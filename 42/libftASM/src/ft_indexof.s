; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_indexof.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/10 22:29:38 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/10 22:29:38 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_indexof
section .text

_ft_indexof:
	push rbp
	mov rbp, rsp
	test rdi, rdi
	je .bad
	mov r8, rdi			; start

.loop:
	cmp byte[rdi], sil
	je .good
	cmp byte[rdi], 0
	je .bad
	inc rdi
	jmp .loop

.good:
	sub rdi, r8
	mov rax, rdi
	jmp .end

.bad:
	xor rax, rax
	not rax

.end:
	mov rsp, rbp
	pop rbp
	ret
