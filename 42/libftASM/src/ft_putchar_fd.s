; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putchar_fd.s                                    :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/10 22:29:38 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/10 22:29:38 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_putchar_fd
section .text

_ft_putchar_fd:
	push rbp
	mov rbp, rsp
	sub rsp, 0x8
	mov [rsp], rdi
	mov rdi, rsi
	mov rsi, rsp
	xor rdx, rdx
	inc rdx
	mov rax, 0x2000004
	syscall

	mov rsp, rbp
	pop rbp
	ret
