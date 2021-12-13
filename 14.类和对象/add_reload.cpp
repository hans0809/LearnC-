#include <iostream>
using namespace std;

class Person
{
public:
    // //1.成员函数重载+
    // Person operator+(Person &p)
    // {
    //     Person temp;
    //     temp.m_a=this->m_a+p.m_a;
    //     temp.m_b=this->m_b+p.m_b;
    //     return temp;
    // }


    int m_a,m_b;
};

//2. 全局函数重载+
// Person operator+(Person &p1,Person &p2)
// {
//     Person temp;
//     temp.m_a=p1.m_a+p2.m_a;
//     temp.m_b=p1.m_b+p2.m_b;
//     return temp;
// }
//函数重载的版本
Person operator+(Person &p1,int num)
{
    Person temp;
    temp.m_a=p1.m_a+num;
    temp.m_b=p1.m_b+num;
    return temp;
}
void test01()
{
    Person p1,p2;
    p1.m_a=10;p1.m_b=10;
    p2.m_a=10;p2.m_b=10;

    Person p3=p1+100;//Person + int
    cout<<p3.m_a<<" "<<p3.m_b<<endl;//110 110
}

int main()
{
    test01();
}