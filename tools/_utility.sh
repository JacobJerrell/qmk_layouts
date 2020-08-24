# To Import:
# source ./_utility.sh

# Established Styles:
#
# - Private Function Naming Convention: 
#   _function_name() { ... }

#####################
# Message Functions #
#####################

_help_msg()
{
    printf 'Usage: qmkws [-c] [-d] [-v] [keyboard1, keyboard2, ...]\n'
    printf '\t -c\t\t\tCompiles the given keymaps or all of them\n'
    printf '\t -d\t\t\tPrints debug messages\n'
    printf '\t -v\t\t\tPasses the verbose command to system commands where applicable\n'
    printf '\t [keyboard...]\t\t\tPerforms actions for only the provided keyboards\n'
}

_send_msg()
{
    if [[ "$1" != "-"* ]]; then
        echo "Illegal _send_msg usage"
        return 1
    elif [[ -z "$2" ]]; then
        return 0
    fi

    first_arg=${1}
    message=${2}

    case "${first_arg}" in
         -m|--msg) 
            printf '%s\n' "${message}"
            return 0
            ;;
        -f|--fatal)
            _send_msg -h " !! Fatal Error !! "
            _send_msg -m "ERROR :: ${message}"
            return 1
            ;;
        -h|--header)
            header_length=$(( ${#message} + 4 ))
            printf "%${header_length}s\n" |tr " " "#"
            printf '# %s #\n' "${message}"
            printf "%${header_length}s\n\n" |tr " " "#"
            ;;
        -d|--debug)
            printf 'DEBUG :: %s\n' "${message}"
            ;;
    esac
}
