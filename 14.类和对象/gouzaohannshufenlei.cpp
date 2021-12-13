#include <iostream>
using namespace std;

class Person
{
public:
    //普通构造

    //无参构造
    Person()
    {
        cout<<"Person的无参构造函数的调用"<<endl;
    }
    //有参构造
    Person(int a)
    {
        age=a;
        cout<<"Person的有参构造函数的调用"<<endl;
    }

    //拷贝构造函数:将一个对象中的所有属性复制给自己一份
    Person(const Person &p)
    {
        cout<<"Person的拷贝构造函数的调用"<<endl;
        age=p.age;
    }

    ~Person()
    {
        cout<<"Person析构函数的调用"<<endl;
    }

    int age;
};

//构造函数的调用
void test01()
{
    //1.括号法
    Person p1;//默认(无参)构造函数的调用
    Person p2(10);//有参构造函数的调用
    Person p3(p2);//拷贝构造函数的调用
    cout<<"p2的年龄为："<<p2.age<<endl;//10
    cout<<"p3的年龄为："<<p3.age<<endl;//10

    //注意：在进行默认规则时，不要加()，一位内编译器会把它当成函数声明

    //2.显示法，有点像Python，只是前面需要加类名Person，就像定义变量时需要指定数据类型一样
    Person p4;//无参构造
    Person p5=Person(10);//有参构造 
    Person p6=Person(p5);//拷贝构造

    Person(10);//匿名对象，即上面等号的右侧。当前执行结束后，系统会立即回收掉匿名对象(运行可以看到，析构函数被调用后才打印下面的句子)
    cout<<"匿名对象执行"<<endl;

    //注意：不要使用拷贝构造函数初始化匿名对象
    //因为编译器会认为Person(p6) <==> Person p6; 对象声明重复了
    //Person(p6);

    //3. 隐式转换法
    Person p7=10;//相当于Person p7=Person(10),有参构造
    Person p8=p7;//拷贝构造

    

}
int main()
{
    test01();
}