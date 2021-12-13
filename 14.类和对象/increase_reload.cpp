#include <iostream>
using namespace std;


class MyInteger
{
    friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
    MyInteger()
    {
        m_num=0;
    }
    //重载前置++运算符
    MyInteger& operator++()
    {
        m_num+=1;//先做自增运算
        return *this;//再将自身返回
    }

    //重载后置++运算符，此时不用返回引用，因为temp是临时的
    MyInteger operator++(int)//int:占位参数，可以用于区分前置递增和后置递增
    {
        MyInteger temp=*this;//先记录当时的结果
        m_num+=1;//后做自增运算
        return temp;
    }
private:
    int m_num;
};
//全局函数重载左移运算符，返回引用是为了对一个同变量进行自增操作
ostream& operator<<(ostream& cout, MyInteger myint)
{
    cout<<myint.m_num<<endl;
    return cout;
}
void test01()
{
    MyInteger myint;
    cout<<myint<<endl;//0
    
    //使用重载的前置++
    cout<<++myint<<endl;//1

    cout<<++(++myint)<<endl;//3
}

void test02()
{
    MyInteger myint;
    //使用重载的后置++
    cout<<myint++<<endl;//0
    cout<<myint<<endl;//1
    cout<<(myint++)++<<endl;//1
    cout<<myint<<endl;//2
}
int main()
{
    test01();
    test02();
}