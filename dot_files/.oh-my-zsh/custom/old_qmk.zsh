# This func copies the latest planck and/or ergodox layout from the firmware directory to the workspace directory
# Before doing that, it copies the previous planck and/or ergodox layouts to WORKSPACE/backups/KEYBOARD_DATE.bin(hex)
qmkbak() {
    # This could all be abstracted and improved a touch for easier 3rd party adoption
    date=$(date '+%Y-%m-%dT%H%M%S')

    QMK_FIRMWARE=/Users/j792280/qmk_firmware
    QMK_WORKSPACE=/Users/j792280/qmk_layouts
    PLANCK_UNCHANGED="cmp -s $QMK_WORKSPACE/planck-latest.bin $QMK_FIRMWARE/planck_ez_bocaj.bin"
    ERGODOX_UNCHANGED="cmp -s $QMK_WORKSPACE/ergodox-latest.hex $QMK_FIRMWARE/ergodox_ez_bocaj.hex"

    if [ -z "$1" ]; then
        planck=true
        ergodox=true
    elif [[ "$1" == *"planck"* ]]
    then
        planck=true
        ergodox=false
    elif [[ "$1" == *"ergodox"* ]]
    then
        ergodox=true
        planck=false
    else
        ergodox=false
        planck=false
    fi

    if [ $planck ]
    then
        case $PLANCK_UNCHANGED in
            true)
                echo "Creating backup of last planck build"
                ditto ~/qmk_layouts/plank_latest.bin ~/qmk_layouts/backups/planck_$date.bin
                ditto ~/qmk_firmware/planck_ez_bocaj.bin ~/qmk_layouts/plank_latest.bin
                ;;
            *)
                echo "No changes found in Planck keymap."
                ;;
        esac
    fi

    if [ $ergodox ]
    then
        case $ERGODOX_UNCHANGED in
            false)
                echo "Creating backup of last ergodox build"
                ditto ~/qmk_layouts/ergodox_latest.hex ~/qmk_layouts/backups/ergodox_$date.hex
                ditto ~/qmk_firmware/ergodox_ez_bocaj.hex ~/qmk_layouts/ergodox_latest.hex
                ;;
            *)
                echo "No changes found in Ergodox keymap"
                ;;
        esac
    fi
}

old_qmkws () {
    if [ "$1" != "compile" ]
    then
        echo "Usage:"
        echo "    - \`qmkws compile\` will copy the userspace and both layouts to qmk_firmware and then compile both"
        echo "    - \`qmkws compile planck\` copies the userspace and the planck layout to qmk_firmware and then compiles the planck/ez layout"
        echo "    - \`qmkws compile ergodox\` copies the userspace and the ergodox layout to qmk_firmware and then compiles the ergodox_ez layout"
        return
    else
        echo "Copying workspace files to firmware directory..."
        ditto ~/qmk_layouts/users/bocaj ~/qmk_firmware/users/bocaj
        if [ -z "$2" ]
        then
            echo "No parameters received. Copying and compiling both layouts..."
            ditto ~/qmk_layouts/layouts/community/ortho_4x12/bocaj ~/qmk_firmware/layouts/community/ortho_4x12/bocaj
            qmk compile -kb planck/ez || 
            ditto ~/qmk_layouts/layouts/community/ergodox/bocaj ~/qmk_firmware/layouts/community/ergodox/bocaj
            qmk compile -kb ergodox_ez || return
        elif [[ "$2" == *"planck"* ]]
        then
            echo "Copying and compiling Planck layout..."
            ditto ~/qmk_layouts/layouts/community/ortho_4x12/bocaj ~/qmk_firmware/layouts/community/ortho_4x12/bocaj
            qmk compile -kb planck/ez || return
        elif [[ "$2" == *"ergodox"* ]]
        then
            echo "Copying and compiling Ergodox layout..."
            ditto ~/qmk_layouts/layouts/community/ergodox/bocaj ~/qmk_firmware/layouts/community/ergodox/bocaj
            qmk compile -kb ergodox_ez || return
        fi
        echo "Creating backups..."
        # qmkbak
        return
    fi
}
