
#pragma once
#include<string>
#include"worker.h"
using namespace std;



class Employee : public Worker {
public:
	Employee(string name, string id, int deptId);

	virtual void showInfo();//��ȡ������Ϣ

	virtual string getDeptName();//��ȡ��λ����

	~Employee();
};


