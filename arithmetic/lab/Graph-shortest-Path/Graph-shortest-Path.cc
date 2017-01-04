/*
 * Function: 单源点最短路径
 * FileName: Graph-shortest-Path.c
 * CreateTime: 20161215 16:00
 * UpdateTime: 20161215
 * Author: iyuge2
 */
#include"Graph-shortest-Path.h"

static const int M = 7;

static const unsigned int G[M][M] =//7*7
{
    {0      ,20     ,50     ,30     ,INT_MAX,INT_MAX,INT_MAX},
    {INT_MAX,0      ,25     ,INT_MAX,INT_MAX,70     ,INT_MAX},
    {INT_MAX,INT_MAX,0      ,40     ,25     ,50     ,INT_MAX},
    {INT_MAX,INT_MAX,INT_MAX,0      ,55     ,INT_MAX,INT_MAX},
    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,0      ,10     ,70     },
    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0      ,50     },
    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0      }
};
static _Path R[M];//存放结果

inline void InitR(int point)//初始化R
{
    for(int i = 0;i < M;++i){
        R[i].dist = G[point][i];
        R[i].prePoint = point;
    }
}

int main()
{
    cout << "please input the source point v(0<=point<" << M << "):" <<endl;
    int point = 0;
    cin >> point;
    InitR(point);//初始化结果数组
    DIST(point);//求最短距离
    Print(point);//打印源点到各个点的最短路径
    return 0;
}

/*
 * 求最短路径
 * point-->源点
 * */
void DIST(int point)
{
    int *S = new int[M];//堆分配内存会自动初始化为0
    unsigned int i = 0,u = 0,min = INT_MAX;
    S[point] = 1;
    for(i = 2;i < M;++i){//确定n-2条边
        for(int j = 0;j < M;++j){//此步选取当前路径最短且未考虑过的节点
            if(!S[j] && min > R[j].dist){
                min = R[j].dist;
                u = j;
            }
        }
        min = INT_MAX;
        S[u] = 1;
        for(int j = 0;j < M;++j){
            if(!S[j] && R[j].dist > R[u].dist + G[u][j]){
                R[j].dist = R[u].dist + G[u][j];
                R[j].prePoint = u;
            }
        }
    }
    delete[] S;
}

/*
 * 打印源点到各个点的最短路径
 */
void Print(int point)
{
    cout << "-----------------------------------------------\n" << endl;
    for(int i = 0;i < M;++i){
        if(R[i].dist == INT_MAX){
            cout << point << " can't get to " << i << endl;
            cout << "-" << endl;
            continue;
        }
        cout << "from " << point << " to " << i << " the shortest way is " << R[i].dist << " long" << endl;
        for(int j = i; 1 ;j = R[j].prePoint){
            if(j == point){
                cout << j << endl;
                break;
            }
            else
                cout << j << "<---";
        }
    }
}
