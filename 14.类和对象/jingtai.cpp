#include <iostream>
using namespace std;

class Base
{
public:
    static int m_a;//类内声明
    static void func()
    {
        cout<<"Base static void func 的调用"<<endl;
    }
    static void func(int a)
    {
        cout<<"Base static void func 的调用"<<endl;
    }
};

int Base::m_a=100;//类外初始化

class Son:public Base
{
public:
    static int m_a;//类内声明
    static void func()
    {
        cout<<"Son static void func 的调用"<<endl;
    }

};
int Son::m_a=200;//类外初始化

//同名静态成员函数
void test02()
{
    //1. 通过对象访问
    Son s;
    s.func();//Son static void func 的调用
    s.Base::func();//Base static void func 的调用

    //2.通过类名访问
    Son::func();//Son static void func 的调用
    Son::Base::func();//Base static void func 的调用

    //子类出现和父类同名的静态成员函数时，也会隐藏掉父类中所有的同名成员函数
    //如果想访问父类中被因此的题目成员，需要加父类的作用域
    Son::Base::func(0);//Base static void func 的调用
}


int main()
{
    test02();
}