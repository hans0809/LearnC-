#include <iostream>
#include <string>
using namespace std;

class Phone
{
public:
    //有参构造吧
    Phone(string pname)
    {
        cout<<"Phone 构造函数的调用"<<endl;
        m_pname=pname;
    }
    ~Phone()
    {
        cout<<"Phone析构函数的调用"<<endl;
    }
    
    string m_pname;
};
class Person
{
public:
    //初始化列表赋初值
    //m_phone(pname)相当于Phone m_pname=pname 隐式转换法
    Person(string name,string pname):m_name(name),m_phone(pname)
    {
        cout<<"Person 构造函数的调用"<<endl;
    }
    
    //字符串
    string m_name;
    //对象，
    Phone m_phone;  

    ~Person()
    {
        cout<<"Person析构函数的调用"<<endl;
    }  
};

void test01()
{
    Person p("Bob","Apple");
    cout<<p.m_name<<p.m_phone.m_pname<<endl;//BobApple
}
int main()
{
    test01();
}