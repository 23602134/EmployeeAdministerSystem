#pragma once
//抽象类公司的三个岗位
#include<iostream>
#include<string>
using namespace std;

class Worker {
public:
	string m_Id;//职工编号
	string m_Name;//姓名
	int m_DeptId;//部门编号

	virtual void showInfo() = 0;//获取个人信息

	virtual string getDeptName() = 0;//获取岗位名称

	~Worker() {
		
	}

};

