#include <iostream>
using namespace std;

//设计一个圆类，求圆的周长
//圆的周长公式：2*pi*r
const double PI = 3.14; //圆周率

class Circle
{
    //访问权限
public: //公共权限
    //属性
    int m_radius;//半径
    //行为
    double calculate()//计算圆的周长
    {
        return 2*PI*m_radius;
    }
};

int main()
{
    Circle circle;//通过类创建一个具体的对象
    circle.m_radius =10;//半径赋值为10
    cout<<"圆的周长为"<<circle.calculate()<<endl;//圆的周长为62.8
}