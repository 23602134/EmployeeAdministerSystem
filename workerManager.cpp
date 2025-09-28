#include"workerManager.h"


workerManager::workerManager() {
	//初始化文件现存人数为0
	this->m_number = 0;
	//初始化worker为空指针
	this->m_WkArray = NULL;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	//如果文件不存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_number = 0; //初始化人数为0
		this->m_WkArray = NULL;  //初始化数组为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_number = 0; //初始化人数为0
		this->m_WkArray = NULL;  //初始化数组为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且有信息
	int num = this->getEmpNum();
	cout << "职工个数为：" << num << endl;
	this->m_number = num;//更新人数


	//根据现有员工数量创建数组
	this->m_WkArray = new Worker*[this->m_number];
	//接着对员工进行初始化
	this->Init_emp();


}


//统计现存表人数
int workerManager::getEmpNum() {
	string Id;//职工编号
	string Name;//姓名
	int DeptId;//部门编号

	int num = 0;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	while (ifs >> Id and ifs >> Name and ifs >> DeptId) {
		num++;//读完一行信息就+1
	}

	return num;
}


//退出函数
void workerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	exit(0);
}


//菜单显示函数
void workerManager::show_Menu() {
	cout << "*************************************************" << endl;
	cout << "**************欢迎使用职工管理系统***************" << endl;
	cout << "*****************0-退出管理程序******************" << endl;
	cout << "*****************1-添加职工信息******************" << endl;
	cout << "*****************2-显示职工信息******************" << endl;
	cout << "*****************3-删除离职职工******************" << endl;
	cout << "*****************4-修改职工信息******************" << endl;
	cout << "*****************5-查找职工信息******************" << endl;
	cout << "*****************6-清空所有文档******************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}


//初始化员工
void workerManager::Init_emp() {
	//首先读入文件信息
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string Id;//员工编号
	string name;
	int dId;//部门编号

	Worker* worker = NULL;

	int index = 0;//记录数组下标
	while (ifs >> name and ifs >> Id and ifs >> dId) {
		
		if (dId == 1) {
			worker = new Employee(name, Id, 1);
		}
		else if (dId == 2) {
			worker = new Manager(name, Id, 2);
		}
		else {
			worker = new Boss(name, Id, 3);
		}
		//将读取的值赋值到m_WkArray指针数组中
		this->m_WkArray[index] = worker;
		index++;
	}

	ifs.close();

	
}


//添加职工函数
void workerManager::addWorker() {

		int count = 0;
		cout << "请输入要添加的职工数量：";
		cin >> count;

		//根据Worker_num决定循环次数
		//写一个循环，分别进行员工编号，姓名，岗位的输入

		if (count > 0) {

			//计算现存人数
			int newCount = count + this->m_number;
			//开辟新空间
			Worker** newSpace = new Worker*[newCount];
			//将旧数据赋值到新空间
			if (this->m_WkArray != NULL) {
				for (int i = 0; i < this->m_number; i++) {
					newSpace[i] = this->m_WkArray[i];
				}
			}

			for (int i = 0; i < count; i++) {

				string id;//职工编号
				string name;//姓名
				int position;//岗位

				cout << "请输入第" << i + 1 << "个职工的编号：";
				cin >> id;
				cout << "请输入职工姓名:";
				cin >> name;
				cout << "请选择该职工的岗位:" << endl;
				cout << "1-普通员工" << endl;
				cout << "2-经理" << endl;
				cout << "3-老板" << endl;
				cin >> position;

				Worker* nw = NULL;

				switch (position) {

				case 1: {     //1 普工类
					//实例化对象,在堆区开辟内存,方便后续实现删除功能
					nw = new Employee(name, id, 1);
					break;
				}

				case 2://2 经理类
				{
					//实例化对象,在栈上开辟内存,方便后续实现删除功能
					nw = new Manager(name, id, 2);
					break;
				}

				case 3://3 老板类
				{
					//实例化对象,在栈上开辟内存,方便后续实现删除功能
					nw = new Boss(name, id, 3);
					break;
				}

				default:
					cout << "不存在此岗位，请输入1~3的数字" << endl;
					break;
				}

				//将新输入的值添加到worker*数组的末尾
				newSpace[this->m_number + i] = nw;
			}
			
			//释放原有空间
			delete[] this->m_WkArray;
			//更新指针指向
			this->m_WkArray = newSpace;
			//更新现有人数
			this->m_number = newCount;

			cout << "成功添加" << count << "名职工！" << endl;

			//保存文件
			this->save();
		}
		else {
			cout << "请输入大于0的数字" << endl;
		}
}


//保存文件函数
void workerManager::save() {

	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_number;i++) {

		ofs << this->m_WkArray[i]->m_Name << " ";
		ofs << this->m_WkArray[i]->m_Id << " ";
		ofs << this->m_WkArray[i]->m_DeptId << endl;
	}
	ofs.close();
}


