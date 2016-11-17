#include"QUE2S.h"

QUE2S::operator int()const
{
    return s1+s2;
}

QUE2S& QUE2S::operator <<(int e)
{
    int *t = new int[s1+s2];
    int i = 0;
    int len1 = s1,len2 = s2;
    int max1 = s1.size();
    int max2 = s2.size();
    if(len1 == max1 && len2 != max2)
    {//栈s1满了，但s2没有满
        for(i = 0;i < len2;i++)
        {
            s2 >> t[i];
        }
        for(i = (len1 + len2 -1);i >= len2;i--)
        {
            s1 >> t[i];
        }
        for(i = (len1-1);i >= 0;i--)
        {
             s2 << t[i];
        }
        for(i = len1;i < (len1+len2);i++)
        {
            s1 << t[i];
        }
    }
    if(s1 != max1)
    {
        s1 << e;
    }
    delete t; t = 0;
    return *this;
}

QUE2S& QUE2S::operator >>(int &e)
{
    int temp;
    if(!s2 && !s1)
    {
        cout << "队列为空!" << endl;
        return *this;
    }
    else if(!s2 && s1)
    {//栈s2为空,s1不为空
        int len = s1;
        for(int i=0;i<len;i++)
        {
            s1 >> temp;
            s2 << temp;
        }
    }
    s2 >> e;
    return *this;
}

QUE2S& QUE2S::operator =(const QUE2S &q)
{
    s1 = q.s1;
    s2 = q.s2;
    return *this;
}

void QUE2S::print( )const
{
    int len = s1 + s2;
    QUE2S t(*this);
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

