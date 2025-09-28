#include"Boss.h"

Boss::Boss(string name, string id, int deptId) {
	m_Name = name;
	m_Id = id;
	m_DeptId = deptId;
}

void Boss::showInfo()//获取个人信息
{
	cout << "姓名:" << m_Name
		<< "\t职工编号:" << m_Id
		<< "\t部门编号:" << m_DeptId
		<< "\t岗位职责是管理公司所有事务。"
		<< endl;
}

string Boss::getDeptName()//获取岗位名称
{
	return string("老板");
}

Boss::~Boss() { //析构

}