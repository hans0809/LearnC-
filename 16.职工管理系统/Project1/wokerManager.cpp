#include "workerManager.h"


//类外实现构造函数
WorkerManager::WorkerManager()
{
    //文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//读文件
    if (!ifs.is_open())
    {
        //cout << "文件不存在" << endl;
        //初始化记录人数为0
        this->m_empnum = 0;
        //初始化数组指针
        this->m_emparray = NULL;
        this->isEmpty = true;
        ifs.close();
        return;
    }
    //文件存在，但内容为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //文件为空
        //cout << "文件为空" << endl;
        //初始化记录人数为0
        this->m_empnum = 0;
        //初始化数组指针
        this->m_emparray = NULL;
        this->isEmpty = true;
        ifs.close();
        return;
    }

    //文件存在且内容不为空
    int num = this->get_EmpNum();
    //cout << "职工人数为：" << num << endl;
    this->m_empnum = num;

    //开辟空间
    this->m_emparray = new Worker * [this->m_empnum];
    //将文件中的数据，存到数组中
    this->init_Emp();
    ////测试代码，打印文件中的数据
    //for (int i = 0;i < this->m_empnum;i++)
    //{
    //    cout << "职工编号：" << this->m_emparray[i]->m_id << "  "
    //        << "职工姓名：" << this->m_emparray[i]->m_name<< "  "
    //        << "部门编号：" << this->m_emparray[i]->m_dept_id<< "  " << endl;

    //}

}



////展示菜单
void WorkerManager::Show_Menu() {
    cout << "************************" << endl;
    cout << "** 欢迎使用职工管理系统! **" << endl;
    cout << "***** 0.退出管理程序 *****" << endl;
    cout << "***** 1.增加职工信息 *****" << endl;
    cout << "***** 2.显示职工信息 *****" << endl;
    cout << "***** 3.删除离职职工 *****" << endl;
    cout << "***** 4.修改职工信息 *****" << endl;
    cout << "***** 5.查找职工信息 *****" << endl;
    cout << "***** 6.按照编号排序 *****" << endl;
    cout << "***** 7.清空所有文档 *****" << endl;
    cout << "************************" << endl;
}


//退出系统
void WorkerManager::ExitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

//添加职工
void WorkerManager::add_emp()
{
    cout << "请输入要添加的职工数量：" << endl;
    int addnum = 0;
    cin >> addnum;

    if (addnum > 0)
    {
        //添加
        //计算新空间的大小
        int newsize = this->m_empnum + addnum;//新空间人数=原来空间人数+新添加人数

        //开辟新空间
        Worker **newspace=new Worker* [newsize];//二级指针

        //将原来空间下的数据，拷贝到新的空间中
        if (this->m_emparray != NULL)
        {
            for (int i = 0;i < this->m_empnum;i++)
            {
                newspace[i] = this->m_emparray[i];
            }
        }
        //添加新数据
        for (int i = 0;i < addnum;i++)
        {
            int id;//职工编号
            string name;//职工姓名
            int dSelect;//部门选择

            cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
            cin >> name;
            cout << "请选择该职工的岗位：" << endl;
            cout << "1.普通职工"<<endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 1);
                break;
            case 3:
                worker = new Boss(id, name, 1);
                break;
            default:
                break;
            }
            //将创建职工职责，保存到数组中
            newspace[this->m_empnum + i] = worker;

        }
        //释放原有空间
        delete[] this->m_emparray;

        //更改新空间的指向
        this->m_emparray = newspace;

        //更新新的职工人数
        this->m_empnum = newsize;

        //更新职工不为空的标志
        this->isEmpty = false;

        //提示添加成功
        cout << "成功添加" << addnum << "名新的职工" << endl;
        
        //保存数据到文件中
        this->save();
    }
    else
    {
        cout << "输入有误" << endl;
    }

    //按任意键清屏，回上一目录
    system("pause");
    system("cls");
}



//保存文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);//用输出的方式打开文件--写文件

    //将每个人的数据写入到文件中
    for (int i = 0;i < this->m_empnum;i++)
    {
        ofs << this->m_emparray[i]->m_id << " "
            << this->m_emparray[i]->m_name << " "
            << this->m_emparray[i]->m_dept_id << endl;
    }

    //关闭文件
    ofs.close();
}

//统计文件中的人数
int  WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;//总人数
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker* worker = NULL;
        if (dId == 1)//普通职工
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)//经理
        {
            worker = new Manager(id, name, dId);

        }
        else//老板
        {
            worker = new Boss(id, name, dId);
        }

        this->m_emparray[index] = worker;
        index++;
    }
    //关闭文件
    ifs.close();
}

//显示职工
void WorkerManager::ShowEmp()
{
    //判断文件是否为空
    if (this->isEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
    }
    else
    {
        for (int i = 0;i < m_empnum;i++)
        {
            //利用多态调用接口
            this->m_emparray[i]->showInfo();
        }
    }
    //按任意键清屏
    system("pause");
    system("cls");
}

