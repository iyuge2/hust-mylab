#include<iostream>

using namespace std;

float Q_rsqart(float x)
{
    const float threehalfs = 1.5f;
    int i;
    float xhalf,y;
    xhalf = x * 0.5f;
    y = x;
    /*用位操作来取得较好的初始值*/
    i = *(int*)&y;
    i = 0x5f3759df - (i >> 1); //魔术常数，更优值->0x5f375a86
    y = *(float*)&i;

    y = y * (threehalfs - (xhalf * y * y));/*牛顿迭代法*/
    y = y * (threehalfs - (xhalf * y * y));

    return y;
}

int main()
{
    float t;
    cin >> t;
    cout << 1.0/Q_rsqart(t) << endl;
    return 0;
}
