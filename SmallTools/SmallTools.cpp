/*
Coding: UTF-8
@Author: (limou233)[http://github.com/limou233]
Compiler: MSVC++ 2022
*/
#include"./Opts.cpp"
using namespace std;
BOOL IsRunAsAdministrator();
void test() {
    cout << "test" << endl;
}
int main(){
	system("cls");
    cout << " start 开始" << endl;
    if (IsRunAsAdministrator() == FALSE) {
        ColPrint("请以管理员权限运行本程序!\n", F_RED);
        pause("按任意键退出....");
        return 1;
    }
    ColPrint("欢迎使用小工具箱\n", F_WHITE);
    ColPrint("       ——By: limou233\n", F_BLUE| F_LIGHT);
    ColPrint("+====功能列表====+\n",F_GREEN|F_LIGHT,false);
    for (short i = 0;!opt::list[i].name.empty();i++) {
         cout<<i+1<<'.'<<opt::list[i].name<<endl;
    }ColPrint("", F_WHITE);//还原颜色
    cout << "请输入功能编号>>>";
    string opt_id;cin >> opt_id;
    if (!string_is_num(opt_id)) {
        ColPrint("请输入数字!\n", F_RED);
        pause("按任意键退出...");
        return 1;
    }
    cout<<"正在执行"<<opt::list[atoi(opt_id.c_str())-1].name<<endl;
    opt::list[atoi(opt_id.c_str())-1].func();
    pause("按任意键退出...");
    return 0;
}
//From[https://blog.csdn.net/u012505629/article/details/109692159]
BOOL IsRunAsAdministrator() {
    // 判断当前进程是否以管理员权限运行
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
