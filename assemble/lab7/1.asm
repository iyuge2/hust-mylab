.386
CRLF macro
	mov dl,0dh 
	mov ah,2 
	int 21h 
	mov dl,0ah 
	mov ah,2 
	int 21h 
endm 
data segment use16
	buf db 'Bob',0dh
		db 10-($-buf) dup(0)
		db 85 xor 'A',90 xor 'A',48 xor 'A',0
		db 'iyuge2',0dh
		db 10-($-buf-14) dup(0)
		db 89,98,94,0
		db 'hello',0dh
		db 10-($-buf-28) dup(0)
		db 60,32,43,0
		db 1ah ;set the end flag
	password db 'password:$'
		db 100 dup(0)
	input db 11
		  db ?
		  db 11 dup(0)
	OK  db '--Welcome--$'
	err db '--error--$'
	PWD db 5,6,7,'QWERTYU' 
	buf2 db 0dh,0ah,'please input name:$'
	buf3 db 0dh,0ah,'input error,please input again:$'
	buf4 db 10
		 db ?
		 db 10 dup(0)
data ends

stack segment use16 stack
	db 200 dup(0)
stack ends

code segment use16
	assume cs:code,ss:stack,ds:data
begin:
	mov ax,data
	mov ds,ax
L:
	lea dx,password
	mov ah,9
	int 21h
	lea dx,input
	mov ah,10
	int 21h 
	mov cl,input+1
    mov ch,PWD+1  	
	cmp ch,cl
	jz CON
LB:
	CRLF 
	lea dx,err
	mov ah,9 
	int 21h 
	jmp exit 
CON:
	mov cl,PWD+1
	xor ch,ch 
	mov bl,1 
	mov bh,40h 
	lea di,input+2
	lea si,PWD+3
LA:
	mov al,[si] 
	cmp al,[di]
	jnz LB
	inc si
	inc di	
	loop LA
	CRLF
	lea dx,OK
	mov ah,9 
	int 21h
L1:
	lea si,buf
	lea dx,buf2
	mov ah,9
	int 21h
	mov cx,0
	;get the name that user input
	lea dx,buf4
	mov ah,10
	int 21h
	lea di,buf4+2
	cmp byte ptr [di],'q'
	jnz L2
	cmp byte ptr [di+1],0dh
	jz exit
L2:
	mov al,[si]
	cmp [di],al
	jnz L3
	cmp byte ptr [di],0dh
	jz put
	inc di
	inc si
	jmp L2
L3:
	inc cx
	mov ax,cx
	mov bx,offset buf
	imul cx,14
	add bx,cx
	mov si,bx
	mov cx,ax
	cmp byte ptr [si],1ah
	jz L4
	lea di,buf4
	add di,2
	jmp L2
L4:
	lea dx,buf3
	mov ah,9
	int 21h
	jmp L1
put:
	imul cx,14
	lea si,buf+10
	add si,cx;find grade of the student
	mov al,[si]
	mov ah,0
	imul ax,2 ;A*2 
	inc si
	mov bl,[si]
	mov bh,0
	add bx,ax;A*2+B
	inc si
	mov al,[si]
	mov ah,0
	mov dl,2
	div dl
	mov ah,0
	add bx,ax ;A*2+B+C/2
	imul bx,2
	mov ax,bx
	mov dl,7
	div dl
	mov ah,0
	mov bx,ax ;(A*2+B+C/2)*3.5
	mov dl,10
	div dl
	mov cx,ax 
	mov dl,0ah
	mov ah,2
	int 21h
	mov dx,cx
	add dl,30h
	mov ah,2
	int 21h
	mov dl,dh
	add dl,30h
	mov ah,2
	int 21h
	mov dl,0ffh
	mov ah,2
	int 21h
	;ABCDF
	cmp bx,90
	jge P1
	cmp bx,80
	jge P2
	cmp bx,70
	jge P3
	cmp bx,60
	jge P4
	mov dl,'F'
	mov ah,2
	int 21h
	jmp L1
P1:
	mov dl,'A'
	mov ah,2
	int 21h
	jmp L1
P2:
	mov dl,'B'
	mov ah,2
	int 21h
	jmp L1
P3:
	mov dl,'C'
	mov ah,2
	int 21h
	jmp L1
P4:
	mov dl,'D'
	mov ah,2
	int 21h
	jmp L1
exit:
	mov ah,4ch
	int 21h
code ends
	end begin

	
	
	