#include <iostream>
#include <string>
using namespace std;

class Student
{
public:

    string m_name;
    int m_id;

    void showStudent()
    {
        cout<<"姓名："<<m_name<<"学号:"<<m_id<<endl;
    }
    void set_name(string name)
    {
        m_name = name;
    }
};

int main()
{
    Student s1;
    s1.m_name="Bob";
    s1.m_id=1;
    s1.showStudent();//姓名：Bob学号:1

    Student s2;
    s2.m_name="Marry";
    s2.m_id=2;
    s2.showStudent();//姓名：Marry学号:2

    s2.m_name="heheda";
    s2.showStudent();//姓名：heheda学号:2
}