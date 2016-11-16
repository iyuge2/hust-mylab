;模块1
;作者：U201414775余文梦   合作者：U201414779郭弈航
;创建日期：2016年4月12日
	NAME WAN1
	EXTRN SORT:NEAR,OUTGRA:NEAR
	PUBLIC buf,num,output0,output1,output2
.386
INT_9 macro A
	lea dx,A
	mov ah,9
	int 21h
endm

INT_10 macro A
	lea dx,A 
	mov ah,10 
	int 21h 
endm 

CLEAR macro  ;清屏
	mov ax,03h
	int 10h
endm

INPUT_KEY macro
	mov ah,1
	int 21h
endm

CR macro 
	mov dl,0dh
	mov ah,2
	int 21h
	mov dl,0ah 
	mov ah,2 
	int 21h 
endm 

data1 segment use16 PARA PUBLIC 'D1'
	num db 0
	buf db 100 dup(14 dup(0))
	COUNT = 100
	buf0 db 3
		 db 0
		 db 3 dup(0)
	buf2 db 10
		 db 0
		 db 10 dup(0)
	buf3 db 4
		 db 0
		 db 4 dup(0)
	menu0 db 0dh,0ah,'----WELCOME TO MY WORLD----'
		  db 0dh,0ah,'1>Input Stu`s Name And Grades'
		  db 0dh,0ah,'2>Calculate Average of Grades'
		  db 0dh,0ah,'3>Sorting'
		  db 0dh,0ah,'4>Output the List of Grades'
		  db 0dh,0ah,'5>Exit'
		  db 0dh,0ah,'----------------------------$'
	op	  db 0dh,0ah,'please input your option:$'
	op1   db 0dh,0ah,'>>Input Stu`s Name And Grades>>$'
	input1 db 0dh,0ah,'please input stu`s name:$'
	input2 db 0dh,0ah,'input the position of student:$'
	input3 db 0dh,0ah,'--input the grade--$'
	input_C	db 0dh,0ah,'<<Chinese:$'
	input_M  db 0dh,0ah,'<<Math:$'
	input_E  db 0dh,0ah,'<<English:$'
	goon  db 0dh,0ah,'continue input?<y/n>$'
	input_D  db 0dh,0ah,'Done!$'
	Err  db 0dh,0ah,'--input error--$'
	output0 db 0dh,0ah,'NO.$'
	output1 db 0dh,0ah,'name:$'
	output2 db 0dh,0ah,'Average grade is $'
data1 ends

stack segment use16 PARA STACK 'STACK'
	db 200 dup(0)
stack ends

code segment use16 PARA PUBLIC 'CODE'
	assume ds:data1,es:data1,cs:code,ss:stack
start:
	mov ax,data1
	mov ds,ax
	mov es,ax
M0:
	CLEAR
	INT_9<menu0>
	INT_9<op>
	INPUT_KEY
	cmp al,'1'
	jz M1
	cmp al,'2'
	jz M2
	cmp al,'3'
	jz M3
	cmp al,'4'
	jz M4
	cmp al,'5'
	jz E
	INT_9<Err>
	INPUT_KEY
	jmp M0
M1:
	INPUT_KEY
	call I_NAME
	INT_9<input_D>
	INPUT_KEY
	jmp M0
M2:
	INPUT_KEY
	call C_AVER
	INT_9<input_D>
	INPUT_KEY
	jmp M0
M3:
	call SORT
	INPUT_KEY
	INT_9<input_D>
	INPUT_KEY
	jmp M0
M4:
	call OUTGRA
	INPUT_KEY
	INT_9<input_D>
	INPUT_KEY
	jmp M0
E:
	INPUT_KEY
	CLEAR
	mov ah,4ch
	int 21h
;子程序名:I_NAME
;功能:录入学生姓名和各科成绩
;入口参数:无
;出口参数:无
;所用寄存器:bx——存放需要记录第几个学生，后面临时保存该生的首地址
;			cx——用于充当成绩输入时的循环计数
;			ax——保存成绩的临时变量
;			si——输入学生名字的首地址
;			di——目标学生的首地址
I_NAME proc
	CLEAR
	INT_9<op1>
