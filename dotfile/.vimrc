set t_Co=256

"color scheme {{{
set background=dark
colorscheme solarized
" colorscheme badwolf
" }}}
let mapleader = ","
"非兼容模式
set nocp
"底部标尺
set ru
"搜索时高亮显示结果
set hls
"输入搜索命令时，显示目前输入的模式的匹配位置
set is
set ignorecase
"显示行号
set number
"使用:e命令的时候 可选项预览
set wildmenu

set showcmd

"highlight current column
set cursorcolumn
"highlight current line
"set cursorline


"fileencoding setting
"文件默认编码
set enc=utf-8
set fileencodings=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8 
set fileencoding=utf-8
"文件默认格式unix
set ff=unix


"tab setting
"缩进为4个空格宽度
set tabstop=2
"自动缩进使用的空格数
set shiftwidth=2
"编辑插入tab时, 把tab算作的空格数
set softtabstop=2
"缩进使用空格
set expandtab


"自动缩进
set autoindent
"鼠标捕捉
"set mouse=a
"打开语法高亮
syntax enable

"searching
set incsearch           " search as characters are entered
set hlsearch            " highlight matches
"clear highlight 
:nmap <leader>q :nohlsearch<CR>


" set showmatch

set comments=sl:/*,mb:*,ex:*/
set showtabline=2
set laststatus=2

"set backup file dir
set backupdir=~/.vim/backup
"set swap file dir
set directory=~/.vim/swap

"floding setting
set foldenable
set foldlevelstart=10   " open most folds by default
set foldnestmax=10      " 10 nested fold max
nnoremap <space> za

"moving
" move to beginning/end of line
nnoremap B ^
nnoremap E $
" $/^ doesn't do anything
" nnoremap $ <nop>
" nnoremap ^ <nop>

" vim save session
" save session you can save session, then use vim -S to reopen session
nnoremap <leader>s :mksession<CR>


filetype on
:autocmd BufRead,BufNewFile *.php set expandtab tabstop=2 shiftwidth=2 autoindent smartindent keywordprg="help"
:autocmd BufRead,BufNewFile *.py set expandtab tabstop=2 shiftwidth=2 autoindent smartindent
:autocmd BufRead,BufNewFile *.cpp set expandtab tabstop=2 shiftwidth=2 autoindent smartindent
:autocmd BufRead,BufNewFile *.h set expandtab tabstop=2 shiftwidth=2 autoindent smartindent
:autocmd BufRead,BufNewFile *.c set expandtab tabstop=2 shiftwidth=2 autoindent smartindent
:autocmd BufRead,BufNewFile *.cc set expandtab tabstop=2 shiftwidth=2 autoindent smartindent
:autocmd BufRead,BufNewFile *.xml set expandtab tabstop=2 shiftwidth=2 autoindent smartindent foldmethod=indent

nmap <silent> <F7> :!python %<CR>
nmap <silent> <F8> :!make<CR>
nmap <silent> <F9> :!./a.out<CR>
nmap <silent> <F10> :source %<cr>

let Tlist_Ctags_Cmd = '/usr/bin/ctags'
let Tlist_Display_Prototype = 1

"Add vim-v to pbcopy
vmap <silent>y y:call system("pbcopy", getreg("\""))<cr>
noremap <leader>p :set paste<CR>:put  *<CR>:set nopaste<CR>
"nmap <C-v> :call setreg("\"",system("pbpaste"))p
"
"Add code beautiful

nnoremap <leader>ev :tabe $MYVIMRC<cr>
nnoremap <leader>sv :source $MYVIMRC<cr>
" add colon in a word
" nnoremap <leader>" viw<esc>a"<esc>hbi"<esc>lel
inoremap jk <esc>

" add quickfix map
nnoremap <leader>cn :cn<cr>
nnoremap <leader>cp :cp<cr>
nmap <leader>cw :cw 10<cr>
" add new quickfix in new tabe
"set switchbuf+=usetab,newtab

