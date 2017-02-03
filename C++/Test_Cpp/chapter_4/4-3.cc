/*
 * look up some basic type's size
 * */
#include<iostream>
#include<typeinfo>

using namespace std;

template<typename T>

struct Type{
    static void print(){
        cout << "sizeof(" << typeid(T).name() << ") = " << sizeof(T) << endl;
    }
};

int main()
{
    Type<char>::print();
    Type<bool>::print();
    Type<unsigned char>::print();
    Type<unsigned int>::print();
    Type<int>::print();
    Type<double>::print();
    return 0;
}
