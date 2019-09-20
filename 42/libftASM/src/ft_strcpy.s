; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/10 22:29:38 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/10 22:29:38 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcpy
section .text

_ft_strcpy:
	test rdi, rdi
	je .bad
	test rsi, rsi
	je .bad
	mov r8, rdi

.loop:
	cmp byte[rsi], 0
	je .good
	mov al, byte[rsi]
	mov byte[rdi], al
	inc rdi
	inc rsi
	jmp .loop

.good:
	mov byte[rdi], 0
	mov rax, r8
	ret
.bad:
	mov rax, rdi
	ret
