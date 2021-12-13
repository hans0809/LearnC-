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
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_empnum;

	//ְ�������ָ��
	Worker** m_emparray;

	//���ְ��
	void add_emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool isEmpty;

	//ͳ���ļ��е�����
	int  get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void ShowEmp();


	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڣ����������±꣬���򷵻�-1
	int IsExist(int d);

	//�޸�ְ��
	void Modify_Emp();

	//����Ա��
	void FindEmp();

	//����ְ����Ž�������
	void SortEmp();

	//����ļ�
	void CleanFile();

	//��������
	~WorkerManager();

};