#include<iostream>

using namespace std;

static int *X,*W;
static int M = 0;

void Print(int k)
{
    cout << "( ";
    for(int i = 0;i <= k;++i){
        if(X[i]){
            cout << W[i] << " ";
        }
    }
    cout << ")" << endl;
    cout << "------------------------------------------------------------" << endl;
}

void SUMOFSUB(int s,int k,int r)
{
    X[k] = 1;
    cout << "[ " << s << "," << k+1 << "," << r << " ]" << endl;
    if(s + W[k] == M){
        Print(k);
    }
    else if(s + W[k] + W[k+1] <= M){
        SUMOFSUB(s+W[k],k+1,r-W[k]);
    }
    if((s+r-W[k] >= M) && (s+W[k+1] <= M)){
        X[k] = 0;
        SUMOFSUB(s,k+1,r-W[k]);
    }
}

int main()
{
    int n = 0,r = 0;
    cout << "input n: ";
    cin >> n;
    X = new int[n];
    W = new int[n];
    cout << "input W: ";
    for(int i = 0;i < n;++i){
        cin >> W[i];
        r += W[i];
    }
    cout << "input M: ";
    cin >> M;
    int s = 0,k = 0;
    SUMOFSUB(s,k,r);
    return 0;
}
