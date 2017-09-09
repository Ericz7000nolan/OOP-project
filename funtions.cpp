#include<iostream>
#include<utility>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<cstdlib>
//#define SIZE 16
#include"funtions.h"
using namespace std;

//讓使用者輸入一個座標(數字+英文字母)並轉成對應二維陣列index的pair<int,int>來回傳
pair<int, int> Enterpos(){
	pair<int, int> ret(0,0);
	char c;
	cin.get(c);
	while(c>='0'&&c<='9'){
		ret.first*=10;
		ret.first+=(c-'0');
		cin.get(c);
	}
	ret.first--;
    if(c>='A'&& c<='Z') ret.second=c-'A';
    else ret.second=c-'a';
	cin.ignore(256,'\n');
	return ret;
}
bool Checkpos(int x,int y,char board[SIZE][SIZE]){
	if(x>=SIZE||x<0||y>=SIZE||y<0) return false;
	else if(board[x][y]=='X' || board[x][y]=='*' || board[x][y]=='s')return false;
	return true;
}

bool CheckEmpty(int x,int y,char board[SIZE][SIZE]){
	if(x>=SIZE||x<0||y>=SIZE||y<0) return false;
	else if(board[x][y]!=' ')return false;
	return true;
}

vector<int> getrand(int n,int div){
	vector<int> rd(n);
	srand(time(NULL));
	if(div<n)return rd;
	for(int i=0;i<n;i++){
		rd[i]=rand()%div;
		for(int j=0;j<i;j++){
			if(rd[i]==rd[j]){i--;break;}
		}
	}
//	cout<<rd[0]<<"  "<<rd[1]<<"  "<<rd[2]<<endl;	
	return rd;
}
