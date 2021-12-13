#include <iostream>
using namespace std;

//纯虚函数和抽象类
class Base
{
public:
    //只要有一个纯虚函数，这个类就成为抽象类
    //抽象类特点：
    //1. 无法实例化对象
    //2. 抽象类的子类必须要重写父类中的纯虚函数，否则而也属于抽象类
    virtual void func()=0;
};

class Son:public Base
{
public:
    void func()
    {
        cout<<"func调用"<<endl;
    }
};


void test01()
{
    //Base base;//错误，抽象类无法实例化对象
    //new Base;//错误，抽象类无法实例化对象
    Base *base=new Son;
    base->func();////func调用

    Son *son=new Son;
    son->func();////func调用
}

int main()
{
    test01();
}