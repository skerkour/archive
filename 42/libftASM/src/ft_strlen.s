; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/11 15:53:16 by skerkour          #+#    #+#              ;
;    Updated: 2015/03/11 15:53:16 by skerkour         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strlen
section .text

_ft_strlen:
	mov rax, -16
	pxor xmm0, xmm0
.loop:
	add rax, 16
	pcmpistri  xmm0, [rdi + rax], 0x08
	jnz .loop
	add rax, rcx
;	xor rax, rax
;	test rdi, rdi
;	je .end
;	xor rcx, rcx
;	not ecx
;	cld
;	repne scasb
;	not rcx
;	dec rcx
;	mov rax, rcx

.end:
	ret
