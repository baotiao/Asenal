#!/bin/sh


files="
.vimrc
.bashrc
.zshrc
.z
.oh-my-zsh/
.gitignore_global
.gitconfig
.gitignore
.aliases
.ctags
.vim/
"


for file in $files
do
  cp -r ~/$file ./$file
done
