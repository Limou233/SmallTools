#include<iostream>
#include<conio.h>
using namespace std;
inline void pause(string __prompt = "�����������....") {
	//��ͣ���� (string:��ʾ��) -> void
	cout << __prompt << endl;
	_getch();//��������˳�
}
inline bool string_is_num(string str) {
	for (short i = 0; i < str.size(); i++) {
		short tmp = (short)str[i];
		if (tmp >= 48 && tmp <= 57) 
			continue;
		else return false;
	}
	return true;
}

namespace opt {
	// ������ǰ��inline��Ϊ�˽��LNK200��LNK1669����

	//Darrows
	
	inline void win10_del_Darrows() {
		system("reg add \"\
			HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons\" \
			/v 29 /d \" % systemroot % \\system32\\imageres.dll, 197\" /t reg_sz /f");
		system("taskkill /f /im explorer.exe");
		system("start explorer.exe");
		cout << "�����!" << endl, pause();
	}inline void win11_del_Darrows() {
		system("reg add \
			\"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons\" \
			/v 29 /d \" % systemroot % \\system32\\imageres.dll, 197\" /t reg_sz /f");
		system("taskkill /f /im explorer.exe");
		system("attrib -s -r -h \" % userprofile % \\AppData\\Local\\iconcache.db\"");
		system("del \" % userprofile % \\AppData\\Local\\iconcache.db\" /f /q");
		system("start explorer");
		cout << "�����!" << endl, pause();
	}inline void restore_Darrows() {
		system("reg delete \" \
		HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons\" /v 29 /f");
		system("taskkill /f /im explorer.exe");
		system("start explorer");
		cout << "�����!" << endl, pause();
	}

	static struct FuncList {
		string name;
		void (*func)();
	}list[32] = {
	"Win10ȥ��ݷ�ʽ��ͷ",&win10_del_Darrows,
	"Win11ȥ��ݷ�ʽ��ͷ",&win11_del_Darrows,
	"Win10/11�ָ��ָ���ͷ",&restore_Darrows
	};
}