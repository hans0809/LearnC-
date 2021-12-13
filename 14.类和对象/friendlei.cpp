#include <iostream>
using namespace std;

//类做友元

//建筑物的类
class Building
{
    //GoodGay是Building的好朋友，可以访问私有的
    friend class GoodGay;
public:
    string m_sittingroom;//客厅
private:
    string m_bedroom;//卧室
public:
    Building()
    {
        m_sittingroom="客厅";
        m_bedroom="卧室";
    }

};
//好基友的类
class GoodGay
{
public:
    GoodGay()
    {
        //创建一个建筑物的对象
        building=new Building;//返回指针
    }
    //参观函数，访问Building中的属性(公共和私有属性都访问)
    void visit()
    {
        cout<<"好基友类正在访问"<<building->m_sittingroom<<endl;
        cout<<"好基友类正在访问"<<building->m_bedroom<<endl;
    }
    Building *building;
};


void test01()
{
    GoodGay gg;
    gg.visit();
}


int main()
{
    test01();
}