#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cstdlib>
#include"funtions.h"
#include"warship.h"
using namespace std;


Cruiser :: Cruiser() : warship(4,"Cruiser"){}

void Cruiser :: attack(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE], int &Cost){
	char input[52];
	while(1){
		cout<<"Select your move. (1)fire (2)MissileVolley(-600) :";
		cin.getline(input,50);
		if(input[0]=='1'){
			Normal_fire(gamedata,board);
			break;
		}
		else if(input[0]=='2' && Cost<600) cout<<"Your money is not enough."<<endl;
		else if(input[0]=='2'&&Cost>=600){
			MissileVolley(gamedata,board);
	        Cost-=600;
            break;
		}
		else cout<<"Invalid input."<<endl;
	}
    system("clear");
}

bool Cruiser :: checksunk(char board[SIZE][SIZE]){
	if(sunk){
		cout<<"The Cruiser is sunk."<<endl;
		for(int i=0;i<length;i++){
			board[position[i].first][position[i].second]='s';
		}
		return true;
	}
	return false;
}

//由目標往右往下數共4x4個格子中隨機找三個不重複的格子轟炸,若轟炸到的位子已被攻擊過則視為無效(重複攻擊無效)
bool Cruiser :: MissileVolley(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE]){
	pair<int,int> p,prd;i
	vector<int> rd( getrand(3,16) );
    //0~15中隨機三個不同的數字
	cout<<"Enter upper-left position(randomly bombard a 4x4 area): ";
	p=Enterpos();
	while( p.first<0||p.first>SIZE-4||p.second<0||p.second>SIZE-4){
        //必須能包含4x4個格子
		cout<<"Invalid position,please enter again: ";
		p=Enterpos();
	}
	for(int i=0;i<3;i++){
		prd.first=p.first+rd[i]/4;
		prd.second=p.second+rd[i]%4;
		//用隨機值除以4的商數和餘數來選取座標
        if(Checkpos(prd.first,prd.second,board)){
			if(fire(prd,gamedata)) board[prd.first][prd.second]='*';
			else board[prd.first][prd.second]='X';
		}
	}
}



AircraftCarrier :: AircraftCarrier() : warship(5,"AircraftCarrier"){}
void AircraftCarrier :: attack(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE], int &Cost){
	char input[52];
	while(1){
		cout<<"Select your move. (1)fire (2)AirStrike(-800) :";
		cin.getline(input,50);
		if(input[0]=='1'){
			Normal_fire(gamedata,board);
			break;
		}
		else if(input[0]=='2' && Cost<800) cout<<"Your money is not enough."<<endl;
		else if(input[0]=='2'&&Cost>=800){
			AirStrike(gamedata,board);
            Cost-=800;
			break;
		}
		else cout<<"Invalid input."<<endl;
	}
    system("clear");
}

bool AircraftCarrier :: checksunk(char board[SIZE][SIZE]){
	if(sunk){
		cout<<"The Aircraft is sunk."<<endl;
		for(int i=0;i<length;i++){
			board[position[i].first][position[i].second]='s';
		}
		return true;
	}
	return false;
}

bool AircraftCarrier :: AirStrike(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE]){
	pair<int,int> p;
	cout<<"Enter Airstrike target (x,y), will also attack (x-1,y-1),(x+1,y+1) : ";
	p=Enterpos();
	while(!Checkpos(p.first,p.second,board)){
		cout<<"Invalid position,please enter again: ";
		p=Enterpos();
	}
	if(fire(p,gamedata)) board[p.first][p.second]='*';
	else board[p.first][p.second]='X';	
	p.first--;p.second--;
	if(Checkpos(p.first,p.second,board)){
		if(fire(p,gamedata)) board[p.first][p.second]='*';
		else board[p.first][p.second]='X';	
	}
	p.first+=2;p.second+=2;
	if(Checkpos(p.first,p.second,board)){
		if(fire(p,gamedata)) board[p.first][p.second]='*';
		else board[p.first][p.second]='X';	
	}
}

