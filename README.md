# Bocaj QMK Layout Workspace

This repo is a workspace that simplifies navigating my userspace and layouts from [qmk_firmware](https://docs.qmk.fm/), it also has the advantage of being tracked separate from the main qmk_firmware fork -- making PRs upstream much less cumbersome.

## Compiling

The firmware can be compiled easily via the following function in .zshrc or whatever similar file you choose to use. Being sure to add the correct paths for your setup.

```bash
qmkws () {
    if [ -z "$1" ] || [ "$1" != "compile"]
    then
        echo "Usage:"
        echo "    - `qmkws compile` will copy the userspace and both layouts to qmk_firmware and then compile both"
        echo "    - `qmkws compile planck` copies the userspace and the planck layout to qmk_firmware and then compiles the planck/ez layout"
        echo "    - `qmkws compile ergodox` copies the userspace and the ergodox layout to qmk_firmware and then compiles the ergodox_ez layout"
        return
    fi

    echo "Copying workspace files to firmware directory..."
    ditto -V ~/qmk_layouts/users/bocaj ~/qmk_firmware/users/bocaj
    if [ -z "$2" ]
    then
        echo "No parameters received. Copying and compiling both layouts..."
        ditto -V ~/qmk_layouts/layouts/community/ortho_4x12/bocaj ~/qmk_firmware/layouts/community/ortho_4x12/bocaj
        qmk compile -kb planck/ez
        ditto -V ~/qmk_layouts/layouts/community/ergodox/bocaj ~/qmk_firmware/layouts/community/ergodox/bocaj
        qmk compile -kb ergodox_ez
    elif [[ "$2" == *"planck"* ]]
    then
        echo "Copying and compiling Planck layout..."
        ditto -V ~/qmk_layouts/layouts/community/ortho_4x12/bocaj ~/qmk_firmware/layouts/community/ortho_4x12/bocaj
        qmk compile -kb planck/ez
    elif [[ "$2" == *"ergodox"* ]]
    then
        echo "Copying and compiling Ergodox layout..."
        ditto -V ~/qmk_layouts/layouts/community/ergodox/bocaj ~/qmk_firmware/layouts/community/ergodox/bocaj
        qmk compile -kb ergodox_ez
    fi
    return
}
```

## Further iTerm/ZSH Helpers

This is only here because I didn't have a better place to put it at the time of finding the tip

- Ctrl + U – delete from the cursor to the start of the line
- Ctrl + K – delete from the cursor to the end of the line
- Ctrl + W – delete from the cursor to the start of the preceding word
- Alt + D – delete from the cursor to the end of the next word
- Ctrl + L – clear the terminal
