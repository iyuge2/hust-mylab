#include"main.h"

inline void PrintPostkMenu()
{
    clear();
    cout << "        |---------------Hello POSTK---------------|" << endl;
    cout << "        | <1>栈的最大长度       <2>栈的实际长度   |" << endl;
    cout << "        | <3>取元素             <4>值压栈         |" << endl;
    cout << "        | <5>值出栈             <6>复制栈         |" << endl;
    cout << "        | <7>exit                                 |" << endl;
    cout << "        |-----------------END---------------------|" << endl;
}

inline void PrintOostkMenu()
{
    clear();
    cout << "        |---------------Hello OOSTK---------------|" << endl;
    cout << "        | <1>栈的最大长度       <2>栈的实际长度   |" << endl;
    cout << "        | <3>取元素             <4>值压栈         |" << endl;
    cout << "        | <5>值出栈             <6>复制栈         |" << endl;
    cout << "        | <7>exit                                 |" << endl;
    cout << "        |-----------------END---------------------|" << endl;
}

inline void PrintStackMenu()
{
    clear();
    cout << "        |---------------Hello Stack---------------|" << endl;
    cout << "        | <1>栈的最大长度       <2>栈的实际长度   |" << endl;
    cout << "        | <3>取元素             <4>值压栈         |" << endl;
    cout << "        | <5>值出栈             <6>复制栈         |" << endl;
    cout << "        | <7>exit                                 |" << endl;
    cout << "        |-----------------END---------------------|" << endl;
}

inline void PrintQue2sMenu()
{
    clear();
    cout << "        |---------------Hello QUE2S---------------|" << endl;
    cout << "        | <1>队列的实际长度     <2>值入队列       |" << endl;
    cout << "        | <3>值出队列           <4>复制队列       |" << endl;
    cout << "        | <5>exit                                 |" << endl;
    cout << "        |-----------------END---------------------|" << endl;
}


inline void PrintQueisMenu()
{
    clear();
    cout << "        |---------------Hello QUEIS---------------|" << endl;
    cout << "        | <1>队列的实际长度     <2>值入队列       |" << endl;
    cout << "        | <3>值出队列           <4>复制队列       |" << endl;
    cout << "        | <5>exit                                 |" << endl;
    cout << "        |-----------------END---------------------|" << endl;
}


void TestPostk()
{
    int max;
    int op = 0,x = 0,e = 0;
    cout << "请输入栈的最大长度:";
    cin >> max;
    POSTk s1,s2,s3;
    s2.elems = 0;
    initPOSTK(&s1,max);
    initPOSTK(&s3,max);
    while(1)
    {
        initPOSTK_s(&s2,&s1);//用栈s1初始化s2
        PrintPostkMenu();
        cout <<"---------------------------------------------------"<<endl;
        cout << "s1:<--|";
        print(&s1);
        cout << "s2:<--|";
        print(&s2);
        cout << "s3:<--|";
        print(&s3);
        cout <<"---------------------------------------------------"<<endl;
        cout << "\n\n请输入操作编号<1-7>：";
        cin >> op;
        switch(op)
        {
            case 1:
                cout << size(&s1);
                getchar();getchar();
                break;
            case 2:
                cout << howMany(&s1);
                getchar();getchar();
                break;
            case 3:
                cout <<"please input x:";
                cin >> x;
                cout << getelem(&s1,x);
                getchar();getchar();
                break;
            case 4:
                cout <<"please input e:";
                cin >> e;
                push(&s1,e);
                getchar();getchar();
                break;
            case 5:
                pop(&s1,&e);
                cout << "出栈值:" << e;
                getchar();getchar();
                break;
            case 6:
                assign(&s3,&s1);
                getchar();getchar();
                break;
            case 7:
                return ;
            default:
                cout << "input error!" <<endl;
                getchar();getchar();
                break;
        }
    }
}

void TestOostk()
{
    int max;
    int op = 0,x = 0,e = 0;
    cout << "请输入栈的最大长度:";
    cin >> max;
    OOSTK s1(max),s3(max);
    while(1)
    {
        OOSTK s2(s1);//用栈s1深度拷贝构造s2
        PrintOostkMenu();
        cout <<"---------------------------------------------------"<<endl;
        cout << "s1:<--|";
        s1.print();
        cout << "s2:<--|";
        s2.print();
        cout << "s3:<--|";
        s3.print();
        cout <<"---------------------------------------------------"<<endl;
        cout << "\n\n请输入操作编号<1-7>：";
        cin >> op;
        switch(op)
        {
            case 1:
                cout << s1.size();
                getchar();getchar();
                break;
            case 2:
                cout << s1.howMany();
                getchar();getchar();
                break;
            case 3:
                cout <<"please input x:";
                cin >> x;
                cout << s1.getelem(x);
                getchar();getchar();
                break;
            case 4:
                cout <<"please input e:";
                cin >> e;
                s1.push(e);
                getchar();getchar();
                break;
            case 5:
                s1.pop(e);
                cout << "出栈值:" << e;
                getchar();getchar();
                break;
            case 6:
                s3.assign(s1);
                getchar();getchar();
                break;
            case 7:
                return ;
            default:
                cout << "input error!" <<endl;
                getchar();getchar();
                break;
        }
    }
}

