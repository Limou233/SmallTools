/*
Coding: UTF-8
@Author: (limou233)[http://github.com/limou233]
Compiler: MSVC++ 2022
*/
// F_XXX:ǰ��ɫ
// B_XXX:����ɫ

#include<iostream>
#include<Windows.h>
#define F_BLUE 0X1
#define F_GREEN 0x2
#define F_RED 0x4
#define F_LIGHT 0x8
#define F_WHITE 0x1|0x2|0x4|0x8

#define F_YELLOW F_RED|F_GREEN

#define B_BLUE 0x10
#define B_GREEN 0x20
#define B_RED 0x40
#define B_LIGHT 0x80
#define B_WHITE B_BLUE|B_GREEN|B_RED|B_LIGHT

using namespace std;

static void ColPrint(string __str, int __color, bool back = true) {
    // (string:��ӡ�ַ�,int:��ɫ,bool:�ָ�Ĭ����ɫ) -> void
    // �ڿ���̨�����������ɫ��string
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), __color);
    cout << __str;
    if (back)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), F_WHITE);
}
static void Color(int __Color) {
    // (int:��ɫ) -> void
    // �л�����������̨�������ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), __Color);
}

