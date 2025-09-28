#include"workerManager.h"


workerManager::workerManager() {
	//��ʼ���ļ��ִ�����Ϊ0
	this->m_number = 0;
	//��ʼ��workerΪ��ָ��
	this->m_WkArray = NULL;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	//����ļ�������
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_number = 0; //��ʼ������Ϊ0
		this->m_WkArray = NULL;  //��ʼ������Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->m_number = 0; //��ʼ������Ϊ0
		this->m_WkArray = NULL;  //��ʼ������Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�����������Ϣ
	int num = this->getEmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_number = num;//��������


	//��������Ա��������������
	this->m_WkArray = new Worker*[this->m_number];
	//���Ŷ�Ա�����г�ʼ��
	this->Init_emp();


}


//ͳ���ִ������
int workerManager::getEmpNum() {
	string Id;//ְ�����
	string Name;//����
	int DeptId;//���ű��

	int num = 0;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	while (ifs >> Id and ifs >> Name and ifs >> DeptId) {
		num++;//����һ����Ϣ��+1
	}

	return num;
}


//�˳�����
void workerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}


//�˵���ʾ����
void workerManager::show_Menu() {
	cout << "*************************************************" << endl;
	cout << "**************��ӭʹ��ְ������ϵͳ***************" << endl;
	cout << "*****************0-�˳��������******************" << endl;
	cout << "*****************1-���ְ����Ϣ******************" << endl;
	cout << "*****************2-��ʾְ����Ϣ******************" << endl;
	cout << "*****************3-ɾ����ְְ��******************" << endl;
	cout << "*****************4-�޸�ְ����Ϣ******************" << endl;
	cout << "*****************5-����ְ����Ϣ******************" << endl;
	cout << "*****************6-��������ĵ�******************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}


//��ʼ��Ա��
void workerManager::Init_emp() {
	//���ȶ����ļ���Ϣ
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string Id;//Ա�����
	string name;
	int dId;//���ű��

	Worker* worker = NULL;

	int index = 0;//��¼�����±�
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
		//����ȡ��ֵ��ֵ��m_WkArrayָ��������
		this->m_WkArray[index] = worker;
		index++;
	}

	ifs.close();

	
}


//���ְ������
void workerManager::addWorker() {

		int count = 0;
		cout << "������Ҫ��ӵ�ְ��������";
		cin >> count;

		//����Worker_num����ѭ������
		//дһ��ѭ�����ֱ����Ա����ţ���������λ������

		if (count > 0) {

			//�����ִ�����
			int newCount = count + this->m_number;
			//�����¿ռ�
			Worker** newSpace = new Worker*[newCount];
			//�������ݸ�ֵ���¿ռ�
			if (this->m_WkArray != NULL) {
				for (int i = 0; i < this->m_number; i++) {
					newSpace[i] = this->m_WkArray[i];
				}
			}

			for (int i = 0; i < count; i++) {

				string id;//ְ�����
				string name;//����
				int position;//��λ

				cout << "�������" << i + 1 << "��ְ���ı�ţ�";
				cin >> id;
				cout << "������ְ������:";
				cin >> name;
				cout << "��ѡ���ְ���ĸ�λ:" << endl;
				cout << "1-��ͨԱ��" << endl;
				cout << "2-����" << endl;
				cout << "3-�ϰ�" << endl;
				cin >> position;

				Worker* nw = NULL;

				switch (position) {

				case 1: {     //1 �չ���
					//ʵ��������,�ڶ��������ڴ�,�������ʵ��ɾ������
					nw = new Employee(name, id, 1);
					break;
				}

				case 2://2 ������
				{
					//ʵ��������,��ջ�Ͽ����ڴ�,�������ʵ��ɾ������
					nw = new Manager(name, id, 2);
					break;
				}

				case 3://3 �ϰ���
				{
					//ʵ��������,��ջ�Ͽ����ڴ�,�������ʵ��ɾ������
					nw = new Boss(name, id, 3);
					break;
				}

				default:
					cout << "�����ڴ˸�λ��������1~3������" << endl;
					break;
				}

				//���������ֵ��ӵ�worker*�����ĩβ
				newSpace[this->m_number + i] = nw;
			}
			
			//�ͷ�ԭ�пռ�
			delete[] this->m_WkArray;
			//����ָ��ָ��
			this->m_WkArray = newSpace;
			//������������
			this->m_number = newCount;

			cout << "�ɹ����" << count << "��ְ����" << endl;

			//�����ļ�
			this->save();
		}
		else {
			cout << "���������0������" << endl;
		}
}


