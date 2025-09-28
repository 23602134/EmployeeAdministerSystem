#include"Employee.h"

Employee::Employee(string name,string id,int deptId) {
	m_Name = name;
	m_Id = id;
	m_DeptId = deptId;
}

void Employee::showInfo()//获取个人信息
{
	cout << "姓名:" << m_Name 
		<< "\t职工编号:" << m_Id 
		<< "\t部门编号:" << m_DeptId 
		<< "\t岗位职责是完成经理安排的任务。" 
		<< endl;
}

string Employee::getDeptName()//获取岗位名称
{
	return string("普通员工");
}

//Employee::~Employee() {
//
//}