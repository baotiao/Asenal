" 去除行尾空字符
:%s/\(\S\)\s\+$/\1/g
" 去掉空行
:%s/^\_s\+$//g
" 规范if, foreach, for等格式
:%s/^\(\s*\)\(if\|foreach\|for\|while\|switch\)\s*(\(.*\))\_s*{/\1\2 (\3) {/g
" 规范if格式
:%s/^\(\s*\)}\_s*else\_s*{/\1} else {/g
" 规范else if和elseif格式
:%s/^\(\s*\)}\_s*\(else\_s*if\)\s*(\(.*\))\_s*{/\1} \2 (\3) {/g
" 将类函数声明的大括号和声明放在同一列
:%s/^\(\s*\)\(class\)\(.*\)\_s*{\n*\r*/\1\2\3\1{\r/g
" 将{ 提到上面一行
:%s/\(.*\)\_s{/\1 {/g
" 转换单行注释/* */为//格式
:%s/\(\s*\)\/\*\{1,\}\s*\(.*\)\s*\*\{1,\}\/$/\1\/\/ \2/g
" 去除包含空字符的空行
:%s/^\s\+$//g
" 在相邻函数实现加上换行
:%s/^}\_s\(Status\|int\|void\|bool\)/}\r\r\1/g
" Add blank after comment
:%s/\(.*\)\/\/\([^ ]\)\(.*\)/\1\/\/ \2\3/g
" add one blank in protect/private/public
:%s/^\s*\(public:\|private:\|protect:\)/ \1/g
