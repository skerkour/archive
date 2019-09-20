; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/11 15:53:16 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/11 15:53:16 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isdigit
section .text

_ft_isdigit:
	cmp rdi, 0x30
	jl .bad
	cmp rdi, 0x39
	jg .bad

.good:
	mov rax, 1
	jmp .end
.bad:
	mov rax, 0
.end:
	ret
