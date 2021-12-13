#include <iostream>
using namespace std;

class Person
{
public:
    //默认(无参)构造函数
    Person()
    {
        cout<<"Person的默认构造函数调用"<<endl;
    }
    //有参构造函数
    Person(int age,int height)
    {
        cout<<"Person的默认有参函数调用"<<endl;
        m_age=age;
        m_height=new int(height);
    }
    int m_age;
    int *m_height;//指针，将数据创建在堆区

    //自定义拷贝构造函数
    Person(const Person &p)
    {
        cout<<"Person拷贝构造函数的调用"<<endl;
        m_age=p.m_age;
        //m_height=p.m_height;//编译器默认实现的就是这个，这属于浅拷贝

        //改成深拷贝
        m_height=new int(*p.m_height);

    }
    //析构函数
    ~Person()
    {
        //析构代码，将堆区开辟的数据进行释放
        if(m_height!=NULL)
        {
            delete m_height;
            m_height = NULL;
        }
        cout<<"Person的析构函数调用"<<endl;
    }
};
void test01()
{
    Person p1(19,180);
    cout<<"p1的年龄："<<p1.m_age<<"身高为:"<<*p1.m_height<<endl;//p1的年龄：19身高为:180

    Person p2(p1);
    cout<<"p2的年龄："<<p2.m_age<<"身高为:"<<*p2.m_height<<endl;//p1的年龄：19身高为:180
    
}
int main()
{
    test01();
}