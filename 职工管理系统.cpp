#include"workerManager.h"


int main() {

	//创建一个公司对象
	workerManager wm;

	while (1) {

		//开始菜单
		wm.show_Menu();

		int choice = 0;
		cout << "请输入你的选择:";
		cin >> choice;
		switch (choice) {
		case 0: //退出程序
			wm.exitSystem();
			break;

		case 1://添加职工信息
			wm.addWorker();
			break;

		case 2://显示职工信息
			wm.show_Emp();
			break;

		case 3://删除离职职工
			wm.Del_Emp();
			break;

		case 4://修改职工信息
			wm.Mod_Emp();
			break;

		case 5://查找职工信息
			wm.Find_Emp();
			break;

		case 6://清空所有文档
			wm.Clean_File();
			break;

		default:
			cout << "请输入0~7的数字" << endl;
			cout << "若要退出，请输入0" << endl;
		}

		system("pause");
		system("cls");
	}
}