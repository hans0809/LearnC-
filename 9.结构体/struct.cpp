#include <iostream>
using namespace std;
#include <string>

//ѧ���Ľṹ��
struct Student
{
    //��Ա�б�
    string name;
    int age;
    int score;
};

//��ַ����
//�������е��βθ�Ϊָ�룬���Լ����ڴ�ռ䣬���Ҳ��ḳֵ�µĸ�������
void printStu2(const struct Student *s)
{
    //s->age=12;//�Ƿ�����
    cout<<s->name<<s->age<<s->score<<endl;
}
int main()
{
    struct Student s={"Bob",13,89};
    printStu2(&s);//Bob1289
}