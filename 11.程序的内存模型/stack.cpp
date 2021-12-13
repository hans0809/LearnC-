#include <iostream>
using namespace std;

int *func()
{
    int a=10;//局部变量，存放在栈区
    return &a;//返回局部变量的地址
}
int main()
{
    int *p=func();
    cout<<*p<<endl;
}