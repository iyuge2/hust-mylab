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
;名字采用原子符与加1字符异或地方式进行加密
;成绩采用乘2的方式进行加密
	buf db 'Cpc',0eh,6 dup(0)
		db 85*2,90*2,48*2,0
		db 'jzvhf3',0eh,3 dup(0)
		db 89*2,98*2,94*2,0
		db 'ifmmp',0eh,4 dup(0)
		db 60*2,32*2,43*2,0
		db 1ah ;set the end flag
	password db 'password:$'
		db 100 dup(0)
	input db 11
		  db ?
		  db 11 dup(0)
	OK  db '--Welcome--$'
	err db '--error--$'
;密码加密方式：采用函数(X-4nH)*(n+1)的方式进行加密
;其中第二个数字才代表需要输入的字符个数，其余的为干扰项
	PWD db 5,6,7    
		db ('L'-40H)*1 
		db ('K'-41H)*2 
		db ('J'-42H)*3 
		db ('H'-43H)*4 
		db ('G'-44H)*5 
		db ('F'-45H)*6
		db ('D'-46H)*7
	buf2 db 0dh,0ah,'please input name:$'
	buf3 db 0dh,0ah,'input error,please input again:$'
	buf4 db 10
		 db ?
		 db 10 dup(0)
	OLD_INT1 dw 0,0 ;1号中断的原中断矢量 
	OLD_INT3 dw 0,0 ;3号中断的原中断矢量
data ends

stack segment use16 stack
	db 200 dup(0)
stack ends

code segment use16
	assume cs:code,ss:stack,ds:data
begin:
	mov ax,data
	mov ds,ax
	xor ax,ax 
	mov es,ax 
	mov ax,es:[1*4]
	mov OLD_INT1,ax
    mov ax,es:[1*4+2]
    mov OLD_INT1+2,ax
    mov ax,es:[3*4]
    mov OLD_INT3,ax
    mov ax,es:[3*4+2]
    mov OLD_INT3+2,ax
    CLI                          ;设置新的中断矢量
    mov  ax,offset NEWINT
    mov  es:[1*4],ax
    mov  es:[1*4+2],cs
    mov  es:[3*4],ax
    mov  es:[3*4+2],cs
    STI
	;判断新的中断矢量表地址是否被更改
	mov bx,offset NEWINT
	mov ax,es:[1*4]
	cmp ax,bx 
	jnz exit
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
	push cx 
	CLI ;计时反跟踪开始 
	mov ah,2ch 
	int 21h 
	push dx
	mov al,[si]
	xor ah,ah 
	div bl
	add al,bh
	inc bh
	inc bl 
	cmp al,[di]
	jnz LB
	mov ah,2ch 
	int 21h
	push dx
	STI
	pop ax  
	pop dx
	pop cx
	cmp ax,dx ;比较两个时间是否相同 
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
	mov al,buf4+1 
	cmp al,0 
	jz L4
	lea di,buf4+2
	cmp byte ptr [di],'q'
	jnz L2
	cmp byte ptr [di+1],0dh
	jz exit
L2:
	mov al,[di]
	inc al 
	cmp [si],al
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
	shr al,1 
	mov ah,0
	imul ax,2 ;A*2 
	inc si
	mov bl,[si]
	shr bl,1 
	mov bh,0
	add bx,ax;A*2+B
	inc si
	mov al,[si]
	shr al,1 
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
	CRLF
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
NEWINT:
	iret
code ends
	end begin

	
	
	