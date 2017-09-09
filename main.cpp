#include<iostream>
#include<list>
#include<vector>
#include<cstdlib>
#include<ctime>
#include"funtions.h"
#include"warship.h"
#include"valueMap.h"
#include"Display.h"
using namespace std;

void rm_sunkships(list<warship*> :: iterator &it, list<warship*> :: iterator &eit, list<warship*> &Ships, char board[SIZE][SIZE]){
    for( it=Ships.begin() ; it!=Ships.end();){
        if( (*it)->checksunk(board) ){
            //if find a ship sunk
            if( (*eit) == (*it) ) {
                //First, check if it will change eit, if so, let eit++
                eit++;
                if(eit==Ships.end()) eit=Ships.begin();
                if( eit == it ) eit=Ships.end();
                //eit==it means the list have only one item, so if we earse it, list will be empty.
            }
            it=Ships.erase(it);
        }
        else it++;
    }
}

int main(){
    int Cost;
    char mode,setmode;
    pair<int,int> AI;
    srand(time(NULL));
    list<warship*> Ships1,Ships2;
    list<warship*> :: iterator it1,it2,eit1,eit2;
    Cost=99999999;
    char P1board[SIZE][SIZE],P2board[SIZE][SIZE];	
    warship* P1game[SIZE][SIZE]{};
    warship* P2game[SIZE][SIZE]{};
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            P1board[i][j]=' ';
            P2board[i][j]=' ';
        }
    }
    //put ' ' in each board
    Cunboat b1,b2;
    Destroyer d1,d2;
    Submarine s1,s2;
    Cruiser c1,c2;
    AircraftCarrier a1,a2;
    Ships1.push_back(&b1);
    Ships1.push_back(&d1);
    Ships1.push_back(&s1);
    Ships1.push_back(&c1);
    Ships1.push_back(&a1);
    Ships2.push_back(&b2);
    Ships2.push_back(&d2);
    Ships2.push_back(&s2);
    Ships2.push_back(&c2);
    Ships2.push_back(&a2);
    
    //Game start!!
    system("clear");
    instruction();

    //select mode!!
    while(1){
        cout<<"Please choose game mode:";
        cin>>mode;
        cin.ignore(256,'\n');
        if(mode>='1'&&mode<='4')break;
        else cout<<"Invalid input, please enter again."<<endl;
    }

    //==========================Game mode1===========================
    //===========================P1 vs AI============================
    //=============================START=============================
    if(mode>='1' && mode <='3'){
        if(mode=='1')Cost=15000;
        else if(mode=='2') Cost=10000;
        else if(mode=='3') Cost=3000;
        //select setting mode
        while(1){
            cout<<"Player1 set warships."<<endl<<"Do you want auto setting? [y/n]";
            cin>>setmode;
            cin.ignore(256,'\n');
            if(setmode=='y'||setmode=='n')break;
            else cout<<"Invalid input, please enter again. "<<endl;
        }
        system("clear");

        //AUTO setting
        if(setmode=='y'){
            for(it1=Ships1.begin();it1!=Ships1.end();it1++){
                (*it1)->auto_set(P1game, P1board, rand() );
            }
            printOneDetail(P1board);
        }
        //Manual setting
        else if(setmode=='n'){
            for(it1=Ships1.begin();it1!=Ships1.end();it1++){
                printOneDetail(P1board);
                cout<<"Now set your "<<(*it1)->Category<<"\'s position."<<endl;
                (*it1)->set_position(P1game,P1board);
            }
        }
        for(it2=Ships2.begin();it2!=Ships2.end();it2++){
            (*it2)->auto_set(P2game, P2board, rand() );
        }

        system("clear");
        printBHidden(P1board,P2board);

        eit1=Ships1.begin();
        eit2=Ships2.begin();
        while( eit1!=Ships1.end() && eit2!=Ships2.end()){
            cout<<"Your have "<<Cost<<" dollars."<<endl;
            (*eit1)->attack(P2game,P2board,Cost);             //P1's attack end
            rm_sunkships(it2, eit2, Ships2, P2board);
            if(Ships2.begin()==Ships2.end()){
                printBHidden(P1board,P2board);
                win();
                break;
            }
            eit1++;
            if(eit1 == Ships1.end()) eit1=Ships1.begin();

            //========================================================================================
            //========================================================================================
            //========================================================================================

            if( Ships2.size()==1 && (mode=='2'||mode=='3') ) AI=THEEYE(P1board);
            //難度為2or3且電腦只剩一台船時就可以開掛喇\(ﾟ∀ﾟ)/
            else AI=Alphago(P1board);
            if(Checkpos(AI.first, AI.second, P1board)){
                if( (*eit2)->fire(AI , P1game) ){
                    P1board[AI.first][AI.second]='*';
                }
                else P1board[AI.first][AI.second]='X';
            }                                               //AI's attack end
            rm_sunkships(it1, eit1, Ships1, P1board);
            printBHidden(P1board,P2board);
            if(Ships1.begin()==Ships1.end()){
                lose();
                break;
            }
            eit2++;
            if(eit2 == Ships2.end()) eit2=Ships2.begin();
        }
    }
    //=================================Game mode1=============================
    //====================================END=================================

    //=================================Game mode2=============================
    //==================================P1 vs P2==============================
    //===================================START================================
    else if (mode=='4'){
        int Cost1=5000,Cost2=5000;
        //=======================P1set===============================
        while(1){
            cout<<"Player1 set warships."<<endl<<"Do you want auto setting? [y/n]";
            cin>>setmode;
            cin.ignore(256,'\n');
            if(setmode=='y'||setmode=='n')break;
            else cout<<"Invalid input, please enter again."<<endl;
        }
        system("clear");
        if(setmode=='y'){
            for(it1=Ships1.begin();it1!=Ships1.end();it1++){
                (*it1)->auto_set(P1game, P1board, rand() );
            }
            printOneDetail(P1board);
        }
        else if(setmode=='n'){
            printOneDetail(P1board);
            for(it1=Ships1.begin();it1!=Ships1.end();it1++){
                cout<<"Now set your "<<(*it1)->Category<<"\'s position."<<endl;
                (*it1)->set_position(P1game,P1board);
                printOneDetail(P1board);
            }
        }
        char clear;
        cout<<"Key in any characters to clear.";
        cin>>clear;
        cin.ignore(256,'\n');
        system("clear");    
        //=======================P1setEND============================
        //=======================P2set===============================
        while(1){
            cout<<"Player2 set warships."<<endl<<"Do you want auto setting? [y/n]";
            cin>>setmode;
            cin.ignore(256,'\n');
            if(setmode=='y'||setmode=='n')break;
            else cout<<"Invalid input, please enter again"<<endl;
        }
        system("clear");
        if(setmode=='y'){
            for(it2=Ships2.begin();it2!=Ships2.end();it2++){
                (*it2)->auto_set(P2game, P2board, rand() );
            }
            printOneDetail(P2board);
        }
        else if(setmode=='n'){
            printOneDetail(P2board);
            for(it2=Ships2.begin();it2!=Ships2.end();it2++){
                cout<<"Now set your "<<(*it2)->Category<<"\'s position."<<endl;
                (*it2)->set_position(P2game,P2board);
                printOneDetail(P2board);
            }
        }
        cout<<"Key in any characters to clear.";
        cin>>clear;
        cin.ignore(256,'\n');
        system("clear");
        //=======================P2setEND============================

        printBothHidden(P1board,P2board);

        eit1=Ships1.begin();
        eit2=Ships2.begin();

        while( eit1!=Ships1.end() && eit2!=Ships2.end()){
            //P1 attack!
            cout<<"Player1's TURN!!!!!"<<endl;
            cout<<"Player1's TURN!!!!!"<<endl;
            cout<<"Player1's TURN!!!!!"<<endl;
            cout<<"Your have "<<Cost1<<" dollars."<<endl;
            (*eit1)->attack(P2game,P2board,Cost1);
            rm_sunkships(it2, eit2, Ships2, P2board);
            printBothHidden(P1board,P2board);
            if(Ships2.begin()==Ships2.end()){
                win1P();
                break;
            }
            eit1++;
            if(eit1 == Ships1.end()) eit1=Ships1.begin();

            //========================================================================================
            //========================================================================================
            //========================================================================================
            cout<<"Player2's TURN!!!!!"<<endl;
            cout<<"Player2's TURN!!!!!"<<endl;
            cout<<"Player2's TURN!!!!!"<<endl;
            cout<<"Your have "<<Cost1<<" dollars."<<endl;
            (*eit2)->attack(P1game,P1board,Cost2);
            rm_sunkships(it1, eit1, Ships1, P1board);
            printBothHidden(P1board,P2board);
            if(Ships1.begin()==Ships1.end()){
                win2P();
                break;
            }
            eit2++;
            if(eit2 == Ships2.end()) eit2=Ships2.begin();
        }
    }
    //=================================Game mode2=============================
    //====================================END=================================
}



