#include<iostream>
using namespace std;
inline void pause(string __prompt = "按任意键继续....") {
	//暂停程序 (string:提示语) -> void
	cout << __prompt << endl;
	getchar();//按任意键退出
}

namespace opt {

	// 函数名前加inline是为了解决LNK200和LNK1669错误

	//Darrows
	inline void win10_del_Darrows() {
		system("reg add \"\
			HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons\" \
			/v 29 /d \" % systemroot % \\system32\\imageres.dll, 197\" /t reg_sz /f");
		system("taskkill /f /im explorer.exe");
		system("start explorer.exe");
		cout << "已完成!" << endl, pause();
	}inline void win11_del_Darrows() {
		system("reg add \
			\"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons\" \
			/v 29 /d \" % systemroot % \\system32\\imageres.dll, 197\" /t reg_sz /f");
		system("taskkill /f /im explorer.exe");
		system("attrib -s -r -h \" % userprofile % \\AppData\\Local\\iconcache.db\"");
		system("del \" % userprofile % \\AppData\\Local\\iconcache.db\" /f /q");
		system("start explorer");
		cout << "已完成!" << endl, pause();
	}inline void restore_Darrows() {
		system("reg delete \" \
		HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons\" /v 29 /f");
		system("taskkill /f /im explorer.exe");
		system("start explorer");
		cout << "已完成!" << endl, pause();
	}
	

}