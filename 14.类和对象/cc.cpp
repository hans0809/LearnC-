#include <iostream>
using namespace std;

class Person
{
public:
    int m_a;//非静态成员变量，属于类的对象上的数据，占4个字节
    static int m_b;//静态成员变量，不属于类的对象上的数据
    void func(){}//非静态成员函数，不属于类的对象上的数据
    static void func2(){}//静态成员函数，不属于类的对象上的数据
};
void test01()
{
    Person p;
    //空对象占用的内存空间
    //C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout<<"sizeof(p)="<<sizeof(p)<<endl;//sizeof(p)=1
}
void test02()
{
    Person p;
    cout<<"sizeof(p)="<<sizeof(p)<<endl;//sizeof(p)=4
}
int main()
{
    test01();
}