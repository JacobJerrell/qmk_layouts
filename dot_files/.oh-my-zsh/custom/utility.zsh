# Shorten common git commands
alias gcam="git commit -a"
alias gst="git status"
alias mkdir="mkdir -pv"
alias histg="history | grep"

aliases() {
    echo "Aliases sourced from:"
    find ~/.oh-my-zsh/custom \( -name '*.zsh' \) -maxdepth 1
}

# Screwed up Macbook keyboard fix for when I'm not paying attention
it () {
	git $*
}

# Shortcut to Avenel project folders
cdp () {
	cd ~/Projects/Avenel/iOS/$1
}

# While in the root of a Lutra repo, open the workspace file in the default program (XCode)
openp () {
	open Lutra/Lutra.xcworkspace
}

# Makes a folder and any parent necessary parent folders. Then CD's to the new folder
# e.g. The following won't halt if one of the folders in the path doesn't exist mcd oh/my/zsh/is/fun
mcd () {
	mkdir -pv $1
	cd $1
}
