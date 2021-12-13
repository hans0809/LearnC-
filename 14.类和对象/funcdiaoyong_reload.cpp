#include <iostream>
#include <string>
using namespace std;

//加法类
class MyAdd
{
public:
    int operator()(int num1,int num2)
    {
        return num1+num2;
    }
};

void test02()
{
    //函数调用运算符()重载
    // MyAdd myadd;
    // int  ret=myadd(100,100);
    // cout<<"ret:"<<ret<<endl;

    //匿名对象
    cout<<MyAdd()(100,100)<<endl;//200
}

int main()
{
    test02();//ret:200
}