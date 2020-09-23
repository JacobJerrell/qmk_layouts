# To Import:
# source ./_utility.sh

# Established Styles:
#
# - Private Function Naming Convention: 
#   _function_name() { ... }

#####################
# Message Functions #
#####################

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
            ;;
        -f|--fatal)
            _send_msg -h " !! Fatal Error !! "
            _send_msg -m "ERROR :: ${message}"
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
