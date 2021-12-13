#include <iostream>
using namespace std;

class Person
{
public:
    //不会利用成员运算符重载左移运算符
    // //利用成员函数重载 左移运算符
    // void operator<<(Person&p)
    // {
    // }
    int m_a,m_b;
};

ostream &operator<<(ostream &cout,Person &p)//本质：operator<<(cout,p),简化为:cout<<p
{
    cout<<p.m_a<<" "<<p.m_b<<endl;
    return cout;//链式编程思想
}
void test01()
{
    Person p;
    p.m_a =10;
    p.m_b =10;

    cout<<p.m_a<<" "<<p.m_b<<endl;//10 10
    
    //使用<<重载来直接输出p
    cout<<p;//10 10
    //cout<<p<<endl;中，根据链式编程思想可以追加多个<<
}

int main()
{
    test01();
}