#include <iostream>
using namespace std;

void showValue(const int &val)
{
    //val=1000;//加了cosnt后，这句就非法了
    cout<<val<<endl;
}
int main()
{
    //int &ref=10;//非法！引用必须引一块合法的内存空间
    const int &ref=10;//加上const后，编译器将代码修改为int temp=10;const int &ref=temp; 这是合法的
    //ref=20;//非法！加上const之后，变为只读，不可以修改

    int a=100;
    showValue(a);//100 
    cout<<a<<endl;//100
}