#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    //设置姓名
    void set_name(string name)
    {
        m_name=name;
    }
    //获取姓名
    string get_name()
    {
        return m_name;
    }
private:
    string m_name;
    string m_age;
    string m_lover;
};

int main()
{
    Person p;
    p.set_name ( "Lucy");
    cout<<p.get_name()<<endl;//Lucy
}