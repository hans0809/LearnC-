#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
//#include "employee.h"
//#include "manager.h"
//#include "boss.h"

int main()
{
	////���Զ�̬����
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "��˹", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "����",3);
	//worker->showInfo();
	//delete worker;

	//ʵ����һ�������߶���
	WorkerManager wm;

	int choice = 0;//�����洢�û���ѡ��

	while (true)
	{
		//����չʾ�˵��ĳ�Ա����
		wm.Show_Menu();
		cout << "���������ѡ��:" << endl;
		cin >> choice;//�����û���ѡ��

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://����ְ��
			wm.add_emp();
			break;
		case 2://��ʾְ��
			wm.ShowEmp();
			break;
		case 3://ɾ��ְ��
		{
			wm.Del_Emp();
			break;
		}
		//{
		//	//����
		//	int ret = wm.IsExist(5);//5��ְ���治����
		//	if (ret != -1)
		//	{
		//		cout << "ְ������" << endl;
		//	}
		//	else
		//	{
		//		cout << "ְ��������" << endl;
		//	}
		//	break;
		//}
		case 4://�޸�ְ��
			wm.Modify_Emp();
			break;
		case 5://����ְ��
			wm.FindEmp();
			break;
		case 6://����ְ��
			wm.SortEmp();
			break;
		case 7://����ĵ�
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