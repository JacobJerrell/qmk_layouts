###############
# Configuration
# Update these variables to fit your collection
###############

# The path to your qmk firmware folder
QMK_HOME="/Users/jacob/Projects/qmk/qmk_firmware"

# Note
# This script makes the assumption that your userspace contains a file named <QMK_USER>.c
# Usually your github username but could be anything
QMK_USER="bocaj"

# The path to your keyboard(s) and revision relative to qmk_firmware/keyboards/
# Note: This is the `-kb` parameter in the `qmk compile` command
KEYBOARDS=( 
    "planck/ez" # Keyboard w/ revision path
    "ergodox_ez" # Keyboard w/out revision path
)

# The path where your layout will be stored relative to 
# "QMK_HOME/layouts/" in the same order as the previous array
LAYOUTS=(
    "ortho_4x12"
    "ergodox"
)
############################################
# **WARNING**
# You shouldn't need to edit below this line
############################################
TEST_FILE="quantum/api.c"

if [[ "$1" == "compile" ]]; then
    SHOULD_COMPILE=true
    shift
else
    unset -f SHOULD_COMPILE
fi

# Validate build environment 
if [ -d "${QMK_HOME}" ]; then
    if [[ ! -r "$QMK_HOME/$TEST_FILE" ]]; then
        echo "Fatal Error: Firmware does not appear to exist at ${QMK_HOME}.
        - Check your configuration by editing the ``qmkws.sh`` file
        - Otherwise, you may need to clone and setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started"
        exit 127 # Possible PATH issue
    else
        echo "Firmware Path: ${QMK_HOME}"
    fi
fi

if [[ ! qmk && SHOULD_COMPILE == true ]]; then
    echo "Fatal Error: You need to setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started?id=set-up-qmk"
    exit 126 # Cannot invoke required command
fi

if [[ ! ditto ]]; then
    echo "Fatal Error: Command \"ditto\" must be available in \$PATH"
    exit 126 # Cannot invoke required command
fi

SHOULD_COPY_USER=true

copy_layout()
{
    KEYBOARD=$1
    if [ ! -d "${QMK_HOME}/layouts/community/$KEYBOARD" ]; then
        echo "Keyboard does not exist at: ${QMK_HOME}/layouts/community/$KEYBOARD"
        exit 127 # Possible PATH issue
    elif [[ SHOULD_COPY_USER == true ]]; then
        if [ -d "${QMK_HOME}/users/${QMK_USER}" ]; then
            echo "Userspace needs to be deleted before ditto is run to prevent orphaned files."
            rm -rf ${QMK_HOME}/users/${QMK_USER}
            if [ ! -d "${QMK_HOME}/users/${QMK_USER}" ]; then
                echo "Deleted the user folder for overwrite"
            fi
        fi
        mkdir $QMK_HOME/users/$QMK_USER
        ditto users/$QMK_USER $QMK_HOME/users/$QMK_USER
        # If the assumption mentioned in the definition of QMK_USER doesn't apply to you, change this:
        if [ -f "${QMK_HOME}/users/${QMK_USER}/${QMK_USER}.c" ]; then
            unset -f SHOULD_COPY_USER
            echo "Copied user directory from source."
        fi
    fi

    if [ -f "${QMK_HOME}/layouts/community/${KEYBOARD}/${QMK_USER}/keymap.c" ]; then
        echo "Removing existing files at keymap path to prevent orphans."
        rm -rf $QMK_HOME/layouts/community/$KEYBOARD/$QMK_USER
    fi
    mkdir $QMK_HOME/layouts/community/$KEYBOARD/$QMK_USER
    ditto layouts/community/$KEYBOARD/$QMK_USER $QMK_HOME/layouts/community/$KEYBOARD/$QMK_USER
    if [ -f "${QMK_HOME}/layouts/community/${KEYBOARD}/${QMK_USER}/keymap.c" ]; then
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
    for k in ${!KEYBOARDS[@]}; do
        copy_layout ${KEYBOARDS[$k]}
        if [[ SHOULD_COMPILE == true ]]; then
            qmk compile -kb ${LAYOUTS[$k]}
        fi
    done
fi
if [ -z "$1" ]; then
    copy_layout ergodox
    copy_layout ortho_4x12
    if [[ SHOULD_COMPILE == true ]]; then
        qmk compile -kb ergodox_ez
        qmk compile -kb planck/ez
    fi
elif [[ "$1" == *"ergodox"* ]]; then
    copy_layout ergodox
    if [[ SHOULD_COMPILE == true ]]; then
        qmk compile -kb ergodox_ez
    fi
elif [[ "$1" == *"planck"* ]]; then
    copy_layout ortho_4x12
    if [[ SHOULD_COMPILE == true ]]; then
        qmk compile -kb planck/ez
    fi
fi
