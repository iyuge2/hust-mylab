/*
 * print 128 chars
 * */
#include<iostream>

using namespace std;

int main()
{
    char ch = 0;
    for(int i = 0;i < 128;++i){
        cout << dec << i << ": ";
        cout << dec << ch << '\t';
        cout << hex << ch++ << endl;
    }
    return 0;
}
