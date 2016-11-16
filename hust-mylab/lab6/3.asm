.386
data segment use16
	err db 'input error$'
data ends

stack segment use16 stack
	db 200 dup(0)
stack ends

code segment use16
	assume ds:data,cs:code,ss:stack
START:
	mov ax,data
	mov ds,ax
L:
	mov dl,0ah
	mov ah,2
	int 21h
	mov ah,1
	int 21h
	cmp al,'q'
	jz EXIT
	cmp al,'0'
	jb E
	cmp al,'9'
	ja E
	sub al,30h
	out 70h,al
	jmp $+2
	in al,71h
	mov bl,al
	mov dl,0dh
	mov ah,2
	int 21h
	mov bh,bl
	shr bl,4
	cmp bl,9
	ja OUT_C1
	add bl,30h
	mov dl,bl
	mov ah,2
	int 21h
	jmp OUT_H
OUT_C1:
	sub bl,10
	add bl,'A'
	mov dl,bl
	mov ah,2
	int 21h
OUT_H:
	and bh,0Fh
	cmp bh,9
	ja OUT_C2
	add bh,30h
	mov dl,bh
	mov ah,2
	int 21h
	jmp L
OUT_C2:
	sub bh,10
	add bh,'A'
	mov dl,bh
	mov ah,2
	int 21h
	jmp L
EXIT:
	mov ah,4ch
	int 21h
E:
	lea dx,err
	mov ah,9
	int 21h
	jmp L
code ends
	end START