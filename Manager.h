#pragma once
#include<string>
#include"worker.h"

using namespace std;

class Manager : public Worker {
public:
	Manager(string number, string name, int position);

	virtual void showInfo();//��ȡ������Ϣ

	virtual string getDeptName();//��ȡ��λ����

	~Manager();
};