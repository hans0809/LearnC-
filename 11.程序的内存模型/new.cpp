#include <iostream>
using namespace std;
int *func()
{
    //在堆区创建一个整型的数据
    //new返回的是该数据类型的指针
    int *p=new int(10);
    return p;
}

void test01()
{
    int *p=func();
    cout<<*p<<endl;
    cout<<*p<<endl;
    cout<<*p<<endl;
    delete p;//释放内存
    cout<<*p<<endl;
}

void test02()
{
    //创建一个数组，数组中有10个元素
    int *arr=new int[10];
    for (int i=0;i<10;i++)
    {
        arr[i]=i+100;//给0个元素赋值
    }
    for (int i=0;i<10;i++)
    {
        cout<<arr[i]<<endl;//给0个元素赋值
    }
    delete[] arr;//释放数组内存
}
int main()
{
    test01();
    /*
    10
    10
    10
    38941856//内存已经被释放了，再次运行是错的
    */

    test02();
    /*
    100
    101
    102
    103
    104
    105
    106
    107
    108
    109
    */
}