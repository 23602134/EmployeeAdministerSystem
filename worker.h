#pragma once
//�����๫˾��������λ
#include<iostream>
#include<string>
using namespace std;

class Worker {
public:
	string m_Id;//ְ�����
	string m_Name;//����
	int m_DeptId;//���ű��

	virtual void showInfo() = 0;//��ȡ������Ϣ

	virtual string getDeptName() = 0;//��ȡ��λ����

	~Worker() {
		
	}

};

