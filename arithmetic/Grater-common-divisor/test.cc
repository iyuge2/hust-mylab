#include<iostream>
#include"more-phase-impairment.cc"
#include"successive-division.cc"



//#define _MORE_PHASE_IMPAIRMENT
#define _SUCCESSIVE_DIVISION
extern int more_phase_impairment(int,int);

using namespace std;

int main()
{
    int m,n;
    cin >> m >> n;
#ifdef _MORE_PHASE_IMPAIRMENT
    cout << more_phase_impairment(m,n) << endl;
#endif

#ifdef _SUCCESSIVE_DIVISION
    cout << successive_division(m,n) << endl;
#endif
    return 0;
}
