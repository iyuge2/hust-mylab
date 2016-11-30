#include"STACK.h"

STACK::STACK(int m):elems(new int[m]),max(elems?m:0)
{
    if(elems)
    {
        pos = 0;
    }
}

STACK::STACK(const STACK& s):elems(new int[s.max]),max(elems?s.max:0)
{
    if(elems)
    {
        for(pos = 0;pos < s.pos;pos++)
        {
            elems[pos] = s.elems[pos];
        }
    }
}

STACK::~STACK()
{
    delete[] elems;
    *(int**)&elems = 0;
}

int STACK::size()const
{
    return max;
}

STACK::operator int()const
{
    return pos;
}

int STACK::operator[](int x)const
{
    if(x >= pos)
    {
        cout << "超过栈的实际长度!" << endl;
        return -1;
    }
    return elems[pos-x-1];
}

STACK& STACK::operator<<(int e)
{
    if(pos < max)
    {
        elems[pos++] = e;
    }
    return *this;
}

STACK& STACK::operator>>(int &e)
{
    e = elems[--pos];
    return *this;
}

STACK& STACK::operator=(const STACK& s)
{
    delete[] elems;
    *(int**)&elems = new int[s.max];//强制给const变量赋值
    *(int*)&max = s.max;
    for(pos = 0;pos < s.pos;pos++)
    {
        elems[pos] = s.elems[pos];
    }
    return *this;
}

void STACK::print()const
{
    if(!pos)
    {
        cout << "栈为空!" <<endl;
        return ;
    }
    for(int i=(pos-1);i >= 1;i--)
    {
        cout << elems[i] << ' ';
    }
    cout << elems[0] << endl;
}
