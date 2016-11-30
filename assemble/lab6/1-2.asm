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
	mov ax,3510h
	int 21h
	mov ah,4ch
	int 21h
code ends
	end begin