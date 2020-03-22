if exists("b:current_syntax")
  finish
endif

syn match sanEscape /\\[btnfr"/\\]/ display contained
syn match sanEscape /\\u\x\{4}/ contained
syn match sanEscape /\\U\x\{8}/ contained
hi def link sanEscape SpecialChar

syn match sanLineEscape /\\$/ contained
hi def link sanLineEscape SpecialChar

" Basic strings
syn region sanString oneline start=/"/ skip=/\\\\\|\\"/ end=/"/ contains=sanEscape
" Multi-line basic strings
syn region sanString start=/"""/ end=/"""/ contains=sanEscape,sanLineEscape
" Literal strings
syn region sanString oneline start=/'/ end=/'/
" Multi-line literal strings
syn region sanString start=/'''/ end=/'''/
hi def link sanString String

syn match sanInteger /\<[+-]\=[0-9]\(_\=\d\)*\>/ display
syn match sanInteger /\<[+-]\=\(inf\|nan\)\>/ display
hi def link sanInteger Number

syn match sanFloat /\<[+-]\=[0-9]\(_\=\d\)*\.\d\+\>/ display
syn match sanFloat /\<[+-]\=[0-9]\(_\=\d\)*\(\.[0-9]\(_\=\d\)*\)\=[e][+-]\=[0-9]\(_\=\d\)*\>/ display
hi def link sanFloat Float

syn match sanBoolean /\<\%(true\|false\)\>/ display
hi def link sanBoolean Boolean

syn match sanKey /\v(^|[{,])\s*\zs[[:alnum:]_-]+\ze\s*\=/ display
hi def link sanKey Identifier

syn region sanKeyDq oneline start=/\v(^|[{,])\s*\zs"/ end=/"\ze\s*=/ contains=sanEscape
hi def link sanKeyDq Identifier

syn region sanKeySq oneline start=/\v(^|[{,])\s*\zs'/ end=/'\ze\s*=/
hi def link sanKeySq Identifier

syn region sanMap oneline start=/^\s*\[[^\[]/ end=/\]/ contains=sanKey,sanKeyDq,sanKeySq
hi def link sanMap Identifier

syn keyword sanTodo TODO FIXME XXX BUG contained
hi def link sanTodo Todo

syn match sanComment /#.*/ contains=@Spell,sanTodo
hi def link sanComment Comment

syn sync minlines=500

let b:current_syntax = "sane"
