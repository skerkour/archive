; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/11 15:53:16 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/11 15:53:16 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern _ft_strlen

global _ft_puts
section .text

_ft_puts:
	test rdi, rdi
	je .null_input
	push rbp
	mov rbp, rsp
	sub rsp, 0x8

	mov qword[rsp], rdi ; str
	call _ft_strlen

	xor rdi, rdi
	inc rdi
	mov rsi, qword[rsp]
	mov rdx, rax
	mov rax, 0x2000004
	syscall

	xor rdi, rdi
	inc rdi
	lea rsi, [rel endl]
	xor rdx, rdx
	inc rdx
	mov rax, 0x2000004
	syscall

	mov rax, 42
	mov rsp, rbp
	pop rbp
	ret

.null_input:
	xor rdi, rdi
	inc rdi
	lea rsi, [rel .null]
	mov rdx, 0x7
	mov rax, 0x2000004
	syscall
	mov rax, 42
	ret

.null:
	db "(null)", 0xa

section .data
endl:
	db 0xa
