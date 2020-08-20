source qmkws.cfg

############################################
# **WARNING**
# You shouldn't need to edit below this line
############################################
test_file="quantum/api.c"

if [[ "$1" == "compile" ]]; then
    should_compile="true"
    echo "Should be compiling"
    shift
else
    should_compile="false"
fi

# Validate build environment 
if [ -d "${qmk_firmware}" ]; then
    if [[ ! -r "${qmk_firmware}/${test_file}" ]]; then
        echo "Fatal Error: Firmware does not appear to exist at ${qmk_firmware}.
        - Check your configuration by editing the ``qmkws.sh`` file
        - Otherwise, you may need to clone and setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started"
        exit 127 # Possible PATH issue
    else
        echo "Firmware Path: ${qmk_firmware}"
    fi
fi

if [[ ! qmk && should_compile == "true" ]]; then
    echo "Fatal Error: You need to setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started?id=set-up-qmk"
    exit 126 # Cannot invoke required command
fi

if [[ ! ditto ]]; then
    echo "Fatal Error: Command \"ditto\" must be available in \$PATH"
    exit 126 # Cannot invoke required command
fi

should_copy_user="true"

copy_layout()
{
    # copy_layout ${keyboards[$k]}
    if [ ! -d "${qmk_firmware}/keyboards/${keyboards[$1]}" ]; then
        echo "Keyboard does not exist at: ${qmk_firmware}/keyboards/${keyboards[$1]}"
        exit 127 # Possible PATH issue
    fi

    if [[ $1 < 1 ]]; then
        if [ -d "${qmk_firmware}/users/${qmk_user}" ]; then
            echo "Userspace needs to be deleted before ditto is run to prevent orphaned files."
            rm -rf ${qmk_firmware}/users/${qmk_user}
            if [ ! -d "${qmk_firmware}/users/${qmk_user}" ]; then
                echo "Deleted the user folder for overwrite"
            fi
        fi
        mkdir $qmk_firmware/users/$qmk_user
        ditto $qmk_workspace/users/$qmk_user $qmk_firmware/users/$qmk_user
        # If the assumption mentioned in the definition of qmk_user doesn't apply to you, change this:
        if [ -f "${qmk_firmware}/users/${qmk_user}/${qmk_user}.c" ]; then
            should_copy_user="false"
            echo "Copied user directory from source."
        fi
    fi
    echo "------------------------------------"
    echo "- Now Copying Layout: ${layouts[$1]}"
    echo "------------------------------------"
    if [ -f "${qmk_firmware}/layouts/community/${layouts[$1]}/${qmk_user}/keymap.c" ]; then
        echo "Removing existing files at keymap path to prevent orphans."
        rm -rf $qmk_firmware/layouts/community/${layouts[$1]}/$qmk_user
    fi
    mkdir $qmk_firmware/layouts/community/${layouts[$1]}/$qmk_user
    ditto $qmk_workspace/layouts/community/${layouts[$1]}/$qmk_user $qmk_firmware/layouts/community/${layouts[$1]}/$qmk_user
    if [ -f "${qmk_firmware}/layouts/community/${layouts[$1]}/${qmk_user}/keymap.c" ]; then
        echo "Successfully copied keymap from source"
    fi
}

ws_compile()
{
    echo "-------------------------"
    echo "- Compiling ${1}..."
    echo "-------------------------"
    qmk compile -kb $1 -km $2
}
if [ -z "$1" ]; then
    for k in ${!keyboards[@]}; do
        copy_layout $k
        if [[ $should_compile == "true" ]]; then
            ws_compile ${keyboards[$k]} ${qmk_user}
        fi
    done
else
    echo "Found parameter $1"
    for k in ${!keyboards[@]}; do
        echo "Checking ${keyboards[$k]}"
        if [[ -z $1 ]]; then
            continue
        elif [[ "${keyboards[$k]}" == *"$1"* ]]; then
            echo "Found match for $1 in: ${keyboards[$k]}"
            copy_layout $k
            if [[ $should_compile == "true" ]]; then
                ws_compile ${keyboards[$k]} ${qmk_user}
            fi
            shift
        fi
    done
fi
