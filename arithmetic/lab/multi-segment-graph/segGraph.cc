/*
 * filename: segGraph.cc
 * function: 计算多段图的最短路径--邻接矩阵存放多段图
 * author: iyuge2
 * creat-time: 20161218 23:40
 * update-time: 20161219 01:07
 */
#include"segGraph.h"

_pSGraph *head = NULL;//邻接表的首地址

int main()
{
    int k = 0;
    cout << "结点总数: ";
    cin >> k;
    if(k == 0){
        return 0;
    }
    head = new _pSGraph[k];
    for(int i = 1;i <= k;++i){//存储图的相关信息
        int out = 0;
        _pSGraph temp = 0;
        cout <<  i << "的出度: ";
        cin >> out;
        if(out){
            cout << "输入结点" << i << "指向的结点及边的权值.\n";
            for(int j = 0;j < out;++j){
                int node = 0,value = 0;
                cout << "[" << j+1 << "]>>";
                cin >> node >> value;
                if(head[i-1]){
                    temp->next = new _SGraph;
                    temp = temp->next;
                    temp->node = node;
                    temp->value = value;
                    temp->next = NULL;
                }
                else{
                    head[i-1] = new _SGraph;
                    head[i-1]->node = node;
                    head[i-1]->value = value;
                    head[i-1]->next = NULL;
                    temp = head[i-1];
                }
            }
        }
    }
    int *P = new int[k+1];//储存最短路径
    int cost = 0;//储存最短路径成本
    for(int i = 0;i <= k;++i){//初始化P
        P[i] = -1;
    }
    FGRAPH(P,cost,k);
    Print(P,cost);
    delete[] P;
    return 0;
}

void FGRAPH(int *P,int &cost,const int k)
{
    int *D = new int[k-1];
    int *COST = new int[k-1];
    COST[k-1] = 0;
    for(int j = k-2;j >= 0;--j){//计算COST[j]
        _pSGraph temp = head[j];
        int r = 0,min = INT_MAX;
        while(temp){
            int tempc = temp->value + COST[temp->node-1];
            if(min > tempc){
                min = tempc;
                r = temp->node-1;
            }
            temp = temp->next;
        }
        COST[j] = min;
        D[j] = r;
    }
    P[0] = 0;
    P[k-1] = k-1;
    for(int j = 1;P[j-1] != k-1;++j){
        P[j] = D[P[j-1]];
    }
    cost = COST[0];
}

void Print(const int *P,const int cost)
{
    cout << "--由源点到汇点的最短路径为--" << endl;
    for(int i = 0;P[i] != -1;++i){
        cout << P[i]+1 << " ";
    }
    cout << endl;
    cout << "成本为: " << cost << endl;
}
