.386
data segment use16
	db 200 dup(0)
data ends

stack segment use16 stack
	db 200 dup(0)
stack ends

code segment use16
	assume ds:data,ss:stack,cs:code
begin:
	xor ax,ax
	mov ds,ax
	mov ax,ds:[10H*4]
	mov bx,ds:[10H*4+2]
	mov ah,4ch
	int 21h
code ends
	end begin