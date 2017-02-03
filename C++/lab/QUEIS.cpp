#include"QUEIS.h"

QUEIS::operator int()const
{
    return s+STACK::operator int();
}

QUEIS& QUEIS::operator <<(int e)
{
    int i = 0;
    int len1 = STACK::operator int(),len2 = s;
    int max1 = STACK::size();
    int max2 = s.size();
    int *t = new int[len1+len2];
    if(len1 == max1 && len2 != max2)
    {//栈s1满了，但s2没有满
        for(i = 0;i < len2;i++)
        {
            s >> t[i];
        }
        for(i = (len1 + len2 -1);i >= len2;i--)
        {
            STACK::operator >>(t[i]);
        }
        for(i = (len1-1);i >= 0;i--)
        {
             s << t[i];
        }
        for(i = len1;i < (len1+len2);i++)
        {
            STACK::operator <<(t[i]);
        }
    }
    if((STACK::operator int()) != max1)
    {
        STACK::operator <<(e);
    }
    delete t; t = 0;
    return *this;
}

QUEIS& QUEIS::operator>>(int &e)
{
    int temp;
    int len = (STACK::operator int());
    if(!s && !len)
    {
        cout << "队列为空!" << endl;
        return *this;
    }
    else if(!s && len)
    {
        for(int i=0;i<len;i++)
        {
            STACK::operator >> (temp);
            s << temp;
        }
    }
    s >> e;
    return *this;
}

QUEIS& QUEIS::operator=(const QUEIS &q)
{
    this->~QUEIS();
    new (this) QUEIS(q);//利用当前对象进行重新构造
    return *this;
}

void QUEIS::print( )const
{
    int len = s + (STACK::operator int());
    QUEIS t(*this);
    if(!len)
    {
        cout << "队列为空！" << endl;
        return ;
    }
    int e;
    for(int i = 0;i < len-1; i++)
    {
        t >> e;
        cout << e << " ";
    }
    t >> e;
    cout << e << endl;
}

