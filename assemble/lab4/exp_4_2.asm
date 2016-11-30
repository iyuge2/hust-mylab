;模块1
;作者：U201414779郭弈航   合作者：U201414775余文梦
;创建日期：2016年4月12日
	NAME WAN2
	EXTRN buf:byte,num:byte,output1:byte,output2:byte,output0:byte 
	PUBLIC SORT,OUTGRA
INT_9B macro A
	lea dx,A
	mov ah,9
	int 21h
endm
.386
data2 segment use16 PARA PUBLIC 'D1'
	sbuf db 200 dup(0)
	sbuf1 db 100 dup(0)
data2 ends

stack segment use16 PARA STACK 'STACK'
	db 200 dup(0)
stack ends

code segment use16 PARA PUBLIC 'CODE'
	assume fs:data2,cs:code,ss:stack

;子程序名:SORT
;功能:对平均成绩进行排序
;入口参数:无
;出口参数:无
;所用寄存器:	al——暂时保存当前最大成绩 ah——暂时保存对应序号
;				bh——外层循环    bl——内层循环
;				ch——临时成绩  cl——临时变量
;				si——源串首地址   di——目标串首地址
SORT proc
	mov ax,data2
	mov fs,ax
	mov bl,0 
	lea di,sbuf
SD:
	lea si,buf
	movzx dx,bl
	imul dx,14
	add si,dx
	cmp byte ptr [si],0
	jz SC
	mov fs:[di],bl ;将一个学生的序号放到前面
	mov al,[si+13]
	mov fs:[di+1],al ;将该生平均成绩紧接后面
	add di,2
SC:
	inc bl 
	cmp bl,100
	jnz SD
;start sorting
	lea di,sbuf1
	lea si,sbuf
	xor ch,ch
	xor al,al
	xor bx,bx
SLOOP:
	mov cl,fs:[si+1]
	cmp al,cl
	jb SE ;al<cl
	jmp J1
SE:
	mov al,cl
	mov ah,fs:[si]
	mov ch,bl
J1:
	add si,2
	inc bl
	cmp bl,num
	jnz SLOOP
	mov fs:[di],ah
	inc di
	lea si,sbuf
	shr cx,8
	shl cx,1
	add si,cx
	mov byte ptr fs:[si+1],0
	lea si,sbuf
	xor al,al
	xor bl,bl
	inc bh
	cmp bh,num
	jnz SLOOP
	ret
SORT endp

;子程序名:OUTGRA
;功能:输出成绩单
;入口参数:无
;出口参数:无
;所用寄存器:	bl——循环变量   si——源串首地址
OUTGRA proc
	lea si,sbuf1
	mov bl,num
OA:
	cmp bl,0
	jz OB
	lea di,buf
	mov bh,fs:[si]
	movzx cx,bh
	imul cx,14
	add di,cx
	INT_9B<output0>
	mov ah,num
	sub ah,bl
	add ah,30h
	mov dl,ah
	mov ah,2 
	int 21h
	INT_9B<output1>
	mov dx,di
	mov ah,9
	int 21h
	INT_9B<output2>
	mov al,[di+13]
	xor ah,ah
	mov dl,10
	div dl
	mov cx,ax
	add cl,30h
	mov dl,cl
	mov ah,2
	int 21h
	add ch,30h
	mov dl,ch
	mov ah,2
	int 21h
	inc si
	dec bl
	jmp OA
OB:
	ret
OUTGRA endp
code ends
	end