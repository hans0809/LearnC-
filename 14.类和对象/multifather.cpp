#include <iostream>
using namespace std;

class Base1
{
public:
    Base1()
    {
        m_a=100;
    }
    int m_a;
};
class Base2
{
public:
    Base2()
    {
        m_a=111;
        m_b=200;
    }
    int m_a,m_b;
};

//子类Son同时继承Base1和Base2
class Son:public Base1,public Base2
{
public:
    Son()
    {
        m_c=300;
        m_d=400;
    }
    int m_c;
    int m_d;
};

void test01()
{
    Son s;
    cout<<"sizeof Son="<<sizeof(Son)<<endl;//sizeof Son=16

    //当父类中出现同名成员，需要加作用域
    cout<<"Base1::m_a="<<s.Base1::m_a<<endl;//Base1::m_a=100
    cout<<"Base2::m_a="<<s.Base2::m_a<<endl;//Base2::m_a=111

    
}
int main()
{
    test01();
}