# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

alias ls='ls -GF'
alias vi='vim'
alias which='alias | /usr/bin/which --tty-only --read-alias --show-dot --show-tilde'
export PATH="/usr/local/Cellar/:/usr/local/bin:~/bin:/usr/local/sbin:/usr/local/mysql/bin:$PATH"
alias ll='ls -GFl'
alias la='ls -GFa'
alias cur='echo chenzongzhi@`hostname`:`pwd`/'
alias grep='grep --color'
alias bada='cd /usr/local/bada_kv/'

export CLICOLOR=1
export LSCOLORS=ExFxCxDxBxegedabagacad
function parse_git_branch {
    git branch --no-color 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/(\1)/' -e 's/((/(/' -e 's/))/)/'
}
function proml {
    local GREEN="\[\033[0;32m\]"
    local COLOR_END="\033[0m" 
    PS1="[\u@\h:\W$GREEN\$(parse_git_branch)$COLOR_END]\$ "
}
proml

export TERM=xterm-256color
# Make the language type en_US.UTF-8
export LC_ALL="en_US.UTF-8";
