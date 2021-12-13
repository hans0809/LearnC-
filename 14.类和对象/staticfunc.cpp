#include <iostream>
using namespace std;

class Person
{
public:
    //静态成员函数
    static void func()
    {
        m_a=100;//静态成员函数可以访问静态成员变量
        //m_b=10000;//静态成员函数不可以访问非静态成员变量，因为无法区分到底是哪个对象的
        cout<<"static void func的调用"<<endl;
    }
    static int m_a;//静态成员变量
    int m_b;//非静态成员变量
private:
    static void func2()
    {
        cout<<"static void func2的调用"<<endl;
    }
};
int Person::m_a=0;//静态成员变量

void test01()
{
    //1.通过对象进行访问
    Person p;
    p.func();

    //2.通过类名进行访问
    Person::func();

    //Person::func2();//错误，func2是私有的，类外访问不到私有静态成员函数
}
int main()
{
    test01();
}