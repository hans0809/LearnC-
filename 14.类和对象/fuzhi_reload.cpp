#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_age=new int(age);//将数据开辟到堆区
    }
    ~Person()
    {
        if (m_age!=NULL)
        {
            delete m_age;
            m_age=NULL;
        }
    }
    //操作赋值运算符，使其成为深拷贝
    Person& operator=(Person&p)
    {
        //编译器提供的=是浅拷贝
        //m_age=p.m_age;

        //应该先判断是否有属性在堆区，如果有，应该先释放干净，然后再做深拷贝
        if(m_age!=NULL)
        {
            delete m_age;
            m_age=NULL;
        }

        m_age = new int(*p.m_age);//指针哦~

        return *this;
    }
    int *m_age;
};

void test01()
{
    Person p1(18);
    cout<<"p1的年龄："<<*p1.m_age<<endl;//p1的年龄：18

    Person p2(20);
    cout<<"p2的年龄："<<*p2.m_age<<endl;//p1的年龄：20

    p2=p1;//赋值操作，深拷贝
    cout<<"p2的年龄："<<*p2.m_age<<endl;//p1的年龄：18

    Person p3(21);

    p3=p2=p1;
    cout<<"p3的年龄："<<*p3.m_age<<"p2的年龄："<<*p2.m_age<<"p1的年龄："<<*p1.m_age<<endl;
    //p3的年龄：18p2的年龄：18p1的年龄：18
}

int main()
{
    test01();
}