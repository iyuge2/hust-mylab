#include<iostream>

using namespace std;

inline void swaptwoint(int &a,int &b)
{
    int temp = a ^ b;
    a = temp ^ a;
    b = temp ^ b;
}

/*快速排序*/
void mysort(int *a,int l,int r)
{
    if(r <= l){
        return;
    }
    int key = a[l];
    int L = l,R = r;
    while(r > l){
        while(r > l && key <= a[r]){
            --r;
        }
        swaptwoint(a[r],a[l]);
        while(r > l && key >= a[l]){
            ++l;
        }
        swaptwoint(a[r],a[l]);
    }
    mysort(a,L,r);
    mysort(a,r+1,R);
}

/*冒泡排序*/
void myoutsort(int *a,int l,int r)
{
    for(int i = l;i <= r;++i){
        for(int j = l;j <= r-l-1;++j){
            if(a[j] > a[j+1]){
                swaptwoint(a[j],a[j+1]);
            }
        }
    }
}

/*插入排序*/
void myinsertsort(int *a,int l,int r)
{
    for(int i = l+1;i <= r;++i){
        for(int j = i;j >= l+1;--j){
            if(a[j] < a[j-1]){
                swaptwoint(a[j],a[j-1]);
            }
            else{
                break;
            }
        }
    }
}

/*归并排序*/
void merge(int *a,int *LINK,int q,int r,int &p)
{
    int i = q,j = r,k = 0;
    while(i && j){
        if(a[i] <= a[j]){
            LINK[k] = i;
            k = i;
            i = LINK[i];
        }
        else{
            LINK[k] = j;
            k = j;
            j = LINK[j];
        }
    }
    if(i == 0){
        LINK[k] = j;
    }
    else{
        LINK[k] = i;
    }
    p = LINK[0];
}

void mergesort(int *a,int l,int r,int *LINK){
    if(l < r){
        int mid = (l+r)/2;
        mergesort(a,l,mid,LINK);
        mergesort(a,mid+1,r,LINK);
        merge(a,LINK,l,mid,r);
    }
}

int main()
{
    int n;
    cin >> n;
    int *qsort = new int[n];
    int *outsort = new int[n];
    int *insertsort = new int[n];
    int *msort = new int[n];

    for(int i = 0;i < n;++i){
        cin >> qsort[i];
        outsort[i] = qsort[i];
        insertsort[i] = qsort[i];
        msort[i] = qsort[i];
    }

    mysort(qsort,0,n-1);
    myoutsort(outsort,0,n-1);
    myinsertsort(insertsort,0,n-1);

    int *LINK = new int[n];/*堆上内存自动初始化为0*/
    mergesort(msort,0,n-1,LINK);

    cout << "qsort: ";
    for(int i = 0;i < n;++i){
        cout << qsort[i] << " ";
    }
    cout << endl;

    cout << "outsort: ";
    for(int i = 0;i < n;++i){
        cout << outsort[i] << " ";
    }
    cout << endl;

    cout << "insertsort: ";
    for(int i = 0;i < n;++i){
        cout << insertsort[i] << " ";
    }
    cout << endl;

    cout << "mergesort: ";
    for(int i = LINK[0];i != 0;i = LINK[i]){
        cout << msort[i] << " ";
    }
    cout << endl;


    delete[] qsort;
    delete[] outsort;
    delete[] insertsort;
    delete[] msort;
    delete[] LINK;
    return 0;
}
