# Bocaj QMK Layout Workspace

Simplifies navigating the qmk structure to be more efficient.

## Git Usage & Compiling

The workspace can be used with Git or changes easily applied to the main qmk_firmware directory and runs the `qmk` command with the provided parameters. Furthermore, paths can easily be added to the workspace. This is all made possible with this bash function in my `.zshrc` file:

```bash
# This is an adaptation of a guide to managing dotfiles. 
# Many guides for this exist but I used https://medium.com/toutsbrasil/how-to-manage-your-dotfiles-with-git-f7aeed8adf8b
qmkws () {
    # TODO: Make a usage guide for invalid parameters
    if [ -z "$1" ]
    then
        echo "Invalid usage. RTFM."
        return
    fi

    # todo allow params such as "status"/"commit"/"push"/etc... without the "git" parameter
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
        # merge ergodox layout
        ditto -V ~/path/to_workspace/layouts/community/ergodox/bocaj ~/path/to/qmk_firmware/layouts/community/ergodox/bocaj
        # merge planck layout
        ditto -V ~/path/to_workspace/layouts/community/ortho_4x12/bocaj ~/path/to/qmk_firmware/layouts/community/ortho_4x12/bocaj
        # merge user space
        ditto -V ~/path/to_workspace/users/bocaj ~/path/to/qmk_firmware/users/bocaj
        # run `qmk compile param2 param3...`
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

This is only here because I didn't have a better place to put it at the time of finding the tip

- Ctrl + U – delete from the cursor to the start of the line
- Ctrl + K – delete from the cursor to the end of the line
- Ctrl + W – delete from the cursor to the start of the preceding word
- Alt + D – delete from the cursor to the end of the next word
- Ctrl + L – clear the terminal
