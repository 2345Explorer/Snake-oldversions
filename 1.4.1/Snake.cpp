/*
   Copyright (c) [Year] [name of copyright holder]
   [Software Name] is licensed under Mulan PSL v2.
   You can use this software according to the terms and conditions of the Mulan PSL v2. 
   You may obtain a copy of Mulan PSL v2 at:
            http://license.coscl.org.cn/MulanPSL2 
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.  
   See the Mulan PSL v2 for more details.  


                     Mulan Permissive Software License��Version 2

   Mulan Permissive Software License��Version 2 (Mulan PSL v2)
   January 2020 http://license.coscl.org.cn/MulanPSL2

   Your reproduction, use, modification and distribution of the Software shall be subject to Mulan PSL v2 (this License) with the following terms and conditions: 
   
   0. Definition
   
      Software means the program and related documents which are licensed under this License and comprise all Contribution(s). 
   
      Contribution means the copyrightable work licensed by a particular Contributor under this License.
   
      Contributor means the Individual or Legal Entity who licenses its copyrightable work under this License.
   
      Legal Entity means the entity making a Contribution and all its Affiliates.
   
      Affiliates means entities that control, are controlled by, or are under common control with the acting entity under this License, ��control�� means direct or indirect ownership of at least fifty percent (50%) of the voting power, capital or other securities of controlled or commonly controlled entity.

   1. Grant of Copyright License

      Subject to the terms and conditions of this License, each Contributor hereby grants to you a perpetual, worldwide, royalty-free, non-exclusive, irrevocable copyright license to reproduce, use, modify, or distribute its Contribution, with modification or not.

   2. Grant of Patent License 

      Subject to the terms and conditions of this License, each Contributor hereby grants to you a perpetual, worldwide, royalty-free, non-exclusive, irrevocable (except for revocation under this Section) patent license to make, have made, use, offer for sale, sell, import or otherwise transfer its Contribution, where such patent license is only limited to the patent claims owned or controlled by such Contributor now or in future which will be necessarily infringed by its Contribution alone, or by combination of the Contribution with the Software to which the Contribution was contributed. The patent license shall not apply to any modification of the Contribution, and any other combination which includes the Contribution. If you or your Affiliates directly or indirectly institute patent litigation (including a cross claim or counterclaim in a litigation) or other patent enforcement activities against any individual or entity by alleging that the Software or any Contribution in it infringes patents, then any patent license granted to you under this License for the Software shall terminate as of the date such litigation or activity is filed or taken.

   3. No Trademark License

      No trademark license is granted to use the trade names, trademarks, service marks, or product names of Contributor, except as required to fulfill notice requirements in Section 4.

   4. Distribution Restriction

      You may distribute the Software in any medium with or without modification, whether in source or executable forms, provided that you provide recipients with a copy of this License and retain copyright, patent, trademark and disclaimer statements in the Software.

   5. Disclaimer of Warranty and Limitation of Liability

      THE SOFTWARE AND CONTRIBUTION IN IT ARE PROVIDED WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED. IN NO EVENT SHALL ANY CONTRIBUTOR OR COPYRIGHT HOLDER BE LIABLE TO YOU FOR ANY DAMAGES, INCLUDING, BUT NOT LIMITED TO ANY DIRECT, OR INDIRECT, SPECIAL OR CONSEQUENTIAL DAMAGES ARISING FROM YOUR USE OR INABILITY TO USE THE SOFTWARE OR THE CONTRIBUTION IN IT, NO MATTER HOW IT��S CAUSED OR BASED ON WHICH LEGAL THEORY, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

   6. Language

      THIS LICENSE IS WRITTEN IN BOTH CHINESE AND ENGLISH, AND THE CHINESE VERSION AND ENGLISH VERSION SHALL HAVE THE SAME LEGAL EFFECT. IN THE CASE OF DIVERGENCE BETWEEN THE CHINESE AND ENGLISH VERSIONS, THE CHINESE VERSION SHALL PREVAIL.

   END OF THE TERMS AND CONDITIONS

   How to Apply the Mulan Permissive Software License��Version 2 (Mulan PSL v2) to Your Software

      To apply the Mulan PSL v2 to your work, for easy identification by recipients, you are suggested to complete following three steps:

      i Fill in the blanks in following statement, including insert your software name, the year of the first publication of your software, and your name identified as the copyright owner; 

      ii Create a file named ��LICENSE�� which contains the whole context of this License in the first directory of your software package;

      iii Attach the statement to the appropriate annotated syntax at the beginning of each source file.


   Copyright (c) [Year] [name of copyright holder]
   [Software Name] is licensed under Mulan PSL v2.
   You can use this software according to the terms and conditions of the Mulan PSL v2. 
   You may obtain a copy of Mulan PSL v2 at:
               http://license.coscl.org.cn/MulanPSL2 
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.  
   See the Mulan PSL v2 for more details.  
*/
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "Snake.h"
using namespace std;
//����.
void InitFruit() throw() ;
void InitHead(short ms) throw() ;
void Print_Map() throw() ;
void Print_Tips() throw() ;
bool Move() throw() ;
void EatFruit() throw() ;
bool GetInput() throw() ;
void StartGame(short ms) throw() ;
short StartMenu() throw() ;
void DebugMode() throw() ;
bool EndGame(short x) throw() ;
short _Start() throw() ;
void Settings() throw() ;
void About() throw() ;
pos head,tail[MaxSnakeTailLength],fruit;
DebugModeSettings DebugModeSetting=(DebugModeSettings){true,0};
int SnakeLength=0;
const short dx[4]= {-1,1,0,0},dy[4]= {0,0,-1,1};
const short rdx[4]= {1,-1,0,0},rdy[4]= {0,0,1,-1};
bool Pausing=false,SeeMenu=false;
int d;		//0ǰ1��2��3��

