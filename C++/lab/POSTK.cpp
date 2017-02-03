#include"POSTK.h"

void initPOSTK(POSTk *const p,int m)
{
    p->elems = (int*)malloc(sizeof(int)*m);
    if(p->elems)
    {
        p->max = m;
        p->pos = 0;
    }
}

void initPOSTK_s(POSTk *const p,const POSTk *s)
{
    int i = 0;
    if(p->elems)
    {
        free(p->elems);
        p->elems = 0;
    }
    p->elems = (int*)malloc(sizeof(int)*s->max);
    if(p->elems)
    {
        p->max = s->max;
        p->pos = s->pos;
        for(i = 0;i < p->pos;i++)
        {
            p->elems[i] = s->elems[i];
        }

    }
}

int size(const POSTk *const p)
{
    return p->max;
}

int howMany(const POSTk *const p)
{
    return p->pos;
}

int getelem(const POSTk* const p,int x)
{
    if(x > (p->pos-1))
    {
        return -1;
    }
    return p->elems[x];
}

POSTk *const push(POSTk *const p,int e)
{
    if(p->pos >= p->max)
    {
        return p;
    }
    else
    {
        p->elems[p->pos] = e;
        p->pos++;
        return p;
    }
}

POSTk *const pop(POSTk *const p,int *e)
{
    if(p && p->pos)
    {
        *e = p->elems[--p->pos];
        return p;
    }
    return p;
}

POSTk *const assign(POSTk *const p,const POSTk *s)
{
    int i = 0;
    if(p->elems)
    {
        free(p->elems);
    }
    p->elems = (int*)malloc(sizeof(int)*(s->max));
    if(p->elems)
    {
        p->max = s->max;
        p->pos = s->pos;
        for(i = 0;i < p->pos;i++)
        {
            p->elems[i] = s->elems[i];
        }
        return p;
    }
    return 0;
}

void print(const POSTk *const p)
{
    int i = 0;
    if(!p->pos)
    {
        printf("栈为空!\n");
        return ;
    }
    if(p)
    {
        for(i = p->pos-1;i >= 1;i--)
        {
            printf("%d ",p->elems[i]);
        }
    }
    printf("%d\n",p->elems[0]);
}

void destroyPostk(POSTk *const p)
{
    if(p->elems)
    {
        free(p->elems);
        p->elems = 0;
        p->max = 0;
        p->pos = 0;
    }
}
