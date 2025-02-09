/*
Coding: UTF-8
@Author: (limou233)[http://github.com/limou233]
Compiler: MSVC++ 2022
*/
#include <iostream>
#include<Windows.h>
#include"./Color.cpp"
using namespace std;
BOOL IsRunAsAdministrator();

void pause(string __prompt="按任意键继续....") {
    //暂停程序 (string:提示语) -> void
	cout << __prompt << endl;
	getchar();//按任意键退出
}
class Opt {
	public:

		void win10_del_Darrows() {
			system("reg add \"\
			HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons\" \
			/v 29 /d \" % systemroot % \\system32\\imageres.dll, 197\" /t reg_sz /f");
			system("taskkill /f /im explorer.exe");
			system("start explorer.exe");
			cout << "已完成!" << endl,pause();
		}void win11_del_Darrows() {
			system("reg add \
			\"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons\" \
			/v 29 /d \" % systemroot % \\system32\\imageres.dll, 197\" /t reg_sz /f");
			system("taskkill /f /im explorer.exe");
			system("attrib -s -r -h \" % userprofile % \\AppData\\Local\\iconcache.db\"");
			system("del \" % userprofile % \\AppData\\Local\\iconcache.db\" /f /q");
			system("start explorer");
			cout << "已完成!" << endl,pause();
		}void restore_Darrows() {
            system("reg delete \" \
            HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons\" /v 29 /f");
            system("taskkill /f /im explorer.exe");
            system("start explorer");
            cout << "已完成!" << endl,pause();
        }
};

int main(){
	system("chcp 65001");
    if (IsRunAsAdministrator() == FALSE) {
        ColPrint("请以管理员权限运行本程序!\n", F_RED);
        pause("按任意键退出....");
    }
	return 0;
}
//From[https://blog.csdn.net/u012505629/article/details/109692159]
BOOL IsRunAsAdministrator() {
    BOOL fIsRunAsAdmin = FALSE;
    DWORD dwError = ERROR_SUCCESS;
    PSID pAdministratorsGroup = NULL;

    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    if (!AllocateAndInitializeSid(
        &NtAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &pAdministratorsGroup))
    {
        dwError = GetLastError();
        goto Cleanup;
    }

    if (!CheckTokenMembership(NULL, pAdministratorsGroup, &fIsRunAsAdmin))
    {
        dwError = GetLastError();
        goto Cleanup;
    }

Cleanup:

    if (pAdministratorsGroup)
    {
        FreeSid(pAdministratorsGroup);
        pAdministratorsGroup = NULL;
    }

    if (ERROR_SUCCESS != dwError)
    {
        throw dwError;
    }

    return fIsRunAsAdmin;
}
////////////////////////////////////////////////////////////////////////////



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
