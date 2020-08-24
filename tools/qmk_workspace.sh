#!/bin/bash
source _utility.sh
source qmkws.cfg

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
for arg
do
    if [[ ! -z "${arg[i]}" ]]; then
        _debug_msg "Argument : \"${arg[i]}\""
    fi
done

#####################
# Environment Check #
#####################

_qmk_setup_msg()
{
    _send_msg -f "Firmware does not appear to exist at ${qmk_firmware}." 
    _send_msg -m "- Check your configuration by editing the ``qmkws.sh`` file"
    _send_msg -m "- Otherwise, you may need to clone and setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started"
}

_config_check()
{
    test_file="quantum/api.c"
    if [[ ! -r "${qmk_firmware}/${test_file}" ]]; then
        debug_msg fatal "Firmware does not appear to exist at ${qmk_firmware}.
        - Check your configuration by editing the ``qmkws.sh`` file
        - Otherwise, you may need to clone and setup QMK first. Link: https://docs.qmk.fm/#/newbs_getting_started"
    else
        debug_msg info "Firmware Path: ${qmk_firmware}"
    fi
}
