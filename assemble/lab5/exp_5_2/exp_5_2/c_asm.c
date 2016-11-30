#include<stdio.h>

#define NAME_LEN 12
#define N  10

typedef struct STU {
	char name[NAME_LEN];
	int C;//语文成绩
	int M;//数学成绩
	int E;//英语成绩
	int aver;//平均成绩
}STUDENT;

extern void CalcAver(STUDENT *, int);
extern int FindName(STUDENT *, int,int*);
char temp[NAME_LEN];

int main()
{
	int i = 0;
	int n = 0, flag = 0, m = 0;
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
	__asm mov ebp,10
	CalcAver(stu, n);
	for (i = 0;i < n;i++) {
		printf("姓名      语文 数学 英语 平均成绩\n");
		printf("%-10s%-5d%-5d%-5d%-d\n", stu[i].name, stu[i].C, stu[i].M, stu[i].E, stu[i].aver);
	}
	printf("--输入需要查询的学生姓名--\n");
	scanf_s("%s", temp, NAME_LEN);
	m = FindName(stu, n,&flag);
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



