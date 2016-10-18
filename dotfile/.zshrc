# Path to your oh-my-zsh configuration.
ZSH=$HOME/.oh-my-zsh

# Set name of the theme to load.
# Look in ~/.oh-my-zsh/themes/
# Optionally, if you set this to "random", it'll load a random theme each
# time that oh-my-zsh is loaded.
ZSH_THEME="gianu"

# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

# Set to this to use case-sensitive completion
# CASE_SENSITIVE="true"

# Uncomment this to disable bi-weekly auto-update checks
# DISABLE_AUTO_UPDATE="true"

# Uncomment to change how often before auto-updates occur? (in days)
export UPDATE_ZSH_DAYS=13

# Uncomment following line if you want to disable colors in ls
# DISABLE_LS_COLORS="true"

# Uncomment following line if you want to disable autosetting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment following line if you want to disable command autocorrection
# DISABLE_CORRECTION="true"

# Uncomment following line if you want red dots to be displayed while waiting for completion
# COMPLETION_WAITING_DOTS="true"

# Uncomment following line if you want to disable marking untracked files under
# VCS as dirty. This makes repository status check for large repositories much,
# much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Which plugins would you like to load? (plugins can be found in ~/.oh-my-zsh/plugins/*)
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# plugins=(git autojump zsh-syntax-highlighting brew osx extract z h take history)
plugins=(git autojump brew osx extract z h take history)
# plugins=(git autojump brew osx extract z)

source $ZSH/oh-my-zsh.sh

# Customize to your needs...
export PATH=~/bin:/usr/local/bin:/usr/bin:/sbin:/opt/local/bin:/opt/local/sbin:/Users/baotiao/.rvm/bin:/usr/local/sbin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/X11/bin:$PATH

if [[ "$USER" == "baotiao" ]];
then
    alias ls='ls -GF'
else    
    export LS_COLORS="di=34:ln=36:so=35;40:pi=1;35;40:ex=33:bd=32;40:cd=33;40:su=31:sg=1;31:tw=1;35:ow=35:or=31;40:"
fi
alias vi='vim'
alias which='alias | /usr/bin/which --tty-only --read-alias --show-dot --show-tilde'
alias ll='ls -GFl'
alias la='ls -GFa'
alias pa='ps aux'
alias cur='echo chenzongzhi@`hostname`:`pwd`/'
alias ccore='rm -rf ./core.*'
alias grep='grep --color'

alias ep='export LC_ALL="en_US.UTF-8"'
# alias global then you can pg process name
alias -g pg='ps aux | grep '

# open end with cc by vim
alias -s cc=vim
alias -s c=vim
alias -s h=vim
alias -s erl=vim
alias -s php=vim
alias -s py=python
alias -s sh=sh

hash -d bada=~/dev/bada/

# color for Macos
export CLICOLOR=1
export LSCOLORS=gxfxbEaEBxxEhEhBaDaCaD

# bindkey with vim
# bindkey -v

export TERM=xterm-256color
# Make the language type en_US.UTF-8
export LC_ALL="en_US.UTF-8";

export GOPATH=$HOME/go


# Even better: use the silver searcher (brew install the_silver_searcher)
alias f="ag -g"
alias r=ag

alias typora="open -a typora"


man() {
  env \
    LESS_TERMCAP_mb=$(printf "\e[1;31m") \
    LESS_TERMCAP_md=$(printf "\e[1;31m") \
    LESS_TERMCAP_me=$(printf "\e[0m") \
    LESS_TERMCAP_se=$(printf "\e[0m") \
    LESS_TERMCAP_so=$(printf "\e[1;44;33m") \
    LESS_TERMCAP_ue=$(printf "\e[0m") \
    LESS_TERMCAP_us=$(printf "\e[1;32m") \
    man "$@"
}
