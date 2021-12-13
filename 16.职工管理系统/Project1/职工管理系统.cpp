#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
//#include "employee.h"
//#include "manager.h"
//#include "boss.h"

int main()
{
	////测试多态代码
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "里斯", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五",3);
	//worker->showInfo();
	//delete worker;

	//实例化一个管理者对象
	WorkerManager wm;

	int choice = 0;//用来存储用户的选项

	while (true)
	{
		//调用展示菜单的成员函数
		wm.Show_Menu();
		cout << "请输入你的选择:" << endl;
		cin >> choice;//接收用户的选项

		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://增加职工
			wm.add_emp();
			break;
		case 2://显示职工
			wm.ShowEmp();
			break;
		case 3://删除职工
		{
			wm.Del_Emp();
			break;
		}
		//{
		//	//测试
		//	int ret = wm.IsExist(5);//5号职工存不存在
		//	if (ret != -1)
		//	{
		//		cout << "职工存在" << endl;
		//	}
		//	else
		//	{
		//		cout << "职工不存在" << endl;
		//	}
		//	break;
		//}
		case 4://修改职工
			wm.Modify_Emp();
			break;
		case 5://查找职工
			wm.FindEmp();
			break;
		case 6://排序职工
			wm.SortEmp();
			break;
		case 7://清空文档
			wm.CleanFile();
			
			break;
		default:
			system("cls");
			break;
		}
	}







	system("pause");
	return 0;
}