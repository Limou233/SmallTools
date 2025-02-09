/*
Coding:UTF-8
@Author: (limou233)[http://github.com/limou233]
Compiler: MSVC++ 2022
*/
// F_XXX:Ç°¾°É«
// B_XXX:±³¾°É«

#include<iostream>
#include<Windows.h>
#define F_BlUE 0X1
#define F_GREEN 0x2
#define F_RED 0x4
#define F_LIGHT 0x8
#define F_WHITE 0x1|0x2|0x4|0x8
#define B_BLUE 0x10
#define B_GREEN 0x20
#define B_RED 0x40
#define B_LIGHT 0x80
#define B_WHITE B_BLUE|B_GREEN|B_RED|B_LIGHT

using namespace std;

static void ColPrint(string __str, int __color, bool back = false) {// (string:´òÓ¡×Ö·û,int:ÑÕÉ«,bool:»Ö¸´Ä¬ÈÏÑÕÉ«) -> void
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), __color);
    cout << __str;
    if (back)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), F_WHITE);
}
static void Color(int __Color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), __Color);
}

