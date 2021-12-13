#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
    int m_age;
};

//羊类
class Sheep:virtual public Animal{};

//驼类
class Tuo: virtual public Animal{};

//羊驼类
class SheepTuo:public Sheep, public Tuo{};

void test01()
{
    SheepTuo st;
    st.Sheep::m_age=18;
    st.Tuo::m_age=20;
    //当零星继承，两个父类拥有相同数据，需要加作用域用以区分
    cout<<"st.Sheep::m_age="<<st.Sheep::m_age<<endl;//st.Sheep::m_age=20
    cout<<"st.Tuo::m_age="<<st.Tuo::m_age<<endl;//st.Tuo::m_age=20

    //当使用虚继承后，可以不加作用域了，因为此时就一份数据
    cout<<"st.m_age="<<st.m_age<<endl;//st.m_age=20

}

int main()
{
    test01();
}