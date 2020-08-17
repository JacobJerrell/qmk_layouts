QMK_USER="bocaj"

# You shouldn't need to edit below this line
TEST_FILE="quantum/api.c"
SHOULD_COPY_USER=true
SHOULD_COMPILE=true
if [[ "$1" != "compile" ]]; then
    unset -f SHOULD_COMPILE
else
    shift
fi

# Validate build environment 
if [ ! -d "${QMK_HOME}" ]; then
    echo "Set your QMK_HOME environment variable. RTFM!"
else
    if [[ ! -r "$QMK_HOME/$TEST_FILE" ]]; then
        echo "You need to clone and setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started"
    else
        echo "Firmware Path: ${QMK_HOME}"
    fi
fi

if [[ ! qmk ]]; then
    echo "You need to setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started?id=set-up-qmk"
fi

copy_layout()
{
    KEYBOARD=$1
    if [ ! -d "${QMK_HOME}/layouts/community/$KEYBOARD" ]; then
        echo "Keyboard does not exist at: ${QMK_HOME}/layouts/community/$KEYBOARD"
        return
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
        if [ -f "${QMK_HOME}/users/${QMK_USER}/${QMK_USER}.c" ]; then
            unset -f SHOULD_COPY_USER
            echo "Copied user directory from source"
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
