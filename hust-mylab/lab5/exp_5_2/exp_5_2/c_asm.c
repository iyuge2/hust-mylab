#include<stdio.h>

#define NAME_LEN 12
#define N  10

typedef struct STU {
	char name[NAME_LEN];
	int C;//���ĳɼ�
	int M;//��ѧ�ɼ�
	int E;//Ӣ��ɼ�
	int aver;//ƽ���ɼ�
}STUDENT;

extern void CalcAver(STUDENT *, int);
extern int FindName(STUDENT *, int,int*);
char temp[NAME_LEN];

int main()
{
	int i = 0;
	int n = 0, flag = 0, m = 0;
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
	__asm mov ebp,10
	CalcAver(stu, n);
	for (i = 0;i < n;i++) {
		printf("����      ���� ��ѧ Ӣ�� ƽ���ɼ�\n");
		printf("%-10s%-5d%-5d%-5d%-d\n", stu[i].name, stu[i].C, stu[i].M, stu[i].E, stu[i].aver);
	}
	printf("--������Ҫ��ѯ��ѧ������--\n");
	scanf_s("%s", temp, NAME_LEN);
	m = FindName(stu, n,&flag);
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



