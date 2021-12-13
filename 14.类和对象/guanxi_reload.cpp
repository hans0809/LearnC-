#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name,int age)
    {
        m_name = name;
        m_age = age;
    }

    //重载==
    bool operator==(Person &p)
    {
        if (this->m_name == p.m_name && this->m_age == p.m_age)
        {
            return true;
        }
        return false;
    }
    //重载!=
    bool operator!=(Person &p)
    {
        if (this->m_name != p.m_name || this->m_age != p.m_age)
        {
            return true;
        }
        return false;
    }

    string m_name;
    int m_age;
};

void test01()
{
    Person p1("Tom",18);
    Person p2("Tom",18);

    if (p1==p2)
    {
        cout<<"p1=p2"<<endl;
    }
    else
    {
        cout<<"p1!=p1"<<endl;
    }
    //p1=p2

    Person p3("Tom",18);
    Person p4("Tom",180);
    if(p3!=p4)
    {
        cout<<"p3!=p4"<<endl;
    }
    //p3!=p4
}

int main()
{
    test01();
}