#include <iostream>
using namespace std;

class Building
{
    //goodDay全局函数是Building的好朋友，因此可以分为Building中的私有成员
    friend void goodDay(Building *building);
public:
    Building()
    {
        m_sittingroom="客厅";
        m_bedroom="卧室";
    }
public:
    string m_sittingroom;//客厅
private:
    string m_bedroom;//卧室
};

void goodDay(Building *building) 
{
    cout<<"好基友全局函数正在访问"<<building->m_sittingroom<<endl;
    cout<<"好基友全局函数正在访问"<<building->m_bedroom<<endl;//
}
void test01()
{
    Building building;
    goodDay(&building);
}
int main()
{
    test01();
}