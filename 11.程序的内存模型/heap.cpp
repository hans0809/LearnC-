#include <iostream>
using namespace std;

int *func()
{
    //利用new关键字，可以在堆区开辟数据
    int *p=new int(10);
    return p;
}
int main()
{
    //在堆区开辟数据
    int *p=func();
    cout<<*p<<endl;//10
    cout<<*p<<endl;//10
    cout<<*p<<endl;//10
}