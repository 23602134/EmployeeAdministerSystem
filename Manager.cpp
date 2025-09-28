#include"Manager.h"


Manager::Manager(string name, string id, int deptId) {
	m_Name = name;
	m_Id = id;
	m_DeptId = deptId;
}

void Manager::showInfo()//获取个人信息
{
	cout << "姓名:" << m_Name
		<< "\t职工编号:" << m_Id
		<< "\t部门编号:" << m_DeptId
		<< "\t岗位职责是接收老板安排的任务，并下发给员工。"
		<< endl;
}

string Manager::getDeptName()//获取岗位名称
{
	return string("经理");
}


Manager::~Manager() { //析构
	
}
