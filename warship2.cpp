#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cstdlib>
#include"funtions.h"
#include"warship.h"
using namespace std;

//設定長度血量為3,種類為Destroyer
Destroyer :: Destroyer():warship(3,"Destroyer"){}

//跳出Destroyer的操作介面
void Destroyer :: attack(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE], int &Cost){
	char input[52];
	while(1){
		cout<<"Select your move. (1)fire (2)Plasma Connon(-700) :";
		cin.getline(input,50);
		if(input[0]=='1'){
			Normal_fire(gamedata,board);
			break;
		}
		else if(input[0]=='2' && Cost<700) cout<<"Your money is not enough."<<endl;
		else if(input[0]=='2'&&Cost>=700){
			PlasmaConnon(gamedata,board);
			Cost-=700;
            break;
		}
		else cout<<"Invalid input."<<endl;
	}
    system("clear");
}

//回傳bool確認是否沈船,顯示沈船訊息並將board上的該位子改為's'
bool Destroyer :: checksunk(char board[SIZE][SIZE]){
	if(sunk){
		cout<<"The Destroyer is sunk."<<endl;
		for(int i=0;i<length;i++){
			board[position[i].first][position[i].second]='s';
		}
		return true;
	}
	return false;
}

//若擊中船隻則對該船隻全體轟炸(就是擊沉啦)
bool Destroyer :: PlasmaConnon(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE]){
	pair<int,int> p;
	cout<<"Enter your target:"<<endl;
	p=Enterpos();
	while(!Checkpos(p.first,p.second,board)){
		cout<<"Invalid position,please enter again: ";
		p=Enterpos();
	}
	if(fire(p,gamedata)){
        //若是擊中目標,則存取目標的所有position並攻擊
		warship* enemy=gamedata[p.first][p.second];
		pair<int,int> ep;
		cout<<"You hit a ship!!"<<endl;
		board[p.first][p.second]='*';
		for(int i=0; i<(enemy->length) ;i++){
			ep=enemy->getposition(i);
			if( Checkpos( ep.first, ep.second, board) ){
				fire( ep , gamedata );
				board[ ep.first ][ ep.second ] = '*'; 
			}
		}
	}
	else board[p.first][p.second]='X';
}

//設定長度血量為3,種類為Submarine
Submarine :: Submarine():warship(3,"Submarine"){}

//彈出Submarine的操作介面
void Submarine :: attack(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE], int &Cost){
	char input[52];
	while(1){
		cout<<"Select your move. (1)fire (2)Torpedo(-300): ";
		cin.getline(input,50);
		if(input[0]=='1'){
			Normal_fire(gamedata,board);
			break;
		}
		else if(input[0]=='2'&&Cost<300) cout<<"Your money is not enough!\n";
		else if(input[0]=='2'&&Cost>=300){
			Torpedo(gamedata,board);
			Cost-=300;
            break;
		}
		else cout<<"Invalid input."<<endl;
	}
    system("clear");
}

//回傳bool確認是否沈船,顯示沈船訊息並將board上的該位子改為's'
bool Submarine :: checksunk(char board[SIZE][SIZE]){
	if(sunk){
		cout<<"The Submarine is sunk."<<endl;
		for(int i=0;i<length;i++){
			board[position[i].first][position[i].second]='s';
		}
		return true;
	}
	return false;
}

//沿著自身船頭位置的x座標攻擊橫向一直線 最多攻擊五格 集中目標則停止
bool Submarine :: Torpedo(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE]){
	pair<int,int> p=position[0];
	for(int i=0;i<5;i++){
		p.second=i;
		if(Checkpos(p.first,i,board)){
			//先確認是否可以攻擊
			if(fire(p,gamedata)) {
				//若擊中則標示擊中船隻  並結束攻擊
				board[p.first][i]='*';
				break;
			}
			else board[p.first][i]='X';
		}
	}
}

