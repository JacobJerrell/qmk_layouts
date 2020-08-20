###############
# Configuration
# Update these variables to fit your collection
###############

# The path to your qmk firmware folder
qmk_home="/Users/j792280/qmk_firmware"

# The path to your workspace folder
qmk_workspace="/Users/j792280/qmk_layouts"

# Note
# This script makes the assumption that your userspace contains a file named <qmk_user>.c
# Usually your github username but could be anything
qmk_user="bocaj"

# The path to your keyboard(s) and revision relative to qmk_firmware/keyboards/
# Note: This is the `-kb` parameter in the `qmk compile` command
keyboards=( 
    "planck/ez" # Keyboard w/ revision path
    "ergodox_ez" # Keyboard w/out revision path
)

# The path where your layout will be stored relative to 
# "qmk_home/layouts/" in the same order as the previous array
layouts=(
    "ortho_4x12"
    "ergodox"
)

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
if [ -d "${qmk_home}" ]; then
    if [[ ! -r "${qmk_home}/${test_file}" ]]; then
        echo "Fatal Error: Firmware does not appear to exist at ${qmk_home}.
        - Check your configuration by editing the ``qmkws.sh`` file
        - Otherwise, you may need to clone and setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started"
        exit 127 # Possible PATH issue
    else
        echo "Firmware Path: ${qmk_home}"
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
    if [ ! -d "${qmk_home}/keyboards/${keyboards[$1]}" ]; then
        echo "Keyboard does not exist at: ${qmk_home}/keyboards/${keyboards[$1]}"
        exit 127 # Possible PATH issue
    fi

    if [[ $1 < 1 ]]; then
        if [ -d "${qmk_home}/users/${qmk_user}" ]; then
            echo "Userspace needs to be deleted before ditto is run to prevent orphaned files."
            rm -rf ${qmk_home}/users/${qmk_user}
            if [ ! -d "${qmk_home}/users/${qmk_user}" ]; then
                echo "Deleted the user folder for overwrite"
            fi
        fi
        mkdir $qmk_home/users/$qmk_user
        ditto $qmk_workspace/users/$qmk_user $qmk_home/users/$qmk_user
        # If the assumption mentioned in the definition of qmk_user doesn't apply to you, change this:
        if [ -f "${qmk_home}/users/${qmk_user}/${qmk_user}.c" ]; then
            should_copy_user="false"
            echo "Copied user directory from source."
        fi
    fi
    echo "------------------------------------"
    echo "- Now Copying Layout: ${layouts[$1]}"
    echo "------------------------------------"
    if [ -f "${qmk_home}/layouts/community/${layouts[$1]}/${qmk_user}/keymap.c" ]; then
        echo "Removing existing files at keymap path to prevent orphans."
        rm -rf $qmk_home/layouts/community/${layouts[$1]}/$qmk_user
    fi
    mkdir $qmk_home/layouts/community/${layouts[$1]}/$qmk_user
    ditto $qmk_workspace/layouts/community/${layouts[$1]}/$qmk_user $qmk_home/layouts/community/${layouts[$1]}/$qmk_user
    if [ -f "${qmk_home}/layouts/community/${layouts[$1]}/${qmk_user}/keymap.c" ]; then
        echo "Successfully copied keymap from source"
    fi
}

# for t in ${allThreads[@]}; do
#   ./pipeline --threads $t
# done

# for i in ${!allThreads[@]}; do
#   ./pipeline --threads ${allThreads[$i]}
# done
if [ -z "$1" ]; then
    for k in ${!keyboards[@]}; do
        copy_layout $k
        if [[ $should_compile == "true" ]]; then
            echo "Compiling....."
            qmk compile -kb ${keyboards[$k]} -km ${qmk_user}
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
                qmk compile -kb ${keyboards[$k]} -km ${qmk_user}
            fi
            shift
        fi
    done
fi
