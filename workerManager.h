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

	//记录信息人数
	int m_number;

	//worker*数组存职工信息
	Worker** m_WkArray;

	//标志数组是否为空
	bool m_FileIsEmpty;

	//统计现存表人数
	int getEmpNum();

	//退出函数
	void exitSystem();

	//菜单显示函数
	void show_Menu();

	//添加职工函数
	void addWorker();

	//保存文件
	void save();

	//初始化职工信息
	void Init_emp();

	//显示职工
	void show_Emp();

	//判断职工是否存在
	int IsExist(string id);

	//删除员工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//清空所有文档
	void Clean_File();
	~workerManager();
};