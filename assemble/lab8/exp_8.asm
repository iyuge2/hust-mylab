.386
.model flat,stdcall
option casemap : none ;不区分大小写
include windows.inc   ;inc
include user32.inc 
include kernel32.inc 
include gdi32.inc 
include comctl32.inc 
includelib user32.lib   ;lib
includelib kernel32.lib 
includelib gdi32.lib 
includelib comctl32.lib 

szText MACRO Name, Text:VARARG
        LOCAL lbl
          jmp lbl
            Name db Text,0
          lbl:
        ENDM
return MACRO arg
        mov eax, arg
        ret
	ENDM
WinMain proto :dword,:dword,:dword,:dword
WinProc proto :dword,:dword,:dword,:dword
TopXY PROTO   :DWORD,:DWORD
CalcAverage PROTO
SortGra PROTO
List PROTO :DWORD
;-----------------------------------------------
.data
	FLAG  dw 0
	temp  db 0,0
	buf db 3,'Bob',6 dup(0)
		db 85,78,48,0,0
		db 6,'iyuge2',3 dup(0)
		db 89,78,94,0,0
		db 5,'hello',4 dup(0)
		db 60,32,43,0,0
		db 8,'zhangsan',1 dup(0)
		db 48,88,90,0,0
		db 4,'lisi',5 dup(0)
		db 87,76,67,0,0
		db 9,'WenmengYu'
		db 99,98,97,0,0
	COUNT EQU 6	;学生人数
	sbuf db 200 dup(0)
	sbuf1 db 0,1,2,3,4,5,94 dup(0)
	szListName	db "List"
	num1 EQU 4 
	szName	db "--------------------------------------------------"
			db "--------------------------------------------------"
			db "--------------------------------------------------"
	num3 EQU 136
	msg_name     db       'name',0
	msg_chinese  db       'chinese',0
	msg_math     db       'math',0
	msg_english  db       'english',0
	msg_average  db       'average',0
	msg_grade    db       'grade',0
	szDisplayName	db 'Our First Window',0 ;窗口标题
	CommamdLine 	dd 0	;命令行的位置
	hWnd	dd 0	;窗口句柄
	hInstance	dd 0	;实例句柄
	
.code	;代码段开始
start:
	invoke GetModuleHandle,NULL	;获取实例句柄
	mov hInstance,eax
	invoke GetCommandLine	;获得命令行参数
	mov CommamdLine,eax
	invoke WinMain,hInstance,NULL,CommamdLine,SW_SHOWDEFAULT
	;进入窗口主程序函数
	invoke ExitProcess,eax ;退出码为WinMain的返回值
;---------窗口主程序----------------
WinMain proc hInst :dword,
		hPrevInst :dword,
		CmdLine :dword,
		CmdShow :dword
;以下定义局部变量
local	wc	:WNDCLASSEX
local	msg	:MSG 
local	Wwd	:dword 
local	Wht	:dword
local	Wtx	:dword
local	Wty	:dword
local	rectClient	:RECT	;矩形坐标结构变量用于存放主窗口用户区的坐标
;给结构wc中各字段赋值
mov wc.cbSize,sizeof WNDCLASSEX
mov wc.style,CS_VREDRAW or CS_HREDRAW or CS_DBLCLKS\
	or CS_BYTEALIGNCLIENT or CS_BYTEALIGNWINDOW ;设置窗口风格
mov wc.lpfnWndProc,offset WndProc
mov wc.cbClsExtra,NULL
mov wc.cbWndExtra,NULL
push hInst
pop wc.hInstance
mov wc.hbrBackground,COLOR_WINDOW+1
mov wc.lpszMenuName,NULL
mov wc.lpszClassName,offset szClassName
invoke LoadIcon,hInst,500
mov wc.hIcon,eax
invoke LoadCursor,NULL,IDC_ARROW	;装入一种系统预定义光标
mov wc.hCursor,eax
mov wc.hIconSm,0
;
invoke RegisterClassEx,addr wc 
mov Wwd,600 ;窗口宽度
mov Wht,400 ;窗口高度
invoke GetSystemMetrics,SM_CXSCREEN
invoke TopXY,Wwd,eax
mov Wtx, eax ;窗口左上角X坐标
invoke GetSystemMetrics,SM_CYSCREEN
invoke TopXY,Wht,eax
mov Wty, eax ;窗口左上角Y坐标

