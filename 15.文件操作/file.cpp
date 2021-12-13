#include <iostream>
#include <fstream>
using namespace std;

void test01()
{
    ofstream ofs;
    ofs.open("test.txt",ios::out);
    ofs<<"姓名：张三"<<endl;
    ofs<<"姓名：dj "<<endl;
    ofs<<"姓名：jdhduduhhud低价"<<endl;
    ofs.close();
}
//文本文件 写文件
int main()
{
    test01();
}