ReI:
	INT_9<input2>
	INT_10<buf0>
	lea si,buf0+2
	mov ah,buf0+1
	cmp ah,2
	jz IA
	mov al,[si]
	sub al,30h
	mov bl,al
	jmp IB
IA:
	mov al,[si]
	sub al,30h
	movzx ax,al
	imul ax,10
	mov dl,[si+1]
	sub dl,30h
	movzx dx,dl
	add ax,dx
	mov bl,al
IB:
	dec bl
	xor bh,bh
	INT_9<input1>
	INT_10<buf2>
	;将命令送到内存区
	mov cl,buf2+1
	xor ch,ch
	CLD  ;将DF清0
	lea si,buf2+2
	lea di,buf
	imul bx,14
	add di,bx
	mov bx,di ;将该生首地址临时保存在bx中
	rep movsb
	mov byte ptr[di],'$' ;名字后面加一个结尾标志符
	mov di,bx
	add di,10 ;di指向该生成绩区的首地址
	;
	INT_9<input3>
	;开始输入成绩
	mov cx,0
LOOPA:
	cmp cx,0
	jnz X1
	INT_9<input_C>
	jmp X0
X1:
	cmp cx,1
	jnz X2
	INT_9<input_M>
	jmp X0
X2:
	INT_9<input_E>
X0:
	INT_10<buf3>
	mov bh,buf3+1 ;输入成绩的位数
	lea si,buf3+2
	cmp bh,3		
	jz G3
	cmp bh,2
	jz G2
	cmp bh,1
	jz G1
	INT_9<Err>
	INPUT_KEY
	jmp con
LOOPB:
	inc cx
	cmp cx,3
	jz con
	jmp LOOPA
G3:
	mov al,[si]
	sub al,30h
	movzx ax,al
	imul ax,100
	mov dl,[si+1]
	sub dl,30h
	movzx dx,dl
	imul dx,10
	add ax,dx
	mov dl,[si+2]
	sub dl,30h
	movzx dx,dl
	add ax,dx
	mov bx,cx
	mov [di+bx],al
	jmp LOOPB
G2:
	mov al,[si]
	sub al,30h
	movzx ax,al
	imul ax,10
	mov dl,[si+1]
	sub dl,30h
	movzx dx,dl
	add ax,dx
	mov bx,cx
	mov [di+bx],al
	jmp LOOPB
G1:
	mov al,[si]
	sub al,30h
	mov bx,cx
	mov [di+bx],al
	jmp LOOPB
con:
	inc num
	INT_9<goon>
	CR
	INPUT_KEY
	mov bl,al
	INPUT_KEY
	cmp bl,'y'
	jz ReI
	cmp bl,'Y'
	jz ReI
return:
	ret
I_NAME endp	
;子程序名:C_AVER
;功能:计算平均分
;入口参数:无
;出口参数:无
;所用寄存器: CX——用于保存当前计算的学生序号
;			 DI——用于保存当前学生的首地址
; 			 AX,BX——用于计算平均成绩
C_AVER proc
	mov cx,0
CA:
	lea di,buf
	mov bx,cx
	imul bx,14
	add di,bx
	cmp byte ptr[di],0
	jz CN
	add di,10
	mov al,[di]
	xor ah,ah
	shl ax,1 ;A*2
	mov bl,[di+1]
	xor bh,bh
	add bx,ax ;A*2+B
	mov al,[di+2]
	xor ah,ah
	shr ax,1
	add bx,ax ;A*2+B+C/2
	shl bx,1
	mov ax,bx
	mov dl,7
	div dl  ;(A*2+B+C/2)*3.5->AL
	mov [di+3],al ;将计算得到的平均成绩放到内存中
CN:
	inc cx
	cmp cx,COUNT
	jnz CA
	ret
C_AVER endp

code ends
	end start