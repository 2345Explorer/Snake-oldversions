#include "stdafx.h"
#ifdef __cplusplus
#include "Snake.h"
using namespace std;
//����.
void InitFruit();
void InitHead(short ms);
void print_map();
bool Move();
void EatFruit();
bool GetInput();
void StartGame(short ms);
short StartMenu();
bool EndGame(short x);
short _Start();
void Settings();
void SeeSettings();
void About();
void ResetSettings();
pos head,tail[MaxSnakeTailLength],fruit;
int SnakeLength=0;
const short dx[4]= {-1,1,0,0},dy[4]= {0,0,-1,1};
const short rdx[4]= {1,-1,0,0},rdy[4]= {0,0,1,-1};
bool pausing=false;
int d;		//0ǰ1��2��3��

int main(int argc,char* argv[],char** env) {
	srand((unsigned)time(NULL));
	system("title ̰����");
	while(1) {
		SnakeLength=0;
		system("cls");
		short t=StartMenu();
		if(!EndGame(t)) {
			system("cls");
			system("pause");
			return 0;
		}
	}
}

void InitFruit() {		//��ʼ��ˮ��.
	do {
		fruit.x=rand()%HIGHT,fruit.y=rand()%WIDTH;
	} while(fruit.x==0||fruit.y==0||fruit.x==HIGHT-1||fruit.y==WIDTH-1);
}
void InitHead(short ms) {		//��ʼ����ͷ.
	int a[4]= {2,4,6,8};
	int x;
	switch(ms) {
		case WALK:
			x=0;
			break;
		case GO:
			x=1;
			break;
		case RUN:
			x=2;
			break;
		case FAST:
			x=3;
			break;
		default:
			x=3;
			break;
	}
	do {
		head.x=rand()%HIGHT,head.y=rand()%WIDTH;
	} while(head.x<=a[x]||head.y<=a[x]||head.x>=HIGHT-a[x]||head.y>=WIDTH-a[x]);
}

void print_map() {		//�����ͼ.
	bool mp[HIGHT+2][WIDTH+2];
	memset(mp,0,sizeof(mp));
	mp[head.x][head.y]=1;
	for(int i=0; i<SnakeLength; i++) {
		mp[tail[i].x][tail[i].y]=1;
	}
	for(int i=0; i<HIGHT; i++) {
		for(int j=0; j<WIDTH; j++) {
			if(i==fruit.x&&j==fruit.y) {
				gotoXY(j,i);
				cout<<FruitC;
			} else if(mp[i][j]) {
				gotoXY(j,i);
				if(i==head.x&&j==head.y)
					cout<<HeadC;
				else
					cout<<TailC;
			} else if(i==0||j==0||i==HIGHT-1||j==WIDTH-1) {
				gotoXY(j,i);
				if(i==0||i==HIGHT-1) {
					cout<<"-";
				} else {
					cout<<"|";
				}
			} else {
				gotoXY(j,i);
				cout<<" ";
			}
		}
	}
	gotoXY(WIDTH+2,10);
	cout<<"��ǰ����:"<<SnakeLength+1;
	gotoXY(WIDTH+2,12);
	cout<<"�÷�����ٿ�̰����,ESC��ͣ";
}

bool Move() {		//�Ƿ�����ƶ�,������Ծ��ƶ�.
	int thx=head.x+dx[d],thy=head.y+dy[d];
	for(int i=0; i<SnakeLength; i++)
		if(thx==tail[i].x&&thy==tail[i].y)
			return false;
	int lx=head.x,ly=head.y;
	head.x+=dx[d],head.y+=dy[d];
	for(int i=0; i<SnakeLength; i++) {
		int tx=tail[i].x,ty=tail[i].y;
		tail[i].x=lx,tail[i].y=ly;
		lx=tx,ly=ty;
	}
	return true;
}

void EatFruit() {		//�Ե�ˮ��.
	tail[SnakeLength].x=tail[SnakeLength-1].x+rdx[d];
	tail[SnakeLength].y=tail[SnakeLength-1].y+rdy[d];
	SnakeLength++;
	InitFruit();
}

bool GetInput() {		//��ȡ��������.
	char t=getch();
	if(t!=0&&t!=224&&t!=-32) {
		if(t==0x1b)
			pausing=true;
		return true;
	}
	char c=getch();		//�ڶ��ζ�ȡ,Ϊʲô������.
	if(c==UP) {
		if(d!=1) {
			d=0;
			if(!Move())
				return false;
		}
	} else if(c==DOWN) {
		if(d!=0) {
			d=1;
			if(!Move())
				return false;
		}
	} else if(c==LEFT) {
		if(d!=3) {
			d=2;
			if(!Move())
				return false;
		}
	} else if(c==RIGHT) {
		if(d!=2) {
			d=3;
			if(!Move())
				return false;
		}
	}
	return true;
}

void StartGame(short ms) {		//��ʼ��Ϸ.
	gotoXY(WIDTH,0);
	cout<<"       ";

	d=rand()%4;
	InitHead(ms);
	InitFruit();
	while(head.x>0&&head.y>0&&head.x<HIGHT-1&&head.y<WIDTH-1) {
		if(pausing) {
			gotoXY(WIDTH+2,12);
			cout<<"��ͣ��...  �������������Ϸ  ";
			getch();
			pausing=false;
		}
		if(head.x==fruit.x&&head.y==fruit.y) {
			EatFruit();
		}
		if(_kbhit()) {
			if(!GetInput())
				break;
		} else {
			if(!Move())
				break;
		}
		Sleep(ms);
		print_map();
	}
	print_map();
}

