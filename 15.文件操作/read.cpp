#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01()
{
    ifstream ifs;
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    //读取数据的4种方法
    //1.
    char buf[1024]={0};
    while(ifs>>buf)
    {
        cout<<buf<<endl;
    }

    //2.
    char buf1[1024]={0};
    while(ifs.getline(buf1, sizeof(buf1)))
    {
        cout<<buf1<<endl;
    }

    //3. 
    string buf3;
    while(getline(ifs,buf3))
    {
        cout<<buf3<<endl;
    }

    //4.
    char c;
    while((c=ifs.get())!=EOF)
    {
        cout<<c<<endl;
    }



    ifs.close();
}
int main()
{
    test01();
}