nnoremap <leader>m :!make<cr>
nnoremap <leader>b :!./a.out<cr>
nnoremap <leader>c :!g++ % -std=c++11<cr>
nnoremap <leader>tg :!ctags -R ./*<cr>
nnoremap <leader>n :!make clean<cr>


"set paste
set pastetoggle=<F3>

"set vimtabe
nmap <C-N> :tabnext<CR>
nmap <C-P> :tabprevious<CR>


"make backspace everywhere
set backspace=indent,eol,start

"filename completion on command line 
set wildmode=longest,list

"set splitwindow in the right, and below
set splitbelow
set splitright

nnoremap Q gq
" set textwidth=80

"set force save
map <leader>f :w !sudo tee %<CR>


"""""""""""""""""""""""""""""""""""
"vundle plugin
"""""""""""""""""""""""""""""""""""
set	nocompatible
filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'gmarik/Vundle.vim'

"My Bundle here:

Plugin 'The-NERD-tree'
"NERDTree shortkey
map <F2> :NERDTreeToggle<CR>

Plugin 'a.vim'
"a.vim shortkey
map ,a :A<CR>


Plugin 'majutsushi/tagbar'
nmap <silent> <F4> :TagbarToggle<CR>
let g:tagbar_ctags_bin = '/usr/local/bin/ctags'
let g:tagbar_width = 30

Plugin 'Spaceghost/vim-matchit'
Plugin 'neocomplcache'
Plugin 'DoxygenToolkit.vim'
Plugin 'TagHighlight'
Plugin 'SuperTab'
let g:ctrlp_map = '<c-j>'
Plugin 'rking/ag.vim'
if executable("ag")
    set grepprg=ag\ --nogroup\ --nocolor
    let g:ctrlp_user_command = 'ag %s -l -g ""'
    " let g:ctrlp_user_command = 'ag %s -l --nocolor -g ""'
    let g:ackprg = "ag --nogroup --column"
    let g:ag_highlight=1
    nnoremap <leader>k :Ag! "\b<C-R><C-W>\b"<CR>:cw<CR>
    nnoremap <leader>g :Ag!<SPACE>
endif

"Color Scheme
Plugin 'altercation/vim-colors-solarized'
Plugin 'sjl/badwolf'

Plugin 'jdevera/vim-stl-syntax'

"vim for erlang
"Plugin 'jimenezrick/vimerl'

" vim comment plugin
Plugin 'scrooloose/nerdcommenter'
let NERDSpaceDelims=1
let NERDRemoveExtraSpaces=1

Plugin 'luochen1990/rainbow'
let g:rainbow_active = 1 "0 if you want to enable it later via :RainbowToggle
let g:rainbow_conf = {
\   'guifgs': ['royalblue3', 'darkorange3', 'seagreen3', 'firebrick'],
\   'ctermfgs': ['lightblue', 'lightyellow', 'lightcyan', 'lightmagenta'],
\   'operators': '_,_',
\   'parentheses': ['start=/(/ end=/)/ fold', 'start=/\[/ end=/\]/ fold', 'start=/{/ end=/}/ fold'],
\   'separately': {
\       '*': {},
\       'tex': {
\           'parentheses': ['start=/(/ end=/)/', 'start=/\[/ end=/\]/'],
\       },
\       'lisp': {
\           'guifgs': ['royalblue3', 'darkorange3', 'seagreen3', 'firebrick', 'darkorchid3'],
\       },
\       'vim': {
\           'parentheses': ['start=/(/ end=/)/', 'start=/\[/ end=/\]/', 'start=/{/ end=/}/ fold', 'start=/(/ end=/)/ containedin=vimFuncBody', 'start=/\[/ end=/\]/ containedin=vimFuncBody', 'start=/{/ end=/}/ fold containedin=vimFuncBody'],
\       },
\       'html': {
\           'parentheses': ['start=/\v\<((area|base|br|col|embed|hr|img|input|keygen|link|menuitem|meta|param|source|track|wbr)[ >])@!\z([-_:a-zA-Z0-9]+)(\s+[-_:a-zA-Z0-9]+(\=("[^"]*"|'."'".'[^'."'".']*'."'".'|[^ '."'".'"><=`]*))?)*\>/ end=#</\z1># fold'],
\       },
\       'css': 0,
\   }
\}
" plugin used find define in dash
Plugin 'rizzatti/dash.vim'
:nmap <silent> <leader>d <Plug>DashSearch

" vim-ariline theme
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
" let g:airline_theme='molokai'
let g:airline_theme='solarized'

""""""""""""""""""""""""""""""
" airline
""""""""""""""""""""""""""""""
if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif
let g:airline#extensions#tabline#enabled = 1
let g:airline_powerline_fonts = 1
let g:airline#extensions#branch#enabled     = 1
let g:airline#extensions#syntastic#enabled  = 1
" vim-powerline symbols
let g:airline_left_sep          = '⮀'
let g:airline_left_alt_sep      = '⮁'
let g:airline_right_sep         = '⮂'
let g:airline_right_alt_sep     = '⮃'
let g:airline_symbols.branch     = '⭠'
let g:airline_symbols.readonly   = '⭤'

let g:airline_symbols.linenr = '⭡'

call vundle#end()

filetype plugin indent on

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"ctags setting
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
map <C-\> :tab split<CR>:exec("tag ".expand("<cword>"))<CR>
set tags=./tags;/

map <leader>tg :!ctags -R ./*<CR>


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" cscope setting
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
if has("cscope")
  set cscopequickfix=s-,c-,d-,i-,t-,e-
  set csprg=/usr/bin/cscope
  set csto=1
  set cst
  set nocsverb
  " add any database in current directory
  if filereadable("cscope.out")
      cs add cscope.out
  endif
  set csverb

  nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>  
  nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>  
  nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>  
  nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>  
  nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>  
  nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>  
  nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
  nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>

  nmap <C-@>s :scs find s <C-R>=expand("<cword>")<CR><CR> 
  nmap <C-@>g :scs find g <C-R>=expand("<cword>")<CR><CR> 
  nmap <C-@>c :scs find c <C-R>=expand("<cword>")<CR><CR> 
  nmap <C-@>t :scs find t <C-R>=expand("<cword>")<CR><CR> 
  nmap <C-@>e :scs find e <C-R>=expand("<cword>")<CR><CR> 
  nmap <C-@>f :scs find f <C-R>=expand("<cfile>")<CR><CR> 
  nmap <C-@>i :scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>   
  nmap <C-@>d :scs find d <C-R>=expand("<cword>")<CR><CR> 

  nmap <C-@><C-@>s :vert scs find s <C-R>=expand("<cword>")<CR><CR>
  nmap <C-@><C-@>g :vert scs find g <C-R>=expand("<cword>")<CR><CR>
  nmap <C-@><C-@>c :vert scs find c <C-R>=expand("<cword>")<CR><CR>
  nmap <C-@><C-@>t :vert scs find t <C-R>=expand("<cword>")<CR><CR>
  nmap <C-@><C-@>e :vert scs find e <C-R>=expand("<cword>")<CR><CR>
  nmap <C-@><C-@>f :vert scs find f <C-R>=expand("<cfile>")<CR><CR>   
  nmap <C-@><C-@>i :vert scs find i ^<C-R>=expand("<cfile>")<CR>$<CR> 
  nmap <C-@><C-@>d :vert scs find d <C-R>=expand("<cword>")<CR><CR>
endif
