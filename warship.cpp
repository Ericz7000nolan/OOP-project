#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include"funtions.h"
#include"warship.h"
using namespace std;

//constructor, 其中lenth,health,Category,sunk跟position的長度在宣告時就已經決定好了
warship :: warship(int l,string s) : length(l),health(l),Category(s){
	sunk=false;
	position=new pair<int,int>[l];
}

warship :: ~warship(){
	delete[] position;
}

//對gamedata中該位置的船隻進行攻擊並判斷該船是否擊沉,回傳bool表攻擊是否擊中
bool warship :: fire(pair<int, int> p, warship* gamedata[SIZE][SIZE]){
	if(gamedata[p.first][p.second]){
		gamedata[p.first][p.second]->health-=1;
		if( !gamedata[p.first][p.second]->health ) gamedata[p.first][p.second]->sunk=true;
		return true;
	}
	return false;
}

//隨機找尋board上一個合法的位置,並將自己填入board跟gamedata中,time是rand的seed,由main funtion中的亂數決定
void warship :: auto_set(warship* gamedata[SIZE][SIZE] ,char board[SIZE][SIZE],int time){
	int direct,i;
	srand( time );
	while(1){
		direct=rand()%2;;
		position[0].first=rand()%SIZE;
		position[0].second=rand()%SIZE;
		if(direct==0){
			for(i=0;i<length;i++){
				if( ! CheckEmpty( position[0].first + i, position[0].second, board) ) break;
				//確認是否為皆為合法空格
				position[i].first=position[0].first + i;
				position[i].second=position[0].second;
			}
		}
		else if(direct==1){
			for(i=0;i<length;i++){
				if( ! CheckEmpty( position[0].first, position[0].second + i, board) ) break;
				//確認是否為皆為合法空格
				position[i].first=position[0].first;
				position[i].second=position[0].second + i;
			}	
		}
		if(i==length)break;
		//若全合法才跳出,此時已配好位置
	}
	for(i=0;i<length;i++){
		gamedata[ position[i].first ][ position[i].second ] = this;
		board[ position[i].first ][ position[i].second ] = Category[0];
		//資料盤指向該物件,遊戲盤填上船名
	}
}

//提供介面設定遊戲開始時的船位
void warship :: set_position(warship* gamedata[SIZE][SIZE] ,char board[SIZE][SIZE]){
	char direct;
	int i=0;
    while(1){
		cout<<"Please input position & direct(ex:V1a):";
		cin>>direct;
		position[0]=Enterpos();
        //請玩家輸入位置
        if(direct=='V' || direct=='v'){
			for(i=0;i<length;i++){
				if( ! CheckEmpty( position[0].first + i, position[0].second, board) ) break;
				//確認是否為皆為合法空格
				position[i].first=position[0].first + i;
				position[i].second=position[0].second;
			}
		}
		else if(direct=='H' || direct=='h'){
			for(i=0;i<length;i++){
				if( ! CheckEmpty( position[0].first, position[0].second + i, board) ) break;
				//確認是否為皆為合法空格
				position[i].first=position[0].first;
				position[i].second=position[0].second + i;
			}
		}
		if(i==length)break;
		//若全合法才跳出,此時已配好位置
		else cout<<"Invalid positions."<<endl;
	}
	for(i=0;i<length;i++){
		gamedata[ position[i].first ][ position[i].second ] = this;
		board[ position[i].first ][ position[i].second ] = Category[0];
		//資料盤指向該物件,遊戲盤填上船名
	}
	system("clear");
    //設定完一艘船後便刷新頁面
}

//要求玩家輸入一個合法座標,並對該座標進行fire,判斷是否擊重並標記
void warship :: Normal_fire(warship* gamedata[SIZE][SIZE],char board[SIZE][SIZE]){
	pair<int,int> p(1,1);
	cout<<"Enter your target:"<<endl;
	p=Enterpos();
	while(!Checkpos(p.first,p.second,board)){
		cout<<"Invalid position,please enter again!!!"<<endl;
		p=Enterpos();
	}
	if(fire(p,gamedata)){
		cout<<"You hit a ship!!"<<endl;
		board[p.first][p.second]='*';
	}
	else board[p.first][p.second]='X';
}

//回傳第i個position,若第i個不存在則回傳一個不合法的位置(-1,-1)
pair<int,int> warship :: getposition(int i){
	pair<int,int> p(-1,-1);
	if(i<0||i>=length)return p;
    else {
		p.first=position[i].first;
		p.second=position[i].second;
		return p;
	}
}



//建立Cunboat,設定長度血量為2,種類為Boat (因為C會跟Cruiser撞名)
Cunboat :: Cunboat():warship(2,"Boat"){}

//跳出Cunboat的操作介面
void Cunboat :: attack(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE], int &Cost){
	char input[52];
	while(1){
		cout<<"Select your move. (1)fire (2)Radar(-500): ";
		cin.getline(input,50);
        //只要第一個字為1或2即可
		if(input[0]=='1'){
			Normal_fire(gamedata,board);
			break;
		}
		else if(input[0]=='2'&&Cost<500) cout<<"Your money is not enough!\n";
		else if(input[0]=='2'&&Cost>=500){
			Radar(gamedata,board);
			Cost-=500;
            break;
		}
		else cout<<"Invalid input."<<endl;
	}
    system("clear");
}

//偵查一個2x2區域,若無船艦標記為X,若有則標記小寫o,若其中有格子被轟炸過或違法則無視,但目標格必須有效
bool Cunboat :: Radar(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE]){
	pair<int,int> p;
	cout<<"Enter upper-left corner position(detect 2*2 area):"<<endl;
	p=Enterpos();
	while(!Checkpos(p.first,p.second,board)){
		cout<<"Invalid position,please enter again: ";
		p=Enterpos();
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			//掃描2*2的區域
			if(Checkpos(p.first+i, p.second+j, board)){
				//先確認此格是否合法且未被轟炸
				if(gamedata[p.first+i][p.second+j]){
					board[p.first+i][p.second+j]='o';
				}
				else board[p.first+i][p.second+j]='X';
			}
		}
	}
}

bool Cunboat :: checksunk(char board[SIZE][SIZE]){
	if(sunk){
		cout<<"The Cunboat is sunk."<<endl;
		for(int i=0;i<length;i++){
			board[position[i].first][position[i].second]='s';
		}
		return true;
	}
	return false;
}
