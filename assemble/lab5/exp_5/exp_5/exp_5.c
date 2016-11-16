#include<stdio.h>

#define NAME_LEN 10
#define N  10
typedef struct STU {
	char name[NAME_LEN];
	int C;//语文成绩
	int M;//数学成绩
	int E;//英语成绩
	int aver;//平均成绩
}STUDENT;

int main()
{
	int i = 0;
	int n = 0, flag = 0, m = 0;
	char temp[NAME_LEN];
	STUDENT stu[N];
	printf("--学生总数--\n");
	scanf_s("%d", &n);
	for (i = 0;i < n;i++) {
		printf("--请输入第%d个学生的信息--\n", i + 1);
		printf("--姓名--\n");
		scanf_s("%s", stu[i].name, NAME_LEN);
		printf("--语文成绩--\n");
		scanf_s("%d", &stu[i].C);
		printf("--数学成绩--\n");
		scanf_s("%d", &stu[i].M);
		printf("--英语成绩--\n");
		scanf_s("%d", &stu[i].E);
	}
	__asm  //嵌入汇编计算平均成绩
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
		printf("姓名      语文 数学 英语 平均成绩\n");
		printf("%-10s%-5d%-5d%-5d%-d\n", stu[i].name, stu[i].C, stu[i].M, stu[i].E, stu[i].aver);
	}
	printf("--输入需要查询的学生姓名--\n");
	scanf_s("%s", temp, NAME_LEN);
	__asm //嵌入汇编语言搜索名字是否存在，存在flag = 1,不存在，flag = 0
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
		printf("存在该学生！\n");
		printf("姓名      语文 数学 英语 平均成绩\n");
		printf("%-10s%-5d%-5d%-5d%-d\n", stu[m].name, stu[m].C, stu[m].M, stu[m].E, stu[m].aver);
	}
	else {
		printf("不存在该学生！\n");
	}
	return 0;
}