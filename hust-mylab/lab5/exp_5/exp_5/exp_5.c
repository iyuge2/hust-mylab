#include<stdio.h>

#define NAME_LEN 10
#define N  10
typedef struct STU {
	char name[NAME_LEN];
	int C;//���ĳɼ�
	int M;//��ѧ�ɼ�
	int E;//Ӣ��ɼ�
	int aver;//ƽ���ɼ�
}STUDENT;

int main()
{
	int i = 0;
	int n = 0, flag = 0, m = 0;
	char temp[NAME_LEN];
	STUDENT stu[N];
	printf("--ѧ������--\n");
	scanf_s("%d", &n);
	for (i = 0;i < n;i++) {
		printf("--�������%d��ѧ������Ϣ--\n", i + 1);
		printf("--����--\n");
		scanf_s("%s", stu[i].name, NAME_LEN);
		printf("--���ĳɼ�--\n");
		scanf_s("%d", &stu[i].C);
		printf("--��ѧ�ɼ�--\n");
		scanf_s("%d", &stu[i].M);
		printf("--Ӣ��ɼ�--\n");
		scanf_s("%d", &stu[i].E);
	}
	__asm  //Ƕ�������ƽ���ɼ�
	{
		mov ebx, 0
		LA1:
		push ebx
			imul ebx, TYPE STUDENT
			lea esi, stu[ebx]
			pop ebx
			mov eax, [esi]STUDENT.C
			shl eax, 1 //A * 2
			mov ecx, [esi]STUDENT.M
			add ecx, eax //A * 2 + B
			mov eax, [esi]STUDENT.E
			shr eax, 1
			add ecx, eax //A * 2 + B + C / 2
			shl ecx, 1
			mov eax, ecx
			xor edx, edx
			mov cx, 7
			div cx  //(A * 2 + B + C / 2)*3.5
			mov [esi]STUDENT.aver, eax
			inc ebx
			cmp ebx, n
			jnz LA1
	}
	for (i = 0;i < n;i++) {
		printf("����      ���� ��ѧ Ӣ�� ƽ���ɼ�\n");
		printf("%-10s%-5d%-5d%-5d%-d\n", stu[i].name, stu[i].C, stu[i].M, stu[i].E, stu[i].aver);
	}
	printf("--������Ҫ��ѯ��ѧ������--\n");
	scanf_s("%s", temp, NAME_LEN);
	__asm //Ƕ�����������������Ƿ���ڣ�����flag = 1,�����ڣ�flag = 0
	{
		mov ebx, 0
		LB1:
			push ebx
			imul ebx, TYPE STUDENT
			lea esi, stu[ebx].name
			pop ebx
			lea edi, temp
			LB2 :
		mov al, [esi]
			cmp al, [edi]
			jnz LB3
			cmp al, 0
			jz LB4
			inc esi
			inc edi
			jmp LB2
			LB3 :
		inc ebx
			cmp ebx, n
			jnz LB1
			mov flag, 0
			jmp exit
			LB4 :
		mov flag, 1
			mov m, ebx
		exit :
	}
	if (flag == 1) {
		printf("���ڸ�ѧ����\n");
		printf("����      ���� ��ѧ Ӣ�� ƽ���ɼ�\n");
		printf("%-10s%-5d%-5d%-5d%-d\n", stu[m].name, stu[m].C, stu[m].M, stu[m].E, stu[m].aver);
	}
	else {
		printf("�����ڸ�ѧ����\n");
	}
	return 0;
}