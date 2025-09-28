#pragma once

#include<iostream>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"

#define FILENAME "empFile.txt"

using namespace std;

class workerManager {
public:
	workerManager();

	//��¼��Ϣ����
	int m_number;

	//worker*�����ְ����Ϣ
	Worker** m_WkArray;

	//��־�����Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ִ������
	int getEmpNum();

	//�˳�����
	void exitSystem();

	//�˵���ʾ����
	void show_Menu();

	//���ְ������
	void addWorker();

	//�����ļ�
	void save();

	//��ʼ��ְ����Ϣ
	void Init_emp();

	//��ʾְ��
	void show_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(string id);

	//ɾ��Ա��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//��������ĵ�
	void Clean_File();
	~workerManager();
};