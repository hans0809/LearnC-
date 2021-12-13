#include <iostream>
using namespace std;

//静态成员变量
class Person
{
public:
    //1.所有对象都共享同一份数据
    //2.编译阶段就分配内存
    //3. 类内声明，类外初始化
    static int m_a;//类内声明
private:
    static int m_b;
};
int Person::m_a=100;//类外初始化
int Person::m_b=300;//类外初始化
void test01()
{
    Person p;
    cout<<p.m_a<<endl;//100

    Person p2;
    p2.m_a=200;
    cout<<p.m_a<<endl;//200 所有对象都共享同一份数据
}

void test02()
{
    //所有对象都共享同一份数据
    //静态成员变量有两种访问方式
    //1.通过对象进行访问
    Person p;
    cout<<p.m_a<<endl;//200
    //2.通过类名进行访问
    cout<<Person::m_a<<endl;//200

    //静态成员变量也是有访问权限的
    //cout<<Person::m_b<<endl;//m_b是私有的，因此类外不能访问
}
int main()
{
    test01();
    test02();
}