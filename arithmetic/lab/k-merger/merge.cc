#include"merge.h"

static int *fd = NULL;

int main()
{
    int filenum = 0;
    int k = 0;
    cout << "请输入文件数: ";
    cin >> filenum;
    cout << "请输入k值: ";
    cin >> k;
    k_merge(filenum,k);
    delete[] fd;
    return 0;
}

void k_merge(int fnum,int k)
{
    if(fnum <= k){
        return ;
    }
    int i = 0;
    if((fnum % (k-1)) == 1){//判断是否需要补充虚结点
        fd = new int[fnum];
    }
    else{
        fd = new int[fnum+k-2];
    }
    srand((unsigned)time(NULL));
    for(i = 0;i < fnum;++i)
        fd[i] = rand()%100;
    cout << "随机文件序列: ";
    for(i = 0;i < fnum;++i)
        cout << fd[i] << " ";
    cout << endl;
    if((k != 2) && (fnum % (k-1)) != 1){//补充虚结点
        int temp = fnum;
        fd[fnum] = 0;
        for(;fnum % (k-1) != 1;){
            fd[fnum++] = 0;
        }
        cout << "补充" << fnum-temp << "个虚结点: ";
        for(i = 0;i < fnum;++i)
            cout << fd[i] << " ";
        cout << endl;
    }
    int *temp = new int[k];
    int sum = 0;
    int time = 0;
    cout << "---------------------------------" << endl;
    for(i = fnum;i >= k;){
        cout << "[" << time++ << "]" << endl;
        for(int j = 0;j < k;++j){
            temp[j] = findMin(i--);//找到当前最小的一个文件
            sum += temp[j];
        }
        fd[i++] = sum;
        sum = 0;
        cout << "归并的结点 :";
        for(int j = 0;j < k;++j){
            cout << temp[j] << " ";
        }
        cout << endl;
        cout << "归并后 :";
        for(int j = 0;j <= i-1;++j){
            cout << fd[j] << " ";
        }
        cout << endl;
    }
}

int findMin(int num)
{
    int temp = 0;
    for(int i = 0;i < num-1;++i){
        if(fd[i] < fd[i+1]){//交换两个数
            temp = fd[i];
            fd[i] = fd[i+1];
            fd[i+1] = temp;
        }
    }
    return fd[num-1];
}
