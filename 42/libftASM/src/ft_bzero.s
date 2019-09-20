; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/10 22:29:38 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/10 22:29:38 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_bzero
section .text

_ft_bzero:
	test rdi, rdi
	je .end
	mov rbx, rdi
	mov rcx, rsi

.loop:
	test rcx, rcx
	je .end
	mov byte[rbx], 0
	inc rbx
	dec rcx
	jmp .loop

.end:
	ret
