#include"workerManager.h"


int main() {

	//����һ����˾����
	workerManager wm;

	while (1) {

		//��ʼ�˵�
		wm.show_Menu();

		int choice = 0;
		cout << "���������ѡ��:";
		cin >> choice;
		switch (choice) {
		case 0: //�˳�����
			wm.exitSystem();
			break;

		case 1://���ְ����Ϣ
			wm.addWorker();
			break;

		case 2://��ʾְ����Ϣ
			wm.show_Emp();
			break;

		case 3://ɾ����ְְ��
			wm.Del_Emp();
			break;

		case 4://�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;

		case 5://����ְ����Ϣ
			wm.Find_Emp();
			break;

		case 6://��������ĵ�
			wm.Clean_File();
			break;

		default:
			cout << "������0~7������" << endl;
			cout << "��Ҫ�˳���������0" << endl;
		}

		system("pause");
		system("cls");
	}
}