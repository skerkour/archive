; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/11 15:53:16 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/11 15:53:16 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isalnum
section .text

_ft_isalnum:
	cmp rdi, 0x40
	jle .test1
	cmp rdi, 0x5a
	jle .good

.test1:
	cmp rdi, 0x60
	jle .test2
	cmp rdi, 0x7a
	jle .good

.test2:
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
