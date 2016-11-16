.386
data segment use16
	buf db 'Bob',0dh
		db 10-($-buf) dup(0)
		db 85,90,48,0
		db 'iyuge2',0dh
		db 10-($-buf-14) dup(0)
		db 89,98,94,0
		db 'hello',0dh
		db 10-($-buf-28) dup(0)
		db 60,32,43,0
		db 1ah ;set the end flag
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
L1:
	lea dx,buf2
	mov ah,9
	int 21h
	;get the name that user input
	lea dx,buf4
	mov ah,10
	int 21h
	mov ebx,10000000 ;循环一千万次
	mov dl,0ah
	mov ah,2
	int 21h
	;time start
	mov ax,0
	call TIMER
LOOP1:
	mov cx,0
	lea si,buf
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
	mov dx,offset buf
	imul cx,14
	add dx,cx
	mov si,dx
	mov cx,ax
	cmp byte ptr [si],'0'
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
	mov ecx,ebx
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
	mov ebx,ecx
	mov cx,ax
	dec ebx
	cmp ebx,0
	jnz LOOP1
	mov ax,1
	call TIMER   
	;time end
	mov ax,cx
	mov bx,cx
	mov dl,10
	div dl
	mov cx,ax
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

;时间计数器(ms),在屏幕上显示程序的执行时间(ms)
;使用方法:
;	   MOV  AX, 0	;表示开始计时
;	   CALL TIMER
;	   ... ...	;需要计时的程序
;	   MOV  AX, 1	
;	   CALL TIMER	;终止计时并显示计时结果(ms)
;输出: 改变了AX和状态寄存器
TIMER	PROC
	PUSH  DX
	PUSH  CX
	PUSH  BX
	MOV   BX, AX
	MOV   AH, 2CH
	INT   21H	     ;CH=hour(0-23),CL=minute(0-59),DH=second(0-59),DL=centisecond(0-100)
	MOV   AL, DH
	MOV   AH, 0
	IMUL  AX,AX,1000
	MOV   DH, 0
	IMUL  DX,DX,10
	ADD   AX, DX
	CMP   BX, 0
	JNZ   _T1
	MOV   CS:_TS, AX
_T0:	
	POP   BX
	POP   CX
	POP   DX
	RET
_T1:	SUB   AX, CS:_TS
	JNC   _T2
	ADD   AX, 60000
_T2:	MOV   CX, 0
	MOV   BX, 10
_T3:	MOV   DX, 0
	DIV   BX
	PUSH  DX
	INC   CX
	CMP   AX, 0
	JNZ   _T3
	MOV   BX, 0
_T4:	POP   AX
	ADD   AL, '0'
	MOV   CS:_TMSG[BX], AL
	INC   BX
	LOOP  _T4
	PUSH  DS
	MOV   CS:_TMSG[BX+0], 0AH
	MOV   CS:_TMSG[BX+1], 0DH
	MOV   CS:_TMSG[BX+2], '$'
	LEA   DX, _TS+2
	PUSH  CS
	POP   DS
	MOV   AH, 9
	INT   21H
	POP   DS
	JMP   _T0
_TS	DW    ?
 	DB    'Time elapsed in ms is '
_TMSG	DB    12 DUP(0)
TIMER   ENDP
code ends
	end begin

	
	
	