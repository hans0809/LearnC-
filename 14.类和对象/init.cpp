#include <iostream>
using namespace std;

class Person
{
public:
    // //传统初始化操作
    // Person(int a ,int b ,int c )
    // {
    //     m_a=a; 
    //     m_b=b; 
    //     m_c=c;
    // }
    int m_a,m_b,m_c; 

    Person(int a,int  b,int c):m_a(a),m_b(a),m_c(a)
    {

    }
};
void test01()
{
    //Person p(10,20,30);
    Person p(10,20,30);
    cout<<"m_a"<<p.m_a<<"m_b"<<p.m_b<<"c"<<p.m_c<<endl;
}
int  main()
{
    test01();
}