szText szClassName,"Template_Class"

invoke CreateWindowEx,WS_EX_LEFT,
                    ADDR szClassName,
                    ADDR szDisplayName,
                    WS_OVERLAPPEDWINDOW,
                    Wtx,Wty,Wwd,Wht,
                    NULL,NULL,
                    hInst,NULL
mov hWnd,eax	;保存窗口句柄
invoke LoadMenu,hInst,600
invoke SetMenu,hWnd,eax

invoke ShowWindow,hWnd,SW_SHOWNORMAL
invoke UpdateWindow,hWnd

;
StartLoop:
	invoke GetMessage,addr msg,NULL,0,0	;获取信息
	cmp eax,0	;是退出信息吗？
	je	ExitLoop
	invoke TranslateMessage,addr msg 
	invoke DispatchMessage,addr msg 
	jmp StartLoop
ExitLoop:	
	return msg.wParam	;设置返回码
WinMain Endp
;---------------窗口消息处理程序---------------------------
WndProc proc hWin   :DWORD,
             uMsg   :DWORD,
             wParam :DWORD,
             lParam :DWORD

        LOCAL hDC  :DWORD
        LOCAL Ps   :PAINTSTRUCT

szText TheText,"Please Confirm Exit"
    .if uMsg == WM_COMMAND
    ;======== menu commands ========
        .if wParam == 1000
			invoke SendMessage,hWin,WM_SYSCOMMAND,SC_CLOSE,NULL
		.elseif wParam == 1100
			invoke CalcAverage
			return 0
		.elseif wParam == 1200
			cmp FLAG,1
			jz LM
			szText TheMsg2,"Please calc the average first!"
			invoke MessageBox,hWin,ADDR TheMsg2,ADDR szDisplayName,MB_OK
LM:
			invoke SortGra
			return 0
		.elseif wParam == 1300
			invoke List,hWin
			return 0
        .elseif wParam == 1900
            szText TheMsg,"I am CS1408 iyuge2!"
			invoke MessageBox,hWin,ADDR TheMsg,ADDR szDisplayName,MB_OK
        .endif
    ;====== end menu commands =====
	.elseif uMsg == WM_KEYDOWN
		cmp wParam,VK_F1
		jnz LM2
        invoke SendMessage,hWin,WM_SYSCOMMAND,SC_CLOSE,NULL
    .elseif uMsg == WM_CLOSE
        invoke MessageBox,hWin,ADDR TheText,ADDR szDisplayName,MB_YESNO
          .if eax == IDNO
            return 0
          .endif
    .elseif uMsg == WM_DESTROY
        invoke PostQuitMessage,NULL
		return 0
		.endif
	invoke DefWindowProc,hWin,uMsg,wParam,lParam
LM2:
	ret
WndProc endp

TopXY proc wDim:DWORD, sDim:DWORD

    shr sDim, 1      ; divide screen dimension by 2
    shr wDim, 1      ; divide window dimension by 2
    mov eax, wDim    ; copy window dimension into eax
    sub sDim, eax    ; sub half win dimension from half screen dimension

   return sDim
TopXY endp

CalcAverage proc
	lea esi,buf
	mov ecx,COUNT
L1:
	add esi,10 
	mov al,[esi]
	mov ah,0
	imul ax,2 ;A*2 
	mov bl,[esi+1]
	mov bh,0
	add bx,ax;A*2+B
	mov al,[esi+2]
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
	mov [esi+3],bl
	cmp bl,90
	jge P1
	cmp bl,80
	jge P2
	cmp bl,70
	jge P3
	cmp bl,60
	jge P4
	mov dl,'F'
	mov [esi+4],dl
	jmp L2
P1:
	mov dl,'A'
	mov [esi+4],dl
	jmp L2
P2:
	mov dl,'B'
	mov [esi+4],dl
	jmp L2
P3:
	mov dl,'C'
	mov [esi+4],dl
	jmp L2
P4:
	mov dl,'D'
	mov [esi+4],dl
