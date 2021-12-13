#include <iostream>
#include <string>
using namespace std;

class Building;

//好基友类
class GoodGay
{
public:
    GoodGay();
    void visit();//让visit函数可以访问Building中的私有成员
    void visit2();//让visit2函数不可以分为Building中的私有成员
    Building *building;
};


//建筑类
class Building
{
//成员函数作为友元
friend void GoodGay::visit();
friend void GoodGay::visit2();
public:
    Building();

public:
    string m_sittingroom;//客厅
private:
    string m_bedroom;//卧室
};

//类外实现成员函数
Building::Building()
{
    m_sittingroom="客厅";
    m_bedroom="卧室";
}
GoodGay::GoodGay()
{
    building=new Building;
}

//让visit函数可以访问Building中的私有成员
void GoodGay::visit()
{
    cout<<"visit函数正在访问"<<building->m_sittingroom<<endl;
    cout<<"visit函数正在访问"<<building->m_bedroom<<endl;
}
//让visit2函数不可以分为Building中的私有成员
void GoodGay::visit2()
{
    cout<<"visit2函数正在访问"<<building->m_sittingroom<<endl;
    cout<<"visit2函数正在访问"<<building->m_bedroom<<endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main()
{
    test01();
}