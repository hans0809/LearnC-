#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    char m_name[64];
    int m_age;
};

void test01()
{
    ifstream ifs;
    ifs.open("person.txt",ios::in|ios::binary);
    if (!(ifs.is_open()))
    {
        cout<<"读取失败"<<endl;
        return;
    }
    Person p;
    ifs.read((char*)&p,sizeof(Person));
    cout<<"姓名："<<p.m_name<<"年龄："<<p.m_age<<endl;//姓名：张三年龄：18
    ifs.close();
}

int main()
{
    test01();
}