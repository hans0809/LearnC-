#include <iostream>
#include<string>
using namespace std;
class Person
{
public:
    string m_name;
    string m_id;
protected:
    string m_car;
private:
    string m_password;

public:
    void func()
    {
        m_name="Bob";
        m_car="bike";
        m_password="123456";
        m_id="qwertyuio";
    }

};
int main()
{
    Person p1;

    p1.m_name="heheda";
    p1.m_id="cchdhddjjdjdjsjd";
    //p1.m_car="plane";//保护权限内容，类外访问不到
    //p1.m_password="76543";//私有权限内容，类外访问不到
    p1.func();
    cout << p1.m_id<<endl;//qwertyuio
}