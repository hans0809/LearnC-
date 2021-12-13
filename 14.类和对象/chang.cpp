#include <iostream>
using namespace std;

//常函数
class Person
{
public:
    //this指针的本质：指针常量，因此指针的指向是不可修改的
    // Person*cosnt this; 等价于void showPerson()
    void showPerson() const //const修饰this指针,等价于const Person*cosnt this; 此时指向和指向的值都不能修改
    {
        //无法执行，因为用了const修饰指针this，此时this的指向和指向对应的的值都不能被修改
        //m_a=100;//它等价于this->m_a=100; 
        this->m_b=100;//可以修改，因为用了mutable及进行修饰
    }
    void func()
    {
        m_a=100;
    }
    int m_a;
    mutable int m_b;//成员属性声明时加关键字mutable后，在常函数中依然可以修改
};
void test01()
{
    Person p;
    p.showPerson();
}
void test02()
{
    const Person p{};//在对象前加const，变为常对象 不加{}报错，不知道为什么
    //p.m_a=100;//assignment of member 'Person::m_a' in read-only object
    p.m_b=100;
    p.showPerson();//常对象只能调用常函数
    //p.func();//常对象只不能调用普通函数,passing 'const Person' as 'this' argument discards qualifiers [-fpermissive]
}
int main()
{
    test01();
    test02();
}