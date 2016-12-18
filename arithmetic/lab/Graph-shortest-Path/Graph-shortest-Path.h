/*
 * Function: 单源点最短路径
 * FileName: Graph-shortest-Path.h
 * CreateTime: 20161215 16:00
 * UpdateTime: 20161215
 * Author: iyuge2
 */
#include<iostream>
#include<limits.h>

using namespace std;

typedef struct Path _Path;
typedef struct Path* _pPath;

struct Path{
    unsigned int dist;//到源点的距离
    unsigned int prePoint;//上一个顶点
};

void DIST(int);//求最短路径
void Print(int);//打印结果