int main(int argc,char* argv[],char** env) {
	srand((unsigned)time(NULL));
	system("title ̰����");
	HideCursor();

	while(1) {
		SnakeLength=0;
		system("cls");
		short t=StartMenu();
		if(SeeMenu){
			SeeMenu=false;
			continue;
		}
		if(!EndGame(t)) {
			system("cls");
			system("pause");
			return 0;
		}
	}
}

void InitFruit() throw() {		//��ʼ��ˮ��.
	HideCursor();
	do {
		fruit.x=rand()%HIGHT,fruit.y=rand()%WIDTH;
		for(int i=0;i<SnakeLength;i++)
			if(fruit.x==tail[i].x&&fruit.y==tail[i].y){
				fruit.x=0;
				break;
			}
	} while(fruit.x==0||fruit.y==0||fruit.x==HIGHT-1||fruit.y==WIDTH-1||(fruit.x==head.x&&fruit.y==head.y));
}
void InitHead(short ms) throw() {		//��ʼ����ͷ.
	HideCursor();
	int a[4]= {2,4,6,8};
	int x;
	if(ms==SPEED_MS[1])	x=0;
	else if(ms==SPEED_MS[2])	x=1;
	else if(ms==SPEED_MS[3])	x=2;
	else if(ms==SPEED_MS[4])	x=3;
	do {
		head.x=rand()%HIGHT,head.y=rand()%WIDTH;
	} while(head.x<=a[x]||head.y<=a[x]||head.x>=HIGHT-a[x]||head.y>=WIDTH-a[x]);
}

void Print_Map() throw() {		//�����ͼ.
	HideCursor();
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
}
void Print_Tips() throw() {
	HideCursor();
	gotoXY(WIDTH+2,10);
	cout<<"��ǰ����:"<<SnakeLength+1<<"         ";
	gotoXY(WIDTH+2,12);
	cout<<"�÷�����ٿ�̰����,ESC��ͣ           ";
}

