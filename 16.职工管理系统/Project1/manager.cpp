#include "manager.h"

//���캯��
Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;;
	this->m_dept_id = dId;
}
//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ�����" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\t��λ" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲����·��������ͨԱ��" << endl;
}
//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}