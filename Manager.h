#pragma once
#include<string>
#include"worker.h"

using namespace std;

class Manager : public Worker {
public:
	Manager(string number, string name, int position);

	virtual void showInfo();//获取个人信息

	virtual string getDeptName();//获取岗位名称

	~Manager();
};