short _Start() {
	system("cls");
	cout<<"����������������̰���ߡ���������������\n";
	cout<<"ѡ����ǧ��Ҫ���س�\n";
	Sleep(100);
	cout<<"�÷�����ٿ�̰����,ESC��ͣ\n";
	Sleep(100);
	cout<<"��ѡ���ٶ�:1.ɢ�� 2.���� 3.���� 4.��� ����:���\n";
	char c=getch();
	bool flag=false;
	if(c<'1'||c>'4') {
		c=rand()%4+'1';
		cout<<"��ѡ�ٶ�:";
		flag=true;
	}
	short x;
	switch(c) {
		case '1': {
				x=WALK;
				if(flag)
					cout<<"ɢ��\n";
				break;
			}
		case '2': {
				x=GO;
				if(flag)
					cout<<"����\n";
				break;
			}
		case '3': {
				x=RUN;
				if(flag)
					cout<<"����\n";
				break;
			}
		case '4': {
				x=FAST;
				if(flag)
					cout<<"���\n";
				break;
			}
		default:
			break;
	}
	cout<<"������...\n";
	Sleep(1050);
	StartGame(x);
	return c-'0';
}

void Settings() {
	system("cls");
	cout<<"��������ͷ����(Ĭ��Ϊ#):";
	HeadC=getche();
	cout<<"\n�������������(Ĭ��Ϊ*):";
	TailC=getche();
	cout<<"\n������ʳ�����(Ĭ��Ϊ0):";
	FruitC=getche();
	cout<<"\n�������óɹ�!\n";
	system("pause");
}
void SeeSettings() {
	system("cls");
	cout<<"��ǰ��ͷ����Ϊ:"<<HeadC<<endl;
	cout<<"��ǰ�������Ϊ:"<<TailC<<endl;
	cout<<"��ǰʳ�����Ϊ:"<<FruitC<<endl;
	system("pause");
}
void About() {
	system("cls");
	cout<<"̰����1.0.9 by 2345Explorern";
	Sleep(100);
	cout<<"����ʱ��:2020.3.28\n";
	Sleep(100);
	system("pause");
}
void ResetSettings() {
	cin.clear();
	system("cls");
	HeadC='#';
	TailC='*';
	FruitC='0';
	cout<<"�ѽ���ͷ��������Ϊ#\n";
	cout<<"�ѽ������������Ϊ*\n";
	cout<<"�ѽ�ʳ���������Ϊ0\n";
	system("pause");
}
short StartMenu() {		//��ʼ�˵�.
	cout<<"����������������̰���ߡ���������������\n\n";
	Sleep(100);
	int f=0;
	int a[5][2]= {2,2,11,6,24,6,37,6,50,2};
	while(1) {
		system("cls");
		cout<<"����������������̰���ߡ���������������\n\n";
		cout<<" ��ʼ     �鿴����     ��������     ��������     ����\n";
		Print_Fame(1,a[f][0],a[f][1]);
		gotoXY(0,4);
		cout<<"���ҷ����ѡ��,�س�ȷ��\n";
		char c1=getch();
		if(c1!=0&&c1!=224&&c1!=-32) {
			if(c1==13) {		//�س�.
				if(f==1)
					SeeSettings();
				else if(f==2)
					Settings();
				else if(f==3)
					ResetSettings();
				else if(f==4)
					About();
				else
					break;
			}
		} else {
			char c2=getch();
			if(c2==LEFT) {
				if(f==0)
					f=4;
				else
					f--;
			} else if(c2==RIGHT) {
				if(f==4)
					f=0;
				else
					f++;
			}
		}
	}
	return _Start();
}
bool EndGame(short x) {		//��Ϸ����.
	gotoXY(0,HIGHT+1);
	system("pause");
	system("cls");
	cout<<"��Ϸ����!\n";
	cout<<"����:"<<SnakeLength+1<<endl;
	string a[5]= {"","ɢ��","����","����","���"};
	cout<<"�ٶ�:"<<a[x]<<endl;
	Sleep(1000);
	cout<<"Y:����һ�� N:����\n";
	char c=getch();
	return (c=='Y'||c=='y');
}

#else		//�õ���C����.   
int main(int argc,char* argv[],char** env) {
	printf("ERROR:��Ҫ��G++����!\n");
	printf("���ڽ���׺����Ϊcpp\n");
	char c1[1002]="move /-Y \"";
	int i;
	for(i=10; __FILE__[i-10]!='\0'; i++)
		c1[i]=__FILE__[i-10];
	int x=i+3;
	c1[i++]='\"';
	c1[i++]=' ';
	c1[i++]='\"';
	for(; __FILE__[i-x]!='\0'; i++)
		c1[i]=__FILE__[i-x];
	c1[i++]='p';
	c1[i++]='p';
	c1[i++]='\"';
	c1[i]='\0';
	char c2[302]="C:\\Windows\\explorer.exe \"";
	char path[302];
	GetCurrentDirectory(300, path);
	for(i=25; path[i-25]!='\0'; i++)
		c2[i]=path[i-25];
	c2[i++]='\"';
	c2[i]='\0';

	Sleep(2000);
	printf("���ڳ����ƶ��ļ�...\n");
	printf("������������...\n");
	Sleep(1000);
	printf("����:%s\n",c1);
	system(c1);
	Sleep(2000);
	printf("�������!�����CPP�ļ�\n");
	Sleep(1000);
	printf("���ڳ��Դ򿪵�ǰ�ļ���...\n");
	printf("������������...\n");
	Sleep(1000);
	printf("����:%s\n",c2);
	system(c2);
	printf("���ڹرճ���...\n");
	system("exit /b");
	return 0;
}
#endif

