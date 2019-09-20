; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_arrlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/10 22:29:38 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/10 22:29:38 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_arrlen
section .text

_ft_arrlen:
	test rdi, rdi
	je .bad
	xor rax, rax

.loop:
	cmp qword[rdi], 0
	je .good
	add rdi, 8
	inc rax
	jmp .loop

.good:
	ret
.bad:
	xor rax, rax
	ret
