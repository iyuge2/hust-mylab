.386
.model flat,c
.code
extern temp:dword
public CalcAver,FindName,dif
text segment 'code'
dif proc
	push ebp
	mov ebp,esp
	mov eax,[ebp+8]
	sub eax,[ebp+12]
	pop ebp
	ret
dif endp

CalcAver proc
	push ebp
	mov ebp,esp
	mov ebx, 0
LA1:
	push ebx
	imul ebx,28
	mov esi,[ebp+8]
	add esi,ebx
	add esi,12
	pop ebx
	mov eax, [esi]
	shl eax, 1 ;A * 2
	mov ecx, [esi+4]
	add ecx,eax ;A * 2 + B
	mov eax, [esi+8]
	shr eax, 1
	add ecx, eax ;A * 2 + B + C / 2
	shl ecx, 1
	mov eax, ecx
	xor edx, edx
	mov cx, 7
	div cx  ;(A * 2 + B + C / 2)*3.5
	mov [esi+12], eax
	inc ebx
	cmp ebx,[ebp+12]
	jnz LA1
	pop ebp
	ret
CalcAver endp

FindName proc
	push ebp
	mov ebp,esp
	mov ebx, 0
LB1:
	push ebx
	imul ebx,28
	mov esi,[ebp+8]
	add esi,ebx
	pop ebx
	lea edi,temp
LB2 :
	mov al,[esi]
	cmp al,[edi]
	jnz LB3
	cmp al, 0
	jz LB4
	inc esi
	inc edi
	jmp LB2
LB3 :
	inc ebx
	cmp ebx,[ebp+12]
	jnz LB1
	mov edi,[ebp+16]
	mov dword ptr [edi], 0
	jmp exit
LB4 :
	mov edi,[ebp+16]
	mov dword ptr [edi], 1
	mov eax,ebx
exit :
	pop ebp
	ret
FindName endp
text ends
	end