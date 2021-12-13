#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout<<"Base的构造函数"<<endl;
    }
    ~Base()
    {
        cout<<"Base的析构函数"<<endl;
    }
};

class Son:public Base
{
public:
    Son()
    {
        cout<<"Son的构造函数"<<endl;
    }
    ~Son()
    {
        cout<<"Son的析构函数"<<endl;
    }
}; 

void test01()
{
    //Base b;

    Son s;
    
}

int main()
{
    test01();
}