#pragma once
#include<string>
#include"worker.h"
using namespace std;


class Boss : public Worker {
public:
	Boss(string number, string name, int position);

	virtual void showInfo();//获取个人信息

	virtual string getDeptName();//获取岗位名称

	~Boss();
};