//显示职工
void workerManager::show_Emp() {
	//刷新文件
	this->save();
	//判断文件是否为空

	if (this->m_FileIsEmpty) {
		cout << "文件为空，请添加职工" << endl;
	}
	else {
		for (int i = 0; i < m_number; i++) {
			this->m_WkArray[i]->showInfo();
		}
	}
}


//判断职工是否存在,存在返回数组下标，反之返回-1
int workerManager::IsExist(string id) {
	int index = -1;

	for (int i = 0; i < this->m_number; i++) {
		if (this->m_WkArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}


//删除职工函数(单次删除)
void workerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件已经为空，无法删除" << endl;
	}
	else {
		string id;
		cout << "请输入要删除的职工编号:";
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {  //职工存在,且要删除index位置上的数组信息
			for (int i = index; i < this->m_number-1; i++) {
				this->m_WkArray[i] = this->m_WkArray[i + 1];
			}
			this->m_number--;//人数减1
			cout << "删除成功！" << endl;
		}
		else {
			cout << "职工不存在，请输入正确的职工编号！" << endl;
		}
	}
	if (this->m_number > 0) {

		//开辟新空间
		Worker** newSpace = new Worker * [this->m_number];
		//将旧数据赋值到新空间
		if (this->m_WkArray != NULL) {
			for (int i = 0; i < this->m_number; i++) {
				newSpace[i] = this->m_WkArray[i];
			}
		}
		delete[] this->m_WkArray;
		this->m_WkArray = newSpace;

		//保存文件
		this->save();
	}
}


//修改职工信息
void workerManager::Mod_Emp() {

	if (this->m_FileIsEmpty) {
		cout << "文件为空" << endl;
	}
	else {
		string id;
		cout << "请输入要修改的职工的编号：";
		cin >> id;

	//查询数组中是否存在此职工
		int ret = this->IsExist(id);

		//职工存在
		if (ret != -1) {
			string newId;//职工编号
			string newName;//姓名
			int newPosition;//岗位
			cout << "找到此职工啦！" << endl;
			cout << "请输入修改后的职工的编号：";
			cin >> newId;
			cout << "请输入职工姓名:";
			cin >> newName;
			cout << "请选择该职工的岗位:" << endl;
			cout << "1-普通员工" << endl;
			cout << "2-经理" << endl;
			cout << "3-老板" << endl;
			cin >> newPosition;

			Worker* nw = NULL;

			switch (newPosition) {

			case 1: {     //1 普工类
				//实例化对象,在堆区开辟内存,方便后续实现删除功能
				nw = new Employee(newName, newId, 1);
				break;
			}

			case 2://2 经理类
			{
				//实例化对象,在栈上开辟内存,方便后续实现删除功能
				nw = new Manager(newName, newId, 2);
				break;
			}

			case 3://3 老板类
			{
				//实例化对象,在栈上开辟内存,方便后续实现删除功能
				nw = new Boss(newName, newId, 3);
				break;
			}

			default:
				cout << "不存在此岗位，请输入1~3的数字" << endl;
				break;
			}
			//将信息更新到数组中
			this->m_WkArray[ret] = nw;
			cout << "成功修改！" << endl;
		}
		else {   //ret == -1,即职工不存在
			cout << "该职工不存在，请检查职工编号或按“0”退出" << endl;
		}
		
	}
}


//查找职工
void workerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件为空" << endl;
	}
	else {
		//可以按照姓名、职工编号、岗位三种方式查找
		cout << "请输入查找职工的编号：";
		string id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret == -1) {
			cout << "该职工不存在，请检查输入" << endl;
		}
		else {
			this->m_WkArray[ret]->showInfo();
		}
	}
}


//清空所有文档
void workerManager::Clean_File() {
	cout << "是否确定清空所有文档？这里面可能有你的重要数据！" << endl;
	cout << "是---1\t否---0" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1) {
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//如果文件存在，则删除并重新创建

		if (this->m_WkArray != NULL) {
			for (int i = 0; i < this->m_number; i++) {
				if (this->m_WkArray[i] != NULL) {
					delete this->m_WkArray[i];
				}
			}
			delete[] this->m_WkArray;
			this->m_WkArray = NULL;
			this->m_number = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
}


workerManager::~workerManager() {
	if (this->m_WkArray != NULL) {
		delete[] this->m_WkArray;
		this->m_WkArray = NULL;
	}
}