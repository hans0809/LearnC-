#include <iostream>
using namespace std;

class Base
{
public:
    int m_a;
    Base()
    {
        m_a=100;
    }

    void func()
    {
        cout<<"Base func 的调用"<<endl;
    }
    void func(int a)
    {
        cout<<"Base func 的调用"<<endl;
    }
};

class Son:public Base
{
public:
    Son()
    {
        m_a=200;
    }
    int m_a;

    // void func()
    // {
    //     cout<<"Son func 的调用"<<endl;
    // }
};

//同名成员属性的处理方式
void test01()
{
    Son s;
    cout<<"Base m_a="<<s.Base::m_a<<endl;//Base m_a=100
}

//同名成员属性的处理方式
void test02()
{
    Son s;
    //直接调用，调用的是子类中的同名成员函数
    s.func();//Son func 的调用 

    //调用父类中的同名成员函数
    s.Base::func();//Base func 的调用
}

int main()
{
    test01();
    test02();
}