bool Move() throw() {		//�Ƿ�����ƶ�,������Ծ��ƶ�.
	HideCursor();
	int thx=head.x+dx[d],thy=head.y+dy[d];
	if(DebugModeSetting.HBT)
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

void EatFruit() throw() {		//�Ե�ˮ��.
	HideCursor();
	tail[SnakeLength].x=tail[SnakeLength-1].x+rdx[d];
	tail[SnakeLength].y=tail[SnakeLength-1].y+rdy[d];
	SnakeLength++;
	InitFruit();
}

bool GetInput() throw() {		//��ȡ��������.
	HideCursor();
	char t=getch();
	if(t!=0&&t!=224&&t!=-32) {
		if(t==0x1b)
			Pausing=true;
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

void StartGame(short ms) throw() {		//��ʼ��Ϸ.
	HideCursor();
	gotoXY(WIDTH,0);
	cout<<"       ";
	d=rand()%4;
	InitHead(ms);
	InitFruit();
	for(int i=1;i<=DebugModeSetting.InitTailLength;i++)	EatFruit();
	while(head.x>0&&head.y>0&&head.x<HIGHT-1&&head.y<WIDTH-1) {
		if(Pausing) {
			int a[3][3]={9,WIDTH+2,8,11,WIDTH+2,12,13,WIDTH+2,8},i=0;
			bool flag=false;
			while(1){
				if(!flag){
					system("cls");
					Print_Map();
					gotoXY(WIDTH+2,10);
					cout<<"������Ϸ                 ";
					gotoXY(WIDTH+2,12);
					cout<<"�˳������˵�             ";
					gotoXY(WIDTH+2,14);
					cout<<"�˳���Ϸ                 ";
					if(IsWin7())	Print_Fame(a[i][0],a[i][1],a[i][2]+1);
					else	Print_Fame(a[i][0],a[i][1],a[i][2]);
					gotoXY(WIDTH+2,16);
					cout<<"�ϡ��·�����л�, �س�ѡ��";
				} else {
					flag=false;
				}
				char t=getch();
				if(t==0||t==224||t==-32) {
					char c=getch();
					if(c==UP) {
						if(i>0) i--;
						else	i=2;
					} else if(c==DOWN) {
						if(i<2)	i++;
						else	i=0;
					} else {
						flag=true;
					}
				} else if(t==13){	//�س�.
					if(i==0){
						break;
					}else if(i==1){
						Pausing=false;
						SeeMenu=true;
						return ;
					}else if(i==2){
						gotoXY(0,HIGHT+1);
						exit(0);
					}
				}
			}
			Pausing=false;
			system("cls");
			Print_Map();
			Print_Tips();
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
		Print_Map();
		Print_Tips();
	}
	Print_Map();
	Print_Tips();
}

short _Start() throw() {
	HideCursor();
	system("cls");
	int f=0,speed,flag=false;
	int a[5][2]={2,2,8,2,14,2,20,2,26,2};
	while(1){
		if(!flag){
			system("cls");
			cout<<"**********̰����**********\n";
			cout<<"��ѡ���ٶ�\n\n";
			cout<<' '<<SPEED_STR[1]<<"  "<<SPEED_STR[2]<<"  "
				<<SPEED_STR[3]<<"  "<<SPEED_STR[4]<<" ���\n\n";
			cout<<"���ҷ�����л�,�س�ѡ��\n";
			if(IsWin7())	Print_Fame(2,a[f][0],a[f][1]+1);
			else	Print_Fame(2,a[f][0],a[f][1]);
		} else {
			flag=false;
		}
		char c1=getch();
		if(c1!=0&&c1!=224&&c1!=-32){
			if(c1==13){
				if(f==4){
					speed=rand()%4+1;	//ɢ��:1 ����:2 ����:3 ���:4 
				} else {
					speed=f+1;
				}
				break;
			} else {
				flag=true;
			}
		} else {
			char c2=getch();
			if(c2==LEFT){
				if(f==0)	f=4;
				else	f--;
			} else if(c2==RIGHT){
				if(f==4)	f=0;
				else	f++;
			} else {
				flag=true;
			}
		}
	}
	system("cls");
	if(f==4)
		cout<<"��ѡ�ٶ�:"<<SPEED_STR[speed]<<endl;
	cout<<"������...\n";
	Sleep(1050);
	StartGame(SPEED_MS[speed]);
	return speed;
}

void DebugMode() throw() {
	int f=0;
	int a[3][3]={1,22,2,3,22,10,5,22,2};
	bool flag=false;
	while(1){
		if(!flag){
			system("cls");
			cout<<"********Debug����********\n\n";
			cout<<"��ͷײ��������:";
			if(DebugModeSetting.HBT)	cout<<"��";
			else	cout<<"��";
			cout<<"    ����  \n\n";
			cout<<"��ǰ��ʼ����Ϊ:"<<DebugModeSetting.InitTailLength+1;
			gotoXY(21,4);
			cout<<"���ĳ�ʼ����  \n\n";
			gotoXY(21,6);
			cout<<"�˳�\n\n";
			cout<<"�ϡ��·����ѡ��, �س�ȷ�� \n";
		} else flag=false;
		if(IsWin7)	Print_Fame(a[f][0],a[f][1],a[f][2]+1);
		else	Print_Fame(a[f][0],a[f][1],a[f][2]);
		char c1=getch();
		if(c1!=0&&c1!=224&&c1!=-32) {
			if(c1==13){		//�س�.
				system("cls");
				if(f==0){
					DebugModeSetting.HBT=!DebugModeSetting.HBT;
					cout<<"��ͷײ���������Ѹ���Ϊ";
					if(DebugModeSetting.HBT==true)	cout<<"��\n";
					else	cout<<"��\n";
					cout<<"�����ص�Debug���ý���...\n";
					Sleep(700);
				} else if(f==1){
					cout<<"������Ҫ���ĵĳ�ʼ����:";
					long long t;
					cin>>t;
					t--;
					if(t<0)	t=-t;
					t%=MaxSnakeTailLength;
					DebugModeSetting.InitTailLength=t;
					cout<<"\n���ĳɹ�!�����ص�Debug���ý���...";
					Sleep(700);
				} else{
					break;
				}
			} else {
				flag=true;
				continue;
			}
		} else {
			char c2=getch();
			if(c2==UP){
				if(f==0)	f=2;
				else	f--;
			} else if(c2==DOWN){
				if(f==2)	f=0;
				else	f++;
			} else {
				flag=true;
				continue;
			}
		}
	}
}

void Settings() throw() {
	HideCursor();
	int fx=0,fy=0;
	int a[4][2][3]={{{1,12,2},{1,20,2}},
					{{3,12,2},{3,20,2}},
					{{5,12,2},{5,20,2}},
					{{7,9,8},{7,20,6}}};
	bool flag=false;
	while(1){
		if(!flag){
			system("cls");
			cout<<"**********����***********\n\n";
			cout<<" ��ͷ:"<<HeadC<<"    ����    ���� \n\n";
			cout<<" ����:"<<TailC<<"    ����    ���� \n\n";
			cout<<" ʳ��:"<<FruitC<<"    ����    ���� \n\n";
			cout<<"        Debugģʽ  �˳����� \n\n";
			cout<<"�������ҷ����ѡ��, �س�ȷ��\n";
		} else	flag=false;
		if(IsWin7())	Print_Fame(a[fx][fy][0],a[fx][fy][1],a[fx][fy][2]+1);
		else	Print_Fame(a[fx][fy][0],a[fx][fy][1],a[fx][fy][2]);
		char c1=getch();
		if(c1!=0&&c1!=224&&c1!=-32) {
			if(c1==13){		//�س�.
				if(fy==0&&fx<3){
					system("cls");
					if(fx==0){
						HeadC='#';
						cout<<"��ͷ����������Ϊ#\n";
						cout<<"�����ص����ý���...";
						Sleep(700);
					}
					else if(fx==1){
						TailC='*';
						cout<<"�������������Ϊ*\n";
						cout<<"�����ص����ý���...";
						Sleep(700);
					}
					else {
						FruitC='0';
						cout<<"ʳ�����������Ϊ0\n";
						cout<<"�����ص����ý���...";
						Sleep(700);
					}
				} else if(fy==1){
					system("cls");
					if(fx==0){
						cout<<"������Ҫ���ĵ���ͷ����:";
						HeadC=getche();
						cout<<"\n���ĳɹ�!�����ص����ý���...";
						Sleep(700);
					}
					else if(fx==1){
						cout<<"������Ҫ���ĵ��������:";
						TailC=getche();
						cout<<"\n���ĳɹ�!�����ص����ý���...";
						Sleep(700);
					}
					else if(fx==2){
						cout<<"������Ҫ���ĵ�ʳ�����:";
						FruitC=getche();
						cout<<"\n���ĳɹ�!�����ص����ý���...";
						Sleep(700);
					}
					else if(fx==3)	break;
				} else if(fx==3&&fy==0){
					DebugMode();
				}
			} else {
				flag=true;
				continue;
			}
		} else {
			char c2=getch();
			if(c2==UP){
				if(fx==0)	fx=3;
				else	fx--;
			} else if(c2==DOWN){
				if(fx==3)	fx=0;
				else	fx++;
			} else if(c2==LEFT){
				if(fy==0)	fy=1;
				else	fy--;
			} else if(c2==RIGHT){
				if(fy==1)	fy=0;
				else	fy++;
			} else {
				flag=true;
				continue;
			}
		}
	}
}
void About() throw() {
	HideCursor();
	system("cls");
	cout<<"̰����"<<VERSION<<" by 2345Explorer\n";
	Sleep(100);
	cout<<"����ʱ��:"<<TIME<<endl;
	Sleep(100);
	system("pause");
}
short StartMenu() throw() {		//��ʼ�˵�.
	HideCursor();
	int f=0;
	bool flag=false;
	int a[4][2]= {2,2,11,2,20,2,29,6};
	while(1) {
		if(!flag){
			system("cls");
			cout<<"**********̰����**********\n\n";
			cout<<" ��ʼ     ����     ����     �˳���Ϸ  \n";
		}
		else	flag=false;
		if(IsWin7())	Print_Fame(1,a[f][0],a[f][1]+1);
		else	Print_Fame(1,a[f][0],a[f][1]);
		gotoXY(0,4);
		cout<<"���ҷ�����л�,�س�ѡ��\n";
		char c1=getch();
		if(c1!=0&&c1!=224&&c1!=-32) {
			if(c1==13) {		//�س�.
				if(f==1)
					Settings();
				else if(f==2)
					About();
				else if(f==3)
					exit(0);
				else
					break;
			} else {
				flag=true;
				continue;
			}
		} else {
			char c2=getch();
			if(c2==LEFT) {
				if(f==0)	f=3;
				else	f--;
			} else if(c2==RIGHT) {
				if(f==3)	f=0;
				else	f++;
			} else {
				flag=true;
				continue;
			}
		}
	}
	return _Start();
}
bool EndGame(short x) throw() {		//��Ϸ����.
	HideCursor();
	gotoXY(0,HIGHT+1);
	cout<<"��Ϸ����!\n";
	system("pause");
	system("cls");
	cout<<"��Ϸ����!\n";
	cout<<"����:"<<SnakeLength+1<<endl;
	cout<<"�ٶ�:"<<SPEED_STR[x]<<endl;
	Sleep(1000);
	cout<<"Y:����һ�� N:����\n";
	char c=32;
	while(c!='Y'&&c!='y'&&c!='N'&&c!='n'){
		c=getch();
	}
	return (c=='Y'||c=='y');
}
