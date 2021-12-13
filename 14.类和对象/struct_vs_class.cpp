#include <iostream>
using namespace std;
class C1
{
    int m_A;//默认权限是私有private
};
struct C2
{
    int m_A;//默认权限是公共public
};
int main()
{
    C1 c1;
    //c1.m_A=100;//报错，类外不能访问

    C2 c2;
    c2.m_A=100;//
}