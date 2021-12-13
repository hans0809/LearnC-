#include <iostream>
using namespace std;

class Person
{
public:
    void showClassName()
    {
        cout<<"this is a person class"<<endl;
    }
    void showPersonAge()
    {
        if (this ==NULL) return;
        cout<<"age="<<m_age<<endl;//相当于cout<<"age="<<this->m_age<<endl;
    }
    int m_age;
};

void test01()
{
    //空指针访问成员函数
    Person *p=NULL;
    p->showClassName();
    p->showPersonAge();
    
    //非空指针访问成员函数
    Person p1;
    Person *p2=&p1;
    p2->m_age=10;
    cout<<p2<<endl;
    p2->showClassName();
    p2->showPersonAge();
}

int main()
{
    test01();
}