#include <iostream>
using namespace std;

void func(int a,int b)
{
    cout<<"func(int a , int b)的调用"<<endl;
}
void func(int a)
{
    cout<<"func(int a)的调用"<<endl;
}
int main()
{
    int a=10;
    func(a,3);//func(int a)的调用
}