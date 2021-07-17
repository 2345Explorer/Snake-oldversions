#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

//�������ASCII.
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

//20*50�ĸ���.
#define HIGHT 20
#define WIDTH 50
//�ߵ������.
#define MaxSnakeTailLength 1000
//�ٶ�.
#define WALK 300
#define GO 125
#define RUN 50
#define FAST 25

char HeadC='#',TailC='*',FruitC='0';

void gotoXY(short x,short y) {
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void Print_Fame(int x,int y,int len){
	gotoXY(y-1,x);
	for(int i=0;i<=len+1;i++)
		cout<<"-";
	gotoXY(y-1,x+2);
	for(int i=0;i<=len+1;i++)
		cout<<"-";
	gotoXY(y-2,x+1);
	cout<<"|";
	gotoXY(y+len,x+1);
	cout<<"|";
}

void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

struct pos {		//pos��0��ʼ.
	short x,y;
};

const short SPEED_MS[5]={0,WALK,GO,RUN,FAST};		//�ٶȶ�Ӧ��ֵ  
const string SPEED_STR[5]={"","ɢ��","����","����","���"};	//������������

const string VERSION="1.3.5",TIME="2021.5.15";
