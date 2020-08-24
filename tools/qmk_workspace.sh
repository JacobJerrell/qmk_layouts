#!/bin/bash

source _utility.sh

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
            _send_msg -f "Unknown Argument: $arg"
            shift
            ;;
    esac
done

_debug_msg()
{
    if [[ "$debug" == "true" ]]; then
        _send_msg -d $@
    fi
}

_send_msg -h "QMK Workspace Utility"
_debug_msg "Debug Messages Enabled"
_debug_msg "Passing $# unparsed arguments"
for arg
do
    if [[ ! -z "${arg[i]}" ]]; then
        _debug_msg "Argument #$i: "${arg[i]}""
    fi
done

