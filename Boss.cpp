#include"Boss.h"

Boss::Boss(string name, string id, int deptId) {
	m_Name = name;
	m_Id = id;
	m_DeptId = deptId;
}

void Boss::showInfo()//��ȡ������Ϣ
{
	cout << "����:" << m_Name
		<< "\tְ�����:" << m_Id
		<< "\t���ű��:" << m_DeptId
		<< "\t��λְ���ǹ���˾��������"
		<< endl;
}

string Boss::getDeptName()//��ȡ��λ����
{
	return string("�ϰ�");
}

Boss::~Boss() { //����

}