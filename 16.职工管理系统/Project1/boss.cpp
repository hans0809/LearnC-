#include "boss.h"

//���캯��
Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;;
	this->m_dept_id = dId;
}
//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ�����" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\t��λ" << this->getDeptName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}
//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ܲ�");
}