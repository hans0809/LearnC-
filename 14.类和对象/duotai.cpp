#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
    //虚函数
    virtual void speak()
    {
        cout<<"动物在说话"<<endl;
    }
};

//猫类
class Cat:public Animal
{
public:
   
    void speak()
    {
        cout<<"小猫在说话"<<endl;
    }
};
//狗类
class Dog:public Animal
{
public:
   
    void speak()
    {
        cout<<"小狗在说话"<<endl;
    }
};

//说话

//地址早绑定，在编译阶段就确定了函数的地址
//如果想让猫说话，那么这个函数地址不能提前绑定，需要在运行阶段进行别的，即地址晚绑定
void DoSpeak(Animal& animal)//Animal& annmal ==> cat
{
    animal.speak();
}

void test01()
{
    Cat cat;
    DoSpeak(cat);//小猫在说话

    Dog dog;
    DoSpeak(dog);//小狗在说话

    dog.speak();//小狗在说话
}

int main()
{
    test01();
}