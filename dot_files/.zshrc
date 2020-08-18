# See https://github.com/robbyrussell/oh-my-zsh/wiki/Themes
ZSH_THEME="xiong-chiamiov-plus"

# Uncomment the following line to display red dots whilst waiting for completion.
COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in ~/.oh-my-zsh/plugins/*
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)

source $ZSH/oh-my-zsh.sh

# User configuration
export PATH="/usr/local/opt/avr-gcc@7/bin:$PATH"
export PATH="/usr/local/opt/gettext/bin:$PATH"
export PATH="/usr/bin/git:$PATH"
export PATH="~/Library/Android/sdk:$PATH"
export QMK_HOME="/Users/j792280/qmk_firmware"

iterm2_print_user_vars() {
	it2git
}

###-tns-completion-start-###
if [ -f /Users/j792280/.tnsrc ]; then 
    source /Users/j792280/.tnsrc 
fi
###-tns-completion-end-###
