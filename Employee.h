
#pragma once
#include<string>
#include"worker.h"
using namespace std;



class Employee : public Worker {
public:
	Employee(string name, string id, int deptId);

	virtual void showInfo();//获取个人信息

	virtual string getDeptName();//获取岗位名称

	~Employee();
};


