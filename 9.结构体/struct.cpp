#include <iostream>
using namespace std;
#include <string>

//学生的结构体
struct Student
{
    //成员列表
    string name;
    int age;
    int score;
};

//地址传递
//将函数中的形参改为指针，可以减少内存空间，而且不会赋值新的副本出来
void printStu2(const struct Student *s)
{
    //s->age=12;//非法！！
    cout<<s->name<<s->age<<s->score<<endl;
}
int main()
{
    struct Student s={"Bob",13,89};
    printStu2(&s);//Bob1289
}