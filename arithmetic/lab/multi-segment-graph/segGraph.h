/*
 * filename: segGraph.h
 * function: 计算多段图的最短路径--邻接矩阵存放多段图
 * author: iyuge2
 * creat-time: 20161218 23:40
 * update-time: 20141219 01:07
 */
#include<iostream>
#include<climits>

using namespace std;

typedef struct SGraph _SGraph;
typedef struct SGraph* _pSGraph;

struct SGraph{
    int node;//指向的结点号
    int value;//指向的结点的值
    _pSGraph next;//下一个节点
};
void FGRAPH(int*,int&,const int);//计算源结点到汇点的最短路径--向前处理算法
void Print(const int*,const int);//打印最短路径
