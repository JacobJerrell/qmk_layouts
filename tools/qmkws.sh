source qmkws.cfg

# Default behavior that can be modified via arguments
should_compile="false"
debug="false"
verbose="false"

# Thus far, all used commands support `-v` so a global var is fine
verbose_string=""

# Set and define debug procedures
debug_msg()
{
    if [[ -z "$1" ]]; then
        return 0
    elif [[ "$1" == "msg" ]]; then
        shift
        printf '%s\n' "$1"
    elif [[ "$1" == "fatal" ]]; then
        shift
        printf '###### Fatal Error ######\n%s\n' "$1"
        exit 1
    elif [[ "$1" == "info" ]]; then
        shift
        printf 'INFO ::  %s\n' "$1"
    elif [[ ("$1" == "--debugHeader" && "${debug}" == "true") || "$1" == "header" ]]; then
        shift
        # Inserts: (Character Count of $1) + 4 hash-tag/pound symbols (#)
        printf "\n%${#1}s####\n" |tr " " "#"
        printf '# %s #\n' "$1"
        printf "%${#1}s####\n\n" |tr " " "#"
    elif [[ "${debug}" == "true" ]]; then
        printf 'DEBUG :: %s\n' "$1"
    fi
}

# Option handling
for arg
do
    case "$arg" in
        -d) debug="true"
            shift
            ;;
        -v|--verbose) verbose="true"
            verbose_string="-v"
            shift
            ;;
        -c|--compile) 
            should_compile="true"
            shift
            ;;
        -*) debug_msg fatal "Unknown Argument: $arg"
            ;;
     esac
done

debug_msg "Debug Messages Enabled"
debug_msg "Passing $# unparsed arguments"
if [[ "${debug}" == "true" ]]; then
    for arg
    do
        debug_msg "Argument #$i: "${arg[i]}""
    done
fi


# Validate environment 
test_file="quantum/api.c"
if [ -d "${qmk_firmware}" ]; then
    if [[ ! -r "${qmk_firmware}/${test_file}" ]]; then
        debug_msg fatal "Firmware does not appear to exist at ${qmk_firmware}.
        - Check your configuration by editing the ``qmkws.sh`` file
        - Otherwise, you may need to clone and setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started"
    else
        debug_msg info "Firmware Path: ${qmk_firmware}"
    fi
fi

if [[ ! qmk && should_compile == "true" ]]; then
    debug_msg fatal "You need to setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started?id=set-up-qmk"
fi

if [[ ! ditto ]]; then
    debug_msg fatal "Command \"ditto\" must be available in \$PATH. I believe it exists by default on MacOS"
fi


should_copy_user="true"

copy_layout()
{
    debug_msg --debugHeader "Now Copying Layout: ${layouts[$1]}"
    if [ ! -d "${qmk_firmware}/keyboards/${keyboards[$1]}" ]; then
        debug_msg fatal "Keyboard does not exist at: ${qmk_firmware}/keyboards/${keyboards[$1]}"
    fi

    # if [[ $1 < 1 ]]; then
    if [[ "${should_copy_user}" == "true" ]]; then
        if [ -d "${qmk_firmware}/users/${qmk_user}" ]; then
            debug_msg "Userspace needs to be deleted before ditto is run to prevent orphaned files."
            rm -rf ${verbose_string} ${qmk_firmware}/users/${qmk_user}
            if [ ! -d "${qmk_firmware}/users/${qmk_user}" ]; then
                debug_msg "Deleted the user folder for overwrite"
            fi
        fi
        mkdir $qmk_firmware/users/$qmk_user
        ditto $verbose_string $qmk_workspace/users/$qmk_user $qmk_firmware/users/$qmk_user
        # If the assumption mentioned in the definition of qmk_user doesn't apply to you, change this:
        if [ -f "${qmk_firmware}/users/${qmk_user}/${qmk_user}.c" ]; then
            should_copy_user="false"
            debug_msg info "Copied user directory for \"$qmk_user\" from workspace"
        fi
    fi
    if [ -f "${qmk_firmware}/layouts/community/${layouts[$1]}/${qmk_user}/keymap.c" ]; then
        debug_msg "Removing existing files at layout path to prevent orphans."
        rm -rf $verbose_string $qmk_firmware/layouts/community/${layouts[$1]}/$qmk_user
    fi
    mkdir -pv $qmk_firmware/layouts/community/${layouts[$1]}/$qmk_user
    ditto $verbose_string $qmk_workspace/layouts/community/${layouts[$1]}/$qmk_user $qmk_firmware/layouts/community/${layouts[$1]}/$qmk_user
    if [ -f "${qmk_firmware}/layouts/community/${layouts[$1]}/${qmk_user}/keymap.c" ]; then
        debug_msg info "Successfully copied layout \"${layouts[$1]}/${qmk_user}\" for your ${keyboards[$1]} from workspace."
    fi
}

# Compiles the keymap at the given index of `${keyboards}`
ws_compile()
{
    keyboard=${keyboards[$1]}
    keyboard_path="${qmk_firmware}/keyboards/${keyboard}"

    layout=${layouts[$1]}
    layout_path="${qmk_firmware}/layouts/community/${layout}"

    if [[ ${should_compile} != "true" ]]; then
        return 0
    elif [[ -d "${layout_path}" && -d ${keyboard_path} ]]; then
        debug_msg header "Compiling $1..."
        qmk compile -kb ${keyboard} -km ${qmk_user}
    else
        printf 'Checking Paths...\n'
        printf '[%s] %s' "${ -d ${keyboard_path}}" "${keyboard_path}"
        printf '[%s] %s' "${ -d ${layout_path}}" "${layout_path}"
        debug_msg fatal "Could not locate required directories from path: ${qmk_firmware}"
    fi
}

ws_run()
{
    for k in ${!keyboards[@]}; do
        if [[ -z "$1" || "${keyboards[$k]}" == *"$1"* ]]; then
            copy_layout $k
            # ws_compile ${keyboards[$k]} ${qmk_user} $k
            ws_compile $k
        fi

    done
}

if [[ ! -z "$1" ]]; then
    for arg
    do
        ws_run $arg
    done
else
    ws_run
fi
