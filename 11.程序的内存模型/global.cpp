#include <iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//const修饰的全局变量，即全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
    //全局区

    //全局变量、静态变量、常量

    //创建普通局部变量
    int a = 10;
    int b = 10;
    cout << "局部变量a的地址：" << (long long int)&a << endl;
    cout << "局部变量b的地址：" << (long long int)&b << endl;
    
    cout << "全局变量g_a的地址：" << (long long int)&g_a << endl;
    cout << "全局变量g_b的地址：" << (long long int)&g_b << endl;

    //静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a的地址" << (long long int)&s_a << endl;
    cout << "静态变量s_b的地址：" << (long long int)&s_b << endl;

    //局部常量
    //1.字符串常量
    cout << "字符串处理的地址：" << (long long int)&"hello world" << endl;

    //2.const修饰的变量

    //2.1 const修饰的全局变量
    cout << "const修饰的全局变量，即全局常量c_g_a的地址：" << (long long int)&c_g_a << endl;
    cout << "const修饰的全局变量，即全局常量c_g_b的地址：" << (long long int)&c_g_b << endl;

    //2.2 cosnt修饰的局部变量，即局部常量
    const int c_l_a = 10;
    const int c_l_b = 10;

    cout << "cosnt修饰的局部变量，即局部常量c_l_a的地址："<< (long long int)&c_l_a << endl;
    cout << "cosnt修饰的局部变量，即局部常量c_l_b的地址："<< (long long int)&c_l_b << endl;
}