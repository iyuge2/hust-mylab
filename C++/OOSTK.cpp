#include"OOSTK.h"

OOSTK::OOSTK(int m):elems(new int[m]),max(elems?m:0)
{
    if(elems)
    {
        pos = 0;
    }
}

OOSTK::OOSTK(const OOSTK& s):elems(new int[s.max]),max(elems?s.max:0)
{
    if(elems)
    {
        for(pos = 0;pos < s.pos;pos++)
        {
            elems[pos] = s.elems[pos];
        }
    }
}

OOSTK::~OOSTK()
{
    if(elems)
    {
        delete[] elems;
        *(int**)&elems = 0;
    }
}

int OOSTK::size()const
{
    return max;
}

int OOSTK::howMany()const
{
    return pos;
}

int OOSTK::getelem(int x)const
{
    if(x >= pos)
    {
        cout << "超过栈的实际长度!" << endl;
        return -1;
    }
    return elems[pos-x-1];
}

OOSTK& OOSTK::push(int e)
{
    if(pos < max)
    {
        elems[pos++] = e;
    }
    return *this;
}

OOSTK& OOSTK::pop(int &e)
{
    e = elems[--pos];
    return *this;
}

OOSTK& OOSTK::assign(const OOSTK& s)
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

void OOSTK::print()const
{
    if(!pos)
    {
        cout << "栈为空" <<endl;
        return ;
    }
    for(int i=(pos-1);i >= 1;i--)
    {
        cout << elems[i] << ' ';
    }
    cout << elems[0] << endl;
}
