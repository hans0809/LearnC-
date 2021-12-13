#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->age=age;//this指针指向被调用的成员函数
    }
    //若以值方式返回，会创建新的对象，所以这里用引用&
    Person& PersonAddAge(Person &p)
    {
        this->age+=p.age;
        return *this;//返回对象本身
    }
    int age;//形参和变量名字相同，会出错，需要加个this，或者给变量改个名，比如m_age.
};
void test01()
{
    Person p1(18);
    cout<<"p1 的年龄"<<p1.age<<endl;//p1 的年龄18
}
//2.返回对象本身
void test02()
{
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1);
    cout<<"p2 age:"<<p2.age<<endl;//p2 age:30
}
int main()
{
    test01();
    test02();
}