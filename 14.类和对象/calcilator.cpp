#include <iostream>
#include <string>
using namespace std;

class AbstractCalculator
{
public:
    int m_num1,m_num2;
    virtual getResult()
    {
        return 0;
    }
};

//加法计算器类
class AddCalculator:public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1+m_num2;
    }
};
//减法计算器类
class SubCalculator:public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1-m_num2;
    }
};
//乘法计算器类
class MulCalculator:public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1*m_num2;
    }
};


void test02()
{

    //多态使用条件：父类的指针或引用指向子类对象

    //加法运算
    AbstractCalculator *abc=new AddCalculator;
    abc->m_num1=10;
    abc->m_num2=10;
    cout<<abc->m_num1<<"+"<<abc->m_num2<<"="<<abc->getResult()<<endl;//10+10=20

    //用完后要销毁
    delete abc;

    //减法运算
    abc=new SubCalculator;
    abc->m_num1=10;
    abc->m_num2=10;
    cout<<abc->m_num1<<"-"<<abc->m_num2<<"="<<abc->getResult()<<endl;//10-10=0

    //乘法运算
    abc=new MulCalculator;
    abc->m_num1=10;
    abc->m_num2=10;
    cout<<abc->m_num1<<"*"<<abc->m_num2<<"="<<abc->getResult()<<endl;//10*10=100


}

int main()
{
    test02();
}