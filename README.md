# Bocaj QMK Layout Workspace

Simplifies navigating the qmk structure to be more efficient.

## Git Usage & Compiling

The workspace can be used with Git or changes easily applied to the main qmk_firmware directory and runs the `qmk` command with the provided parameters. Furthermore, paths can easily be added to the workspace. This is all made possible with this bash function in .zshrc:

```bash
qmkws () {
    if [ -z "$1" ]
    then
        echo "Invalid usage. RTFM."
        return
    fi

    if [ "$1" = "git" ]
    then
        # drop the firm parameter of `git` since we explicitly call git here"
        shift
        # this allows you to do things like `qmkws git add qmk_firmware/layouts/default`
        /usr/bin/git --git-dir=/Users/username/path/to_workspace/.git --work-tree=/Users/username/path/to/qmk_firmware $*
        return
    elif [ "$1" = "compile" ]
    then
        echo "Copying workspace files to firmware directory..."
        ditto -V ~/path/to_workspace/layouts/community/ergodox/bocaj ~/path/to/qmk_firmware/layouts/community/ergodox/bocaj
        ditto -V ~/path/to_workspace/layouts/community/ortho_4x12/bocaj ~/path/to/qmk_firmware/layouts/community/ortho_4x12/bocaj
        ditto -V ~/path/to_workspace/users/bocaj ~/path/to/qmk_firmware/users/bocaj
        qmk $*
        return
    else
        echo "Error processing command"
        echo "Invalid usage. RTFM."
        return
    fi
}
```

## Further iTerm/ZSH Helpers

Ctrl + U – delete from the cursor to the start of the line.
Ctrl + K – delete from the cursor to the end of the line.
Ctrl + W – delete from the cursor to the start of the preceding word.
Alt + D – delete from the cursor to the end of the next word.
Ctrl + L – clear the terminal.