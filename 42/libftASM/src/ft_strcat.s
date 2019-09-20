; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/11 15:53:16 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/11 15:53:16 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcat
section .text

_ft_strcat:
	mov rax, rdi
	test rdi, rdi
	je .end
	test rsi, rsi
	je .end
	mov rbx, rdi
	mov rdx, rsi

.loop1:
	cmp byte[rbx], 0
	je .loop2
	inc rbx
	jmp .loop1

.loop2:
	mov cl, byte[rdx]
	mov byte[rbx], cl
	cmp byte[rdx], 0
	je .end
	inc rbx
	inc rdx
	jmp .loop2

.end:
	ret
