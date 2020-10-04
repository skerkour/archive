if exists('b:did_ftplugin')
    finish
endif
let b:did_ftplugin = 1

let s:save_cpo = &cpo
set cpo&vim

setlocal commentstring=#\ %s

" Add NERDCommenter delimiters

let s:delims = { 'left': '#' }
if exists('g:NERDDelimiterMap')
    if !has_key(g:NERDDelimiterMap, 'sane')
        let g:NERDDelimiterMap.sane = s:delims
    endif
elseif exists('g:NERDCustomDelimiters')
    if !has_key(g:NERDCustomDelimiters, 'sane')
        let g:NERDCustomDelimiters.sane = s:delims
    endif
else
    let g:NERDCustomDelimiters = { 'sane': s:delims }
endif
unlet s:delims

let &cpo = s:save_cpo
unlet s:save_cpo

set shiftwidth=2 tabstop=2
