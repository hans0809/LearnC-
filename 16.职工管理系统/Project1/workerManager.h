#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_empnum;

	//职工数组的指针
	Worker** m_emparray;

	//添加职工
	void add_emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool isEmpty;

	//统计文件中的人数
	int  get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void ShowEmp();


	//删除职工
	void Del_Emp();

	//判断职工是否存在，如果存在，返回所在下标，否则返回-1
	int IsExist(int d);

	//修改职工
	void Modify_Emp();

	//查找员工
	void FindEmp();

	//按照职工编号进行排序
	void SortEmp();

	//清空文件
	void CleanFile();

	//析构函数
	~WorkerManager();

};