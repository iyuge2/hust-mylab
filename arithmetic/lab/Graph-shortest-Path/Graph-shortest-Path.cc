/*
 * Function: 单源点最短路径
 * FileName: Graph-shortest-Path.c
 * CreateTime: 20161215 16:00
 * UpdateTime: 20161215
 * Author: iyuge2
 */
#include"Graph-shortest-Path.h"

static const unsigned int G[7][7] =//7*7
{
    {0      ,20     ,50     ,30     ,INT_MAX,INT_MAX,INT_MAX},
    {INT_MAX,0      ,25     ,INT_MAX,INT_MAX,70     ,INT_MAX},
    {INT_MAX,INT_MAX,0      ,40     ,25     ,50     ,INT_MAX},
    {INT_MAX,INT_MAX,INT_MAX,0      ,55     ,INT_MAX,INT_MAX},
    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,0      ,10     ,70     },
    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0      ,50     },
    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0      }
};
//static const unsigned int G[7][7] =//7*7
//{
//    {0      ,20     ,50     ,30     ,INT_MAX,INT_MAX,INT_MAX},
//    {10     ,0      ,25     ,INT_MAX,INT_MAX,70     ,INT_MAX},
//    {20     ,INT_MAX,0      ,40     ,25     ,50     ,INT_MAX},
//    {30     ,INT_MAX,INT_MAX,0      ,55     ,INT_MAX,INT_MAX},
//    {40     ,INT_MAX,INT_MAX,INT_MAX,0      ,10     ,70     },
//    {50     ,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0      ,50     },
//    {60     ,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0      }
//};
static _Path R[7];//存放结果

inline void InitR(int point)//初始化R
{
    for(int i = 0;i < 7;++i){
        R[i].dist = G[point][i];
        R[i].prePoint = point;
    }
}

int main()
{
    cout << "please input the source point v(0<=point<7):" <<endl;
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
    for(int i=point+1; i < 7;++i){//>point
        for(int j = 0;j < 7;++j){
            if(R[j].dist > R[i].dist + G[i][j]){
                R[j].dist = R[i].dist + G[i][j];
                R[j].prePoint = i;
            }
        }
    }
    for(int i=point-1; i >= 0;--i){//<point
        for(int j = 0;j < 7;++j){
            if(R[j].dist > R[i].dist + G[i][j]){
                R[j].dist = R[i].dist + G[i][j];
                R[j].prePoint = i;
            }
        }
    }
}

/*
 * 打印源点到各个点的最短路径
 */
void Print(int point)
{
    cout << "-----------------------------------------------\n" << endl;
    for(int i = 0;i < 7;++i){
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
