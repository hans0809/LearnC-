#include <iostream>
using namespace std;
class Person
{
public:
    //有参构造函数
    Person(int age)
    {
        cout<<"Person的有参构造函数调用"<<endl;
        m_age = age;

    }
    int m_age;

    //默认析构函数
    ~Person()
    {
        cout<<"Person的默认析构函数调用"<<endl;
    }
};

void test02()
{
    Person p(28);//Person的有参构造函数调用
    cout<<"p的年龄："<<p.m_age<<endl;//p2的年龄：28
}
int main()
{
    test02();
}