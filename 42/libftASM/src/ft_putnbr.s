; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putnbr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/10 22:29:38 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/10 22:29:38 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern _ft_putchar_fd
global _ft_putnbr

section .text
_ft_putnbr:
	cmp edi, 0x80000000
	je .put_min
	push rbp
	mov rbp, rsp
	sub rsp, 0x4
	mov dword[rsp], edi
	cmp rdi, 0x7fffffff
	jle .loc1
	mov rdi, 0x2d
	mov rsi, 1
	call _ft_putchar_fd
	mov eax, dword[rsp]
	mov ebx, eax
	neg eax
	cmovl eax, ebx
	mov dword[rsp], eax

.loc1:
	mov eax, dword[rsp]
	xor edx, edx
	cmp eax, 0xa
	jl .loc2
	mov ebx, 0xa
	div ebx
	mov edi, eax
	call _ft_putnbr

	mov eax, dword[rsp]
	xor edx, edx
	mov ebx, 0xa
	div ebx
	add edx, 0x30
	mov edi, edx
	xor esi, esi
	inc esi
	call _ft_putchar_fd
	jmp .end

.loc2:
	mov edi, dword[rsp]
	add edi, 0x30
	mov esi, 1
	call _ft_putchar_fd

.end:
	mov rsp, rbp
	pop rbp
	ret

.put_min:
	xor rdi, rdi
	inc rdi
	lea rsi, [rel int_min]
	mov rdx, 0xb
	mov rax, 0x2000004
	syscall
	xor rax, rax
	ret

section .data
int_min:
	db "-2147483648"
