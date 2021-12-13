#include <iostream>
#include <string>
using namespace std;

//虚析构和纯虚析构

class Animal
{
public:
    Animal()
    {
        cout<<"Animal构造函数调用"<<endl;
    }
    // //虚析构，可以解决父类指针释放子类对象时不干净的问题
    // virtual ~Animal()
    // {
    //     cout<<"Animal析构函数调用"<<endl;
    // }

    //纯虚析构
    //纯虚析构，需要声明也需要实现
    //有了纯虚析构之后，这个类属于抽象类，无法实例化对象
    virtual ~Animal()=0;
 
    //纯虚函数
    virtual void speak()=0;
};

//纯虚析构，需要声明也需要实现
//有了纯虚析构之后，这个类属于抽象类，无法实例化对象
Animal::~Animal()
 {
     cout<<"纯虚析构函数调用"<<endl;
 }


class Cat:public Animal
{
public:
    Cat(string name)
    {
        cout<<"Cat构造函数调用"<<endl;
        m_name=new string(name);
    }
    ~Cat()
    {
        if (m_name!=NULL)
        {
            cout<<"Cat析构函数调用"<<endl;
            delete m_name;
            m_name=NULL;
        }
    }
    virtual void speak()
    {
        cout<<*m_name<<"小猫在说话"<<endl;
    }
    string *m_name;//创建到堆区
};

void test01()
{
    Animal *animal=new Cat("Tom");
    animal->speak();//Tom小猫在说话
    delete animal;
}

int  main()
{
    test01();
}