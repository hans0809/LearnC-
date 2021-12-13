#include <iostream>
using namespace std;

class Person
{
public:
    //1.构造函数
    //没有返回值
    // 函数名与类名相同
    // 构造函数可以有参数，可以发生重载
    // 创建对象时，构造函数会自动调用，而且只调用一次
    Person()
    {
        cout<<"Person构造函数的调用"<<endl;
    }

    // 2.析构函数
    // 没有返回值，不写void
    // 函数名和类名相同，在名称前要加~
    // 析构函数不可以有参数，不可以发生重载
    // 对象在销毁前，会自动调用析构函数，而且只调用一次
    ~Person()
    {
        cout<<"Person析构函数的调用"<<endl;
    }
};

//构造和析构都是必须有的实现，如果自己不实现，编译器会提供一个空实现的析构和构造函数
void test01()
{
    Person p;
}

int main()
{
    test01();//Person构造函数的调用
}