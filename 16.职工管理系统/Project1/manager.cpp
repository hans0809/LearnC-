#include "manager.h"

//构造函数
Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;;
	this->m_dept_id = dId;
}
//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t岗位" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并且下发任务给普通员工" << endl;
}
//获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}