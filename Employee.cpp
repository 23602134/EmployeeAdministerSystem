#include"Employee.h"

Employee::Employee(string name,string id,int deptId) {
	m_Name = name;
	m_Id = id;
	m_DeptId = deptId;
}

void Employee::showInfo()//��ȡ������Ϣ
{
	cout << "����:" << m_Name 
		<< "\tְ�����:" << m_Id 
		<< "\t���ű��:" << m_DeptId 
		<< "\t��λְ������ɾ����ŵ�����" 
		<< endl;
}

string Employee::getDeptName()//��ȡ��λ����
{
	return string("��ͨԱ��");
}

//Employee::~Employee() {
//
//}