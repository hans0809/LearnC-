#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person()
    {
        cout<<"Person默认（无参）构造函数调用"<<endl;
    }

    Person(int age)
    {
        cout<<"Person有参构造函数调用"<<endl;   
        m_age = age;
    }
    Person(const Person& p)
    {
        cout <<"Person拷贝构造函数调用"<<endl;
        m_age = p.m_age;
    }
    int m_age;

    ~Person()
    {
        cout<<"Person析构函数的调用"<<endl;
    }
};

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(20);//Person有参构造函数调用
    Person p2(p1);//Person拷贝构造函数调用
    cout<<"p2的年龄:"<<p2.m_age<<endl;//p2的年龄:20
}
//2. 值传递的方式给函数参数传值(拷贝一个新的临时副本出来)
void doWork(Person p)
{

}
void test02()
{
    Person p;//Person默认（无参）构造函数调用
    doWork(p); //Person拷贝构造函数调用
}

///3.值方式返回局部对象
Person doWork2()
{
    Person p1;
    cout<<(int*)&p1<<endl;
    return p1;
}
void test03()
{
    Person p=doWork2();
    cout<<(int*)&p<<endl;
}
int main()
{
    test01();
    test02();
    test03();
}