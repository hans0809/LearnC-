#include <iostream>
using namespace std;

//公共继承

//父类
class Base1
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};

class Son1:public Base1
{
public:
    void func()
    {
        m_a=10;//父类中的公共权限成员，到子类中依然是公共权限
        m_b=10;//父类中的保护权限成员，到子类中依然是保护权限
        //m_c=10;//父类中的私有权限成员，子类访问不到
    }
};

void test01()
{
    Son1 s1;
    s1.m_a=100;//公共权限，类内类外都能访问
    //s1.m_b=100;//保护权限，类外不能访问
}
///////////////////////////////////////////////////////////////

//保护继承

//父类
class Base2
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};

class Son2:protected Base2
{
public:
    void func()
    {
        m_a=10;//父类中的公共权限成员，到子类中变为保护权限
        m_b=10;//父类中的保护权限成员，到子类中依然是保护权限
        //m_c=10;//父类中的私有权限成员，子类访问不到
    }
};
void test02()
{
    Son2 s1;
    //s1.m_a=1000;//保护权限，类外访问不到
    //s1.m_b=1000;//保护权限，类外访问不到
    //s1.m_c=10;//私有权限成员，类外访问不到
}

/////////////////////////////////////////////////////////////
//保护继承

//父类
class Base3
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};

class Son3:private Base3
{
public:
    void func()
    {
        m_a=10;//父类中的公共权限成员，到子类中变为s私有权限
        m_b=10;//父类中的保护权限成员，到子类中变为私有权限
        //m_c=10;//父类中的私有权限成员，子类访问不到
    }
};
void test03()
{
    Son3 s1;
    //s1.m_a=1000;//私有权限，类外访问不到
    //s1.m_b=1000;//私有权限，类外访问不到
    //s1.m_c=1000;////私有权限成员，类外访问不到
}

/////////////////////////////////////////////////////////////
class GrandSon3:public Son3//Son3的儿子，Base3的孙子
{
    void func()
    {
        //m_a=10;//父类中的私有权限成员，子类访问不到 
        //m_b=10;//父类中的私有权限成员，子类访问不到 
        //m_c=10;//父类中的私有权限成员，子类访问不到 
    }
};


int main()
{
    test01();
    test02();
    test03();
}
