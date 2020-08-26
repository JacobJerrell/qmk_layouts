#!/bin/bash
source _utility.sh
source qmkws.cfg

user_path="users/${qmk_user}"
layouts_path="layouts/community"

ws_user_dir="${qmk_workspace}/${user_path}"
fw_user_dir="${qmk_firmware}/${user_path}"

ws_layouts_dir="${qmk_workspace}/${layouts_path}"
fw_layouts_dir="${qmk_firmware}/${layouts_path}"

test_file="quantum/api.c"
should_copy_user=0

_send_msg -h "QMK Workspace Utility"

_help_msg()
{
    _send_msg -m "Usage: qmkws [-c] [-d] [-v] [keyboard1, keyboard2, ...]"
    _send_msg -m "\t -c\t\t\tCompiles the given keymaps or all of them"
    _send_msg -m "\t -d\t\t\tPrints debug messages"
    _send_msg -m "\t -v\t\t\tPasses the verbose command to system commands where applicable"
    _send_msg -m "\t [keyboard...]\t\t\tPerforms actions for only the provided keyboards"
}

_debug_msg()
{
    if [[ "$debug" == "true" ]]; then
        _send_msg -d "$*"
    fi
}

####################
# Argument Parsing #
####################

should_compile="false"
debug="false"
verbose="false"
verbose_string=""

for arg
do
    case "$arg" in
        -d) 
            debug="true"
            shift
            ;;
        -v|--verbose) 
            verbose="true"
            verbose_string="-v"
            shift
            ;;
        -c|--compile) 
            should_compile="true"
            shift
            ;;
        -*) 
            _help_msg
            return 1
            ;;
    esac
done

_debug_msg "Debug Messages Enabled"
_debug_msg "Passing $# unparsed arguments"
if [[ ${debug} == "true" ]]; then
    for arg
    do
        if [[ ! -z "${arg[i]}" ]]; then
            _debug_msg "Argument : \"${arg[i]}\""
        fi
    done
fi


#####################
# Environment Check #
#####################

_qmk_setup_msg()
{
    _send_msg -f "Firmware does not appear to exist at `${qmk_firmware}`." 
    _send_msg -m "- Check your configuration by editing the `qmkws.cfg` file"
    _send_msg -m "- Otherwise, you may need to clone and setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started"
}

_config_check()
{
    # Check existance of qmk_firmware
    if [[ ! -r "${qmk_firmware}/${test_file}" ]]; then
       _qmk_setup_msg
        return 1
    else
        _send_msg -m "Firmware Path: ${qmk_firmware}"
    fi

    # If should_compile, check that the qmk command is available
    if [[ $should_compile == "true" && ! qmk ]]; then
        _send_msg -f "You need to setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started?id=set-up-qmk"
        return 1
    fi

    if [[ ! -f "${ws_user_dir}/${qmk_user}.c" ]]; then
        _send_msg -f "This script assumes that your user directory contains a file named `${qmk_user}.c`."
        return 1
    fi

    return 0
}

#############
# Workspace #
#############

_clear_dir()
{
    if [[ "${qmk_firmware}"* != "$1" && "${qmk_workspace}"* != "$1" ]]; then
        echo "Unsupported usage of script builtin: `_clear_dir`"
        return 1
    elif [[ ! -d $1 && "$(mkdir -p $1)" ]]; then
        _send_msg -d "Created dir: $1"
        return 0
    elif [ "$(ls -A $1)" ]; then
        if [ "$(rm -rf $1/*)" ]; then
            _send_msg -d "Removed contents of: $1"
            return 0
        else
            _send_msg -f "Could not clear contents of: $1"
            return 1
        fi
    elif [ -d $1 ]; then
        _send_msg -d "Found empty directory. No action needed at: $1"
        return 0
    fi

    _send_msg -f "Unexpected outcome at script builtin: `_clear_dir`"
    _send_msg -m "Argument(s): $@"
    return 1
}

_copy_paths()
{
    source=$1
    destination=$2

    if [ "$(_clear_dir $destination)" ]; then
        _send_msg -d "Attempting to copy \"${source}/\" to \"${destination}\"."
        # Copy full tree, preserve meta data
        # The verbose "-v" argument is not advised for use in scripts
        return $(cp -R -p "${source}/" "${destination}")
    else
        _send_msg -f "Could not copy path `${source}/` to `${destination}`."
        return 1
    fi
}

_copy_layout()
{
    ws_keymap_path="${ws_layouts_dir}/${1}/${qmk_user}"
    fw_keymap_path="${fw_layouts_dir}/${1}/${qmk_user}"
    if [ "$(_copy_paths ${fw_keymap_path})" ]; then
        _send_msg -d "Successfully copied keymap: $1"
        return 0
    else
        _send_msg -f "Failed to copy keymap: $1"
        return 1
    fi
}

_send_msg -d "Attempting to copy the userspace."
if [[ $(_copy_paths ${ws_user_dir} ${fw_user_dir}) ]]; then
    if [ ! -f "${fw_user_dir}/${qmk_user}.c" ]; then
        _send_msg -f "Expected file: `${qmk_user}.c` in userspace."
        return 1
    fi
fi

for k in ${!keyboards[@]}; do
    if [[ -z "$1" ]]; then
        _copy_layout "${layouts[$k]}"
    else
        for arg; do
            if [[ "${keyboards[$k]}" == *"$1"* || "${layouts[$k]}" == *"$1"* ]]; then
                _copy_layout "${layouts[$k]}"
            fi
        done
    fi
done
