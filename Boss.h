#pragma once
#include<string>
#include"worker.h"
using namespace std;


class Boss : public Worker {
public:
	Boss(string number, string name, int position);

	virtual void showInfo();//��ȡ������Ϣ

	virtual string getDeptName();//��ȡ��λ����

	~Boss();
};