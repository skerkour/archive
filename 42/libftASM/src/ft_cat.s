; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/11 15:53:16 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/11 15:53:16 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_cat
section .text

_ft_cat:
	push rbp
	mov rbp, rsp
	sub rsp, 0x408			; fd, buffer
	mov [rsp], rdi

.loop:
	mov rdi, [rsp]
	lea rsi, [rel buffer]
	mov rdx, 0x400
	mov rax, 0x2000003
	syscall
	jc .en
	test rax, rax
	je .end

	mov rdi, 1
	lea rsi, [rel buffer]
	mov rdx, rax
	mov rax, 0x2000004
	syscall
	jmp .loop

.en:
	mov rdi, 1
	lea rsi, [rel buffer]
	mov rdx, rax
	mov rax, 0x2000004
	syscall

.end:
	mov rsp, rbp
	pop rbp
	ret

section .bss
buffer REST 0x400
