; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/11 15:53:16 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/11 15:53:16 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern _malloc, _ft_strlen

global _ft_strdup
section .text

_ft_strdup:
	push rbp
	mov rbp, rsp
	test rdi, rdi
	je .bad
	sub rsp, 0x20

	mov qword[rsp], rdi				; str
	mov qword[rsp + 0x8], 0			; ret
	mov qword[rsp + 0x10], 0		; len
	call _ft_strlen

	mov qword[rsp + 0x10], rax
	mov rdi, rax
	inc rdi
	call _malloc
	test rax, rax
	je .bad

	mov qword[rsp + 0x8], rax
	mov rdi, rax
	mov rsi, qword[rsp]
	mov rcx, qword[rsp + 0x10]
	cld
	rep movsb
	inc rdi
	mov byte[rdi], 0
.good:
	jmp .end
.bad:
	mov rax, 0
.end:
	mov rsp, rbp
	pop rbp
	ret