void TestStack()
{
    int max;
    int op = 0,x = 0,e = 0;
    cout << "请输入栈的最大长度:";
    cin >> max;
    STACK s1(max),s3(max);
    while(1)
    {
        STACK s2(s1);//用栈s1深度拷贝构造s2
        PrintStackMenu();
        cout <<"---------------------------------------------------"<<endl;
        cout << "s1:<--|";
        s1.print();
        cout << "s2:<--|";
        s2.print();
        cout << "s3:<--|";
        s3.print();
        cout <<"---------------------------------------------------"<<endl;
        cout << "\n\n请输入操作编号<1-7>：";
        cin >> op;
        switch(op)
        {
            case 1:
                cout << s1.size();
                getchar();getchar();
                break;
            case 2:
                cout << s1;
                getchar();getchar();
                break;
            case 3:
                cout <<"please input x:";
                cin >> x;
                cout << s1[x];
                getchar();getchar();
                break;
            case 4:
                cout <<"please input e:";
                cin >> e;
                s1 << e;
                getchar();getchar();
                break;
            case 5:
                s1 >> e;
                cout << "出栈值:" << e;
                getchar();getchar();
                break;
            case 6:
                s3 = s1;
                getchar();getchar();
                break;
            case 7:
                return ;
            default:
                cout << "input error!" <<endl;
                getchar();getchar();
                break;
        }
    }
}

void TestQue2s()
{
    int max;
    int op = 0,x = 0,e = 0;
    cout << "input max:";
    cin >> max;
    QUE2S q1(max),q3(max);
    while(1)
    {
        QUE2S q2(q1);//用栈s1深度拷贝构造s2
        PrintQue2sMenu();
        cout <<"---------------------------------------------------"<<endl;
        cout << "q1:<--|";
        q1.print();
        cout << "q2:<--|";
        q2.print();
        cout << "q3:<--|";
        q3.print();
        cout <<"---------------------------------------------------"<<endl;
        cout << "\n\n请输入操作编号<1-5>：";
        cin >> op;
        switch(op)
        {
            case 1:
                cout << q1;
                getchar();getchar();
                break;
            case 2:
                cout <<"please input e:";
                cin >> e;
                q1 << e;
                getchar();getchar();
                break;
            case 3:
                q1 >> e;
                cout << "出栈值:" << e;
                getchar();getchar();
                break;
            case 4:
                q3 = q1;
                getchar();getchar();
                break;
            case 5:
                return ;
            default:
                cout << "input error!" <<endl;
                getchar();getchar();
                break;
        }
    }
}

void TestQueis()
{
    int max;
    int op = 0,x = 0,e = 0;
    cout << "input max:";
    cin >> max;
    QUEIS q1(max),q3(max);
    while(1)
    {
        QUEIS q2(q1);//用栈s1深度拷贝构造s2
        PrintQueisMenu();
        cout <<"---------------------------------------------------"<<endl;
        cout << "q1:<--|";
        q1.print();
        cout << "q2:<--|";
        q2.print();
        cout << "q3:<--|";
        q3.print();
        cout <<"---------------------------------------------------"<<endl;
        cout << "\n\n请输入操作编号<1-5>：";
        cin >> op;
        switch(op)
        {
            case 1:
                cout << q1;
                getchar();getchar();
                break;
            case 2:
                cout <<"please input e:";
                cin >> e;
                q1 << e;
                getchar();getchar();
                break;
            case 3:
                q1 >> e;
                cout << "出栈值:" << e;
                getchar();getchar();
                break;
            case 4:
                q3 = q1;
                getchar();getchar();
                break;
            case 5:
                return ;
            default:
                cout << "input error!" <<endl;
                getchar();getchar();
                break;
        }
    }
}

inline void PrintMainMenu()
{
    clear();
    cout << "        |-----------------Hello-------------------|" << endl;
    cout << "        | >> Welcome to My C++ lab Test System << |" << endl;
    cout << "        |-----------------iyuge2------------------|" << endl;
    cout << "        | <1>POSTK              <2>OOSTK          |" << endl;
    cout << "        | <3>STACK              <4>QUE2S          |" << endl;
    cout << "        | <5>QUEIS              <6>exit           |" << endl;
    cout << "        |------------------END--------------------|" << endl;
    cout << "\n\n请输入操作编号<1-6>：";
}

int main(int argc,char **argv)
{
    int op = 0;
    while(1)
    {
        PrintMainMenu();
        cin >> op;
        switch(op)
        {
            case 1:
                TestPostk();
                getchar();getchar();
                break;
            case 2:
                TestOostk();
                getchar();getchar();
                break;
            case 3:
                TestStack();
                getchar();getchar();
                break;
            case 4:
                TestQue2s();
                getchar();getchar();
                break;
            case 5:
                TestQueis();
                getchar();getchar();
                break;
            case 6:
                return 0;
            default:
                cout << "input error!" <<endl;
                getchar();getchar();
                break;
        }
    }
}