//删除职工
void WorkerManager::Del_Emp()
{
    if (this->isEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
    }
    else
    {
        //按照职工编号进行删除
        cout << "请输入要删除的员工编号：" << endl;
        int id = 0;
        cin >> id;
        int index = this->IsExist(id);
        if (index != -1)
        {
            //找到了，开始删除
            for (int i = index;i < this->m_empnum - 1;i++)
            {
                this->m_emparray[i] = this->m_emparray[i + 1];
            }
            this->m_empnum--;

            //同步更新到文件中
            this->save();

            cout << "删除成功" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
        }
    }

    //按任意键清屏
    system("pause");
    system("cls");
}

//判断职工是否存在，如果存在，返回所在下标，否则返回-1
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i=0;i < this->m_empnum;i++)
    {
        if (this->m_emparray[i]->m_id == id)
        {
            index = i;//找到了
            break;
        }
    }
    return index;
}

//修改职工
void WorkerManager::Modify_Emp()
{
    if (this->isEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
    }
    else
    {
        cout << "请输入要修改的职工的编号：" << endl;
        int id;
        cin >> id;
        int ret=this->IsExist(id);
        if (ret != -1)
        {
            //找到了，开始修改
            delete this->m_emparray[ret];
            int newId = 0;//新的id
            string newName;//新的名字
            int dSelect = 0;//新的部门

            cout << "查到" << id << "号职工，请输入新的职工号：" << endl;
            cin >> newId;

            cout << "请输入新的姓名：" << endl;
            cin >> newName;

            cout << "请输入新的岗位：" << endl;
            cout << "1.普通岗位\n2.经理\n3.老板" <<endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            }

            //更新数据到数组中
            this->m_emparray[ret] = worker;
            cout << "修改成功！" << endl;

            //保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
    }

    //按任意键清屏
    system("pause");
    system("cls");
}

//查找员工
void WorkerManager::FindEmp()
{
    if (this->isEmpty)
    {
        cout << "文件不存在或者记录为空" <<endl;
    }
    else
    {
        cout << "请输入查找的方式：" <<endl;
        cout << "1.按照职工编号查找\n2.按照职工姓名查找" << endl;

        int select = 0;
        cin >> select;
        if (select == 1)
        {
            //按照编号查
            int id;
            cout << "请输入要查找的职工编号：" << endl;
            cin >> id;

            int ret = this->IsExist(id);
            if (ret != -1)
            {
                cout << "查找成功!该职工的信息如下：" << endl;
                this->m_emparray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if (select == 2)
        {
            //按姓名查
            string name;
            cout << "请输入要查找的职工姓名：" << endl;
            cin >> name;
            
            //加入判断是否查到的标志
            bool flag = false;//默认没找到

            for (int i = 0;i < m_empnum;i++)
            {
                if (this->m_emparray[i]->m_name == name)
                {
                    cout << "查找成功！，职工编号为："
                        << this->m_emparray[i]->m_id
                        << "号职工的信息如下：" << endl;
                    flag = true;
                    //调用显示信息的接口
                    this->m_emparray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "输入有误" << endl;
        }
    }
    //按任意键清屏
    system("pause");
    system("cls");
}

//按照职工编号进行排序
void WorkerManager::SortEmp()
{
    if (this->isEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
        //按任意键清屏
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序的方式”\n1. 按照职工号升序\n2.按照职工号降序" << endl;

        int select = 0;
        cin >> select;

        //选择排序
        for (int i = 0;i < this->m_empnum-1;i++)
        {
            int minOrMax = i;//声明当前最小值或最大值的下标
            for (int j = i + 1;j < this->m_empnum;j++)
            {
                if (select == 1)//升序
                {
                    if (this->m_emparray[minOrMax]->m_id > this->m_emparray[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }
                else//降序
                {
                    if (this->m_emparray[minOrMax]->m_id < this->m_emparray[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }

            }
            if (i != minOrMax)
            {
                Worker * temp = this->m_emparray[i];
                this->m_emparray[i] = this->m_emparray[minOrMax];
                this->m_emparray[minOrMax] = temp;
            }
        }
        cout << "排序成功！排序后的结果为：" << endl;
        this->save();//排序结果保存到文件中
        this->ShowEmp();//展示排序后的职工信息

    }
}

//清空文件
void WorkerManager::CleanFile()
{
    cout << "确认清空吗？\n1.是的 2.不是" <<endl;
    int select=0;
    cin >> select;
    if (select == 1)//确定
    {
        //清空文件
        ofstream ofs(FILENAME, ios::trunc);//trunc:删除文件后重新创建
        ofs.close();

        if (this->m_emparray != NULL)
        {
            //删除堆区的每个职工对象
            for (int i = 0;i < m_empnum;i++)
            {
                delete this->m_emparray[i];
                this->m_emparray[i] = NULL;
            }

            //删除堆区的数组指针
            delete[]this->m_emparray;
            this->m_emparray = NULL;
            this->m_empnum = 0;
            this->isEmpty = true;
            cout << "清空成功！" << endl;
        }
    }
    system("pause");
    system("cls");


}

//类外实现析构函数
WorkerManager::~WorkerManager()
{
    if (this->m_emparray != NULL)
    {
        for (int i = 0;i < this->m_empnum;i++)
        {
            if (this->m_emparray[i] != NULL)
            {
                delete this->m_emparray[i];
            }
        }
        delete[] this->m_emparray;
        this->m_emparray = NULL;
    }
}