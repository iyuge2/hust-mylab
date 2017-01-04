#include<iostream>

using namespace std;

inline void swaptwoint(int &a,int &b)
{
    int temp = a ^ b;
    a = temp ^ a;
    b = temp ^ b;
}

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

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];
    }
    mysort(a,0,n-1);
    for(int i = 0;i < n;++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}