//�����ļ�����
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


//��ʾְ��
void workerManager::show_Emp() {
	//ˢ���ļ�
	this->save();
	//�ж��ļ��Ƿ�Ϊ��

	if (this->m_FileIsEmpty) {
		cout << "�ļ�Ϊ�գ������ְ��" << endl;
	}
	else {
		for (int i = 0; i < m_number; i++) {
			this->m_WkArray[i]->showInfo();
		}
	}
}


//�ж�ְ���Ƿ����,���ڷ��������±꣬��֮����-1
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


//ɾ��ְ������(����ɾ��)
void workerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ��Ѿ�Ϊ�գ��޷�ɾ��" << endl;
	}
	else {
		string id;
		cout << "������Ҫɾ����ְ�����:";
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {  //ְ������,��Ҫɾ��indexλ���ϵ�������Ϣ
			for (int i = index; i < this->m_number-1; i++) {
				this->m_WkArray[i] = this->m_WkArray[i + 1];
			}
			this->m_number--;//������1
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "ְ�������ڣ���������ȷ��ְ����ţ�" << endl;
		}
	}
	if (this->m_number > 0) {

		//�����¿ռ�
		Worker** newSpace = new Worker * [this->m_number];
		//�������ݸ�ֵ���¿ռ�
		if (this->m_WkArray != NULL) {
			for (int i = 0; i < this->m_number; i++) {
				newSpace[i] = this->m_WkArray[i];
			}
		}
		delete[] this->m_WkArray;
		this->m_WkArray = newSpace;

		//�����ļ�
		this->save();
	}
}


//�޸�ְ����Ϣ
void workerManager::Mod_Emp() {

	if (this->m_FileIsEmpty) {
		cout << "�ļ�Ϊ��" << endl;
	}
	else {
		string id;
		cout << "������Ҫ�޸ĵ�ְ���ı�ţ�";
		cin >> id;

	//��ѯ�������Ƿ���ڴ�ְ��
		int ret = this->IsExist(id);

		//ְ������
		if (ret != -1) {
			string newId;//ְ�����
			string newName;//����
			int newPosition;//��λ
			cout << "�ҵ���ְ������" << endl;
			cout << "�������޸ĺ��ְ���ı�ţ�";
			cin >> newId;
			cout << "������ְ������:";
			cin >> newName;
			cout << "��ѡ���ְ���ĸ�λ:" << endl;
			cout << "1-��ͨԱ��" << endl;
			cout << "2-����" << endl;
			cout << "3-�ϰ�" << endl;
			cin >> newPosition;

			Worker* nw = NULL;

			switch (newPosition) {

			case 1: {     //1 �չ���
				//ʵ��������,�ڶ��������ڴ�,�������ʵ��ɾ������
				nw = new Employee(newName, newId, 1);
				break;
			}

			case 2://2 ������
			{
				//ʵ��������,��ջ�Ͽ����ڴ�,�������ʵ��ɾ������
				nw = new Manager(newName, newId, 2);
				break;
			}

			case 3://3 �ϰ���
			{
				//ʵ��������,��ջ�Ͽ����ڴ�,�������ʵ��ɾ������
				nw = new Boss(newName, newId, 3);
				break;
			}

			default:
				cout << "�����ڴ˸�λ��������1~3������" << endl;
				break;
			}
			//����Ϣ���µ�������
			this->m_WkArray[ret] = nw;
			cout << "�ɹ��޸ģ�" << endl;
		}
		else {   //ret == -1,��ְ��������
			cout << "��ְ�������ڣ�����ְ����Ż򰴡�0���˳�" << endl;
		}
		
	}
}


//����ְ��
void workerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ�Ϊ��" << endl;
	}
	else {
		//���԰���������ְ����š���λ���ַ�ʽ����
		cout << "���������ְ���ı�ţ�";
		string id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret == -1) {
			cout << "��ְ�������ڣ���������" << endl;
		}
		else {
			this->m_WkArray[ret]->showInfo();
		}
	}
}


//��������ĵ�
void workerManager::Clean_File() {
	cout << "�Ƿ�ȷ����������ĵ�������������������Ҫ���ݣ�" << endl;
	cout << "��---1\t��---0" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1) {
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//����ļ����ڣ���ɾ�������´���

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
		cout << "��ճɹ�" << endl;
	}
}


workerManager::~workerManager() {
	if (this->m_WkArray != NULL) {
		delete[] this->m_WkArray;
		this->m_WkArray = NULL;
	}
}