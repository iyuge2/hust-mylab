.386
code segment use16
	assume cs:code,ss:stack
OLD_INT dw ?,?

NEW16H:
	cmp ah,0
	jz CHANGE
	cmp ah,10h
	jz CHANGE
	jmp dword ptr OLD_INT
CHANGE:
	pushf
	call dword ptr OLD_INT
	cmp al,'A'
	jnz CB
	mov al,'B'
	jmp QUIT
CB:
	cmp al,'B'
	jnz QUIT
	mov al,'A'
QUIT:
	IRET
START:
	xor ax,ax
	mov ds,ax
	mov ax,3516h
	int 21h
	mov OLD_INT,bx
	mov OLD_INT+2,es
	CLI    ;关中断
	mov ax,cs
	mov ds,ax
	mov dx,offset NEW16H
	mov ax,2516h
	int 21h
	STI    ;开中断
	mov dx,offset START+15
	shr dx,4
	add dx,10h
	mov al,0
	mov ah,31h
	int 21h
code ends
stack segment use16 stack
	db 200 dup(0)
stack ends
	end START