L2:
	add esi,5
	dec ecx
	cmp ecx,0 
	jnz L1
	mov bx,1 
	mov FLAG,bx
	ret
CalcAverage endp

SortGra proc
	mov bl,0 
	lea edi,sbuf
	lea esi,buf
S1:
	mov [edi],bl ;将一个学生的序号放到前面
	mov al,[esi+13]
	mov [edi+1],al ;将该生平均成绩紧接后面
	add edi,2
	add esi,15
	inc bl 
	cmp bl,COUNT
	jb S1
;start sorting
	lea edi,sbuf1
	lea esi,sbuf
	xor ch,ch
	xor al,al
	xor bx,bx
SLOOP:
	mov cl,[esi+1]
	cmp al,cl
	jae J1 ;al>=cl
	mov al,cl
	mov ah,[esi]
	mov ch,bl
J1:
	add esi,2
	inc bl
	cmp bl,COUNT
	jb SLOOP
	mov [edi],ah
	inc edi
	lea esi,sbuf
	shr cx,8
	shl cx,1
	add si,cx
	mov byte ptr [esi+1],0
	lea esi,sbuf
	xor al,al
	xor bl,bl
	inc bh
	cmp bh,COUNT
	jb SLOOP
	ret
SortGra endp

List proc hWd	:DWORD
LOCAL	hdc :DWORD
LOCAL	len	:DWORD
LOCAL	ad	:DWORD
LOCAL	Y	:DWORD
LOCAL	X	:DWORD
XX     equ  10
YY     equ  10
XX_GAP equ  100
YY_GAP equ  30
	INVOKE GetDC,hWd
	mov hdc,eax
	INVOKE TextOut,hdc,XX+0*XX_GAP,YY+0*YY_GAP,addr szListName,num1
	invoke TextOut,hdc,XX+0*XX_GAP,YY+1*YY_GAP,offset msg_name,4
    invoke TextOut,hdc,XX+1*XX_GAP,YY+1*YY_GAP,offset msg_chinese,7
    invoke TextOut,hdc,XX+2*XX_GAP,YY+1*YY_GAP,offset msg_math,4
    invoke TextOut,hdc,XX+3*XX_GAP,YY+1*YY_GAP,offset msg_english,7
    invoke TextOut,hdc,XX+4*XX_GAP,YY+1*YY_GAP,offset msg_average,7
    invoke TextOut,hdc,XX+5*XX_GAP,YY+1*YY_GAP,offset msg_grade,5
	invoke TextOut,hdc,XX+0*XX_GAP,YY+2*YY_GAP,addr szName,num3
	mov ch,0
	mov edx,2
LOOPA:
	lea esi,buf
	lea edi,sbuf1
	movzx eax,ch 
	add edi,eax
	movzx eax,byte ptr [edi]
	imul eax,15
	add esi,eax
	movzx eax,byte ptr [esi]
	mov len,eax
	inc esi
	mov ad,esi
	inc edx
	push edx
	imul edx,30
	add edx,10
	mov Y,edx
	pop edx
	push eax
	push ecx 
	push edx
	invoke TextOut,hdc,XX+0*XX_GAP,Y,ad,len
	pop edx 
	pop ecx 
	pop eax
	mov cl,0
	mov ebx,0 
	add esi,9
LOOPB:
	lea edi,temp 
	mov al,[esi]
	xor ah,ah
	push cx
	mov cl,10
	div cl
	pop cx
	add ax,3030h
	mov [edi],al 
	mov [edi+1],ah
	mov ad,edi
	inc ebx
	push ebx
	imul ebx,100
	add ebx,10 
	mov X,ebx
	pop ebx
	push eax
	push ecx 
	push edx
	invoke TextOut,hdc,X,Y,ad,2
	pop edx 
	pop ecx 
	pop eax
	inc esi
	inc cl 
	cmp cl,4
	jb LOOPB
	mov ad,esi
	inc ebx
	push ebx
	imul ebx,100
	add ebx,10 
	mov X,ebx
	pop ebx
	push eax
	push ecx 
	push edx
	invoke TextOut,hdc,X,Y,ad,1
	pop edx 
	pop ecx 
	pop eax
	inc ch
	cmp ch,COUNT
	jb LOOPA
	ret
List endp
end start

	
	