#include"Manager.h"


Manager::Manager(string name, string id, int deptId) {
	m_Name = name;
	m_Id = id;
	m_DeptId = deptId;
}

void Manager::showInfo()//��ȡ������Ϣ
{
	cout << "����:" << m_Name
		<< "\tְ�����:" << m_Id
		<< "\t���ű��:" << m_DeptId
		<< "\t��λְ���ǽ����ϰ尲�ŵ����񣬲��·���Ա����"
		<< endl;
}

string Manager::getDeptName()//��ȡ��λ����
{
	return string("����");
}


Manager::~Manager() { //����
	
}
