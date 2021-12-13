#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    char m_name[64];//姓名
    int m_age; //年龄
};

void test01()
{
    ofstream ofs;
    ofs.open("person.txt",ios::out|ios::binary);
    cout<<p.m_name<<endl;
    ofs.write((const char*)&p,sizeof(Person));
    ofs.close();
}

int main()
{
    test01();
}