#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include "Display.h"

using namespace std;

void instruction(){
	cout<<endl;
	cout<<"███████╗███████╗ █████╗     ██████╗  █████╗ ████████╗████████╗██╗     ███████╗"<<endl
		<<"██╔════╝██╔════╝██╔══██╗    ██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝"<<endl
		<<"███████╗█████╗  ███████║    ██████╔╝███████║   ██║      ██║   ██║     █████╗  "<<endl
		<<"╚════██║██╔══╝  ██╔══██║    ██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  "<<endl
		<<"███████║███████╗██║  ██║    ██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗"<<endl
		<<"╚══════╝╚══════╝╚═╝  ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝"<<endl;
	
	cout<<"                                                                              ,----,       ,----,   ,--,              "<<endl
	    <<"                                                                            ,/   .`|     ,/   .`|,---.'|              "<<endl
	    <<"  .--.--.       ,---,.   ,---,                   ,---,.    ,---,          ,`   .'  :   ,`   .'  :|   | :       ,---,. "<<endl
	    <<" /  /    '.   ,'  .' |  '  .' \\                ,'  .'  \\  '  .' \\       ;    ;     / ;    ;     /:   : |     ,'  .' | "<<endl
	    <<"|  :  /`. / ,---.'   | /  ;    '.            ,---.' .' | /  ;    '.   .'___,/    ,'.'___,/    ,' |   ' :   ,---.'   | "<<endl
	    <<";  |  |--`  |   |   .':  :       \\           |   |  |: |:  :       \\  |    :     | |    :     |  ;   ; '   |   |   .' "<<endl
	    <<"|  :  ;_    :   :  |-,:  |   /\\   \\          :   :  :  /:  |   /\\   \\ ;    |.';  ; ;    |.';  ;  '   | |__ :   :  |-, "<<endl
	    <<" \\  \\    `. :   |  ;/||  :  ' ;.   :         :   |    ; |  :  ' ;.   :`----'  |  | `----'  |  |  |   | :.'|:   |  ;/| "<<endl
	    <<"  `----.   \\|   :   .'|  |  ;/  \\   \\        |   :     \\|  |  ;/  \\   \\   '   :  ;     '   :  ;  '   :    ;|   :   .' "<<endl
	    <<"  __ \\  \\  ||   |  |-,'  :  | \\  \\ ,'        |   |   . |'  :  | \\  \\ ,'   |   |  '     |   |  '  |   |  ./ |   |  |-, "<<endl
	    <<" /  /`--'  /'   :  ;/||  |  '  '--'          '   :  '; ||  |  '  '--'     '   :  |     '   :  |  ;   : ;   '   :  ;/| "<<endl
	    <<"'--'.     / |   |    \\|  :  :                |   |  | ; |  :  :           ;   |.'      ;   |.'   |   ,/    |   |    \\ "<<endl
	    <<"  `--'---'  |   :   .'|  | ,'                |   :   /  |  | ,'           '---'        '---'     '---'     |   :   .' "<<endl
	    <<"            |   | ,'  `--''                  |   | ,'   `--''                                              |   | ,'   "<<endl
	    <<"            `----'                           `----'                                                        `----'     "<<endl;
	cout<<endl;
	
	cout<<WF<<"###################################################################"<<RESET<<endl
		<<WF<<"##"<<RESET<<"                     Welcome to the game                       "<<WF<<"##"<<RESET<<endl
		<<WF<<"##"<<RESET<<"                 Choose the game mode below:                   "<<WF<<"##"<<RESET<<endl
		<<WF<<"##"<<RESET<<"---------------------------------------------------------------"<<WF<<"##"<<RESET<<endl
		<<WF<<"##"<<RESET<<"-No.-|-----------Game Mode-----------|--Difficulty--|---Cost---"<<WF<<"##"<<RESET<<endl
		<<WF<<"##"<<RESET<<"  1  |   "<<YELLOW<<"Player"<<RESET<<"     V.S      "<<GREEN<<"CPU"<<RESET<<"     |     "<<CYAN<<"Easy"<<RESET<<"     |  15,000  "<<WF<<"##"<<RESET<<endl
		<<WF<<"##"<<RESET<<"  2  |   "<<YELLOW<<"Player"<<RESET<<"     V.S      "<<GREEN<<"CPU"<<RESET<<"     |     "<<RED<<"Hard"<<RESET<<"     |  10,000  "<<WF<<"##"<<RESET<<endl
		<<WF<<"##"<<RESET<<"  3  |   "<<YELLOW<<"Player"<<RESET<<"     V.S      "<<GREEN<<"CPU"<<RESET<<"     |     "<<RED<<"Hard"<<RESET<<"     |   3,000  "<<WF<<"##"<<RESET<<endl
		<<WF<<"##"<<RESET<<"  4  |  "<<YELLOW<<"Player 1"<<RESET<<"    V.S   "<<YELLOW<<"Player 2"<<RESET<<"   |     ????     |   5,000  "<<WF<<"##"<<RESET<<endl
		<<WF<<"###################################################################"<<RESET<<endl
		<<endl
		<<"Please enter your choice: ";
	
	cout<<endl;
	cout<<"========================================================================================="<<endl
		<<"      ___       __   __         ___    ___  __     ___       ___     __              ___ "<<endl
		<<"|  | |__  |    /  ` /  \\  |\\/| |__      |  /  \\     |  |__| |__     / _`  /\\   |\\/| |__  "<<endl
		<<"|/\\| |___ |___ \\__, \\__/  |  | |___     |  \\__/     |  |  | |___    \\__> /~~\\  |  | |___ "<<endl
		<<"                                                                                         "<<endl
		<<"========================================================================================="<<endl;


}

void warnAndExit(){
	cout<<endl;
	cout<<"Invalid size or parameter."<<endl;
	cout<<"The size must be larger than 2."<<endl;
	cout<<"Game aborted."<<endl<<endl;
}

void coloredOutput(char ch){
	if((ch>=65 && ch<=68) || ch == 83) cout<<"\033[44;33m"<<ch<<RESET;
	else if(ch==42 || ch==115) cout<<RESET<<ch<<RESET;
	else if(ch==88) cout<<"\033[30;41m"<<ch<<RESET;
	else cout<<ch;
}

void printOneDetail(char dataInput[SIZE][SIZE]){
	char atoz[26];
	int i,j,k,size=SIZE;
	for(i=0;i<26;i++) atoz[i]=i+65;
	cout<<"    ";
	for(i=0;i<size;i++) cout<<" "<<atoz[i]<<"  ";
	cout<<"\n   ";
	for(i=0;i<size;i++) cout<<WF<<"+---"<<RESET;
	cout<<WF<<"+"<<RESET<<endl;
	for(i=0;i<size;i++){
		(i+1>9) ? cout<<i+1<<" " : cout<<i+1<<"  ";
		for(j=0;j<size;j++){
			cout<<WF<<"| ";
			coloredOutput(dataInput[i][j]);
			cout<<WF<<" "<<RESET;
		}
		cout<<WF<<"|"<<RESET<<endl<<"   ";
		 for(j=0;j<size;j++) cout<<WF<<"+---"<<RESET;
		 cout<<WF<<"+"<<RESET<<endl;
	}
	cout<<endl;
}

void printDetail(char dataInputA[SIZE][SIZE],char dataInputB[SIZE][SIZE]){
	char atoz[26];
	int i,j,k,size=SIZE;
	for(i=0;i<26;i++) atoz[i]=i+65;
	cout<<"    ";
	for(i=0;i<size;i++) cout<<" "<<atoz[i]<<"  ";
	cout<<"\t\t    ";
	for(i=0;i<size;i++) cout<<" "<<atoz[i]<<"  ";
	cout<<"\n   ";
	for(i=0;i<size;i++) cout<<WF<<"+---"<<RESET;
	cout<<WF<<"+"<<RESET<<"\t\t   ";
	for(i=0;i<size;i++) cout<<WF<<"+---"<<RESET;
	cout<<WF<<"+"<<RESET<<endl;
	for(i=0;i<size;i++){
		(i+1>9) ? cout<<i+1<<" " : cout<<i+1<<"  ";
		for(j=0;j<size;j++){
			cout<<WF<<"| ";
			coloredOutput(dataInputA[i][j]);
			cout<<WF<<" "<<RESET;
		}
		cout<<WF<<"|\t\t"<<RESET;
		(i+1>9) ? cout<<i+1<<" " : cout<<i+1<<"  ";
		for(j=0;j<size;j++){
			cout<<WF<<"| ";
			coloredOutput(dataInputB[i][j]);
			cout<<WF<<" "<<RESET;
		}
		cout<<WF<<"|"<<RESET<<"\n   ";
		for(j=0;j<size;j++) cout<<WF<<"+---"<<RESET;
		cout<<WF<<"+"<<RESET<<"\t\t   ";
		for(j=0;j<size;j++) cout<<WF<<"+---";
		cout<<WF<<"+"<<RESET<<"\n";
	}
	cout<<endl;
}

void printAHidden(char dataInputA[SIZE][SIZE],char dataInputB[SIZE][SIZE]){
	char atoz[26];
	int i,j,k,size=SIZE;
	for(i=0;i<26;i++) atoz[i]=i+65;
	cout<<"    ";
	for(i=0;i<size;i++) cout<<" "<<atoz[i]<<"  ";
	cout<<"\t\t    ";
	for(i=0;i<size;i++) cout<<" "<<atoz[i]<<"  ";
	cout<<"\n   ";
	for(i=0;i<size;i++) cout<<WF<<"+---";
	cout<<"+"<<RESET<<"\t\t   ";
	for(i=0;i<size;i++) cout<<WF<<"+---";
	cout<<"+"<<RESET<<endl;
	for(i=0;i<size;i++){
		(i+1>9) ? cout<<i+1<<" " : cout<<i+1<<"  ";
		for(j=0;j<size;j++){
			cout<<WF<<"| "<<RESET;
			char t = dataInputA[i][j];
			if(t>=65 && t<=90 && t!=88) cout<<WF<<"  "<<RESET;
			else{
				cout<<WF;
				coloredOutput(t);
				cout<<WF<<" "<<RESET;
			}
		}
		cout<<WF<<"|"<<RESET<<"\t\t";
		(i+1>9) ? cout<<i+1<<" " : cout<<i+1<<"  ";
		for(j=0;j<size;j++){
			cout<<WF<<"| ";
			coloredOutput(dataInputB[i][j]);
			cout<<WF<<" "<<RESET;
		}
		cout<<WF<<"|"<<RESET<<"\n   ";
		for(j=0;j<size;j++) cout<<WF<<"+---"<<RESET;
		cout<<WF<<"+"<<RESET<<"\t\t   ";
		for(j=0;j<size;j++) cout<<WF<<"+---";
		cout<<"+"<<RESET<<"\n";
	}
	cout<<endl;
}


void printBHidden(char dataInputA[SIZE][SIZE],char dataInputB[SIZE][SIZE]){
	char atoz[26];
	int i,j,k,size=SIZE;
	for(i=0;i<26;i++) atoz[i]=i+65;
	cout<<"    ";
	for(i=0;i<size;i++) cout<<" "<<atoz[i]<<"  ";
	cout<<"\t\t    ";
	for(i=0;i<size;i++) cout<<" "<<atoz[i]<<"  ";
	cout<<"\n   ";
	for(i=0;i<size;i++) cout<<WF<<"+---";
	cout<<"+"<<RESET<<"\t\t   ";
	for(i=0;i<size;i++) cout<<WF"+---";
	cout<<"+"<<RESET<<endl;
	for(i=0;i<size;i++){
		(i+1>9) ? cout<<i+1<<" " : cout<<i+1<<"  ";
		for(j=0;j<size;j++){
			cout<<WF<<"| ";
			coloredOutput(dataInputA[i][j]);
			cout<<WF<<" "<<RESET;
		}
		cout<<WF<<"|"<<RESET<<"\t\t";
		(i+1>9) ? cout<<i+1<<" " : cout<<i+1<<"  ";
		for(j=0;j<size;j++){
			cout<<WF<<"| ";
			char t = dataInputB[i][j];
			if(t>=65 && t<=90 && t!=88) cout<<"  ";
			else{
				coloredOutput(t);
				cout<<WF<<" "<<RESET;
			}
		}
		cout<<WF<<"|"<<RESET<<"\n   ";
		for(j=0;j<size;j++) cout<<WF<<"+---";
		cout<<"+"<<RESET<<"\t\t   ";
		for(j=0;j<size;j++) cout<<WF<<"+---";
		cout<<"+"<<RESET<<"\n";
	}
	cout<<endl;
}

void printBothHidden(char dataInputA[SIZE][SIZE], char dataInputB[SIZE][SIZE]){
	char atoz[26];
	int i,j,k,size=SIZE;
	for(i=0;i<26;i++) atoz[i]=i+65;
	cout<<"    ";
	for(i=0;i<size;i++) cout<<" "<<atoz[i]<<"  ";
	cout<<"\t\t    ";
	for(i=0;i<size;i++) cout<<" "<<atoz[i]<<"  ";
	cout<<"\n   ";
	for(i=0;i<size;i++) cout<<WF<<"+---";
	cout<<"+"<<RESET<<"\t\t   ";
	for(i=0;i<size;i++) cout<<WF"+---";
	cout<<"+"<<RESET<<endl;
	for(i=0;i<size;i++){
		(i+1>9) ? cout<<i+1<<" " : cout<<i+1<<"  ";
		for(j=0;j<size;j++){
			cout<<WF<<"| "<<RESET;
            char ta = dataInputA[i][j];
            if(ta>=65 && ta<=90 && ta!=88) cout<<WF<<"  "<<RESET;
				else{
			        cout<<WF;
			        coloredOutput(ta);
			        cout<<WF<<" "<<RESET;
			    }
		    }
            cout<<WF<<"|"<<RESET<<"\t\t";
            (i+1>9) ? cout<<i+1<<" " : cout<<i+1<<"  ";
			for(j=0;j<size;j++){
	            cout<<WF<<"| ";
	            char tb = dataInputB[i][j];
	            if(tb>=65 && tb<=90 && tb!=88) cout<<"  ";
	            else{
		            coloredOutput(tb);
		            cout<<WF<<" "<<RESET;
		        }
		   }
		   cout<<WF<<"|"<<RESET<<"\n   ";
		   for(j=0;j<size;j++) cout<<WF<<"+---";
		   cout<<"+"<<RESET<<"\t\t   ";
		   for(j=0;j<size;j++) cout<<WF<<"+---";
		   cout<<"+"<<RESET<<"\n";
	}
	cout<<endl;
}

void win(){
	cout<<"██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗    ██╗"<<endl
		<<"╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║    ██║"<<endl
		<<" ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║    ██║"<<endl
		<<"  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║    ╚═╝"<<endl
		<<"   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║    ██╗"<<endl
		<<"   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝    ╚═╝"<<endl;
	cout<<endl;
}

void lose(){
	cout<<"██╗   ██╗ ██████╗ ██╗   ██╗    ██╗      ██████╗ ███████╗███████╗    ██╗"<<endl
		<<"╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║     ██╔═══██╗██╔════╝██╔════╝    ██║"<<endl
		<<" ╚████╔╝ ██║   ██║██║   ██║    ██║     ██║   ██║███████╗█████╗      ██║"<<endl
		<<"  ╚██╔╝  ██║   ██║██║   ██║    ██║     ██║   ██║╚════██║██╔══╝      ╚═╝"<<endl
		<<"   ██║   ╚██████╔╝╚██████╔╝    ███████╗╚██████╔╝███████║███████╗    ██╗"<<endl
		<<"   ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝ ╚═════╝ ╚══════╝╚══════╝    ╚═╝"<<endl;
	cout<<endl;
}

void win1P(){
	cout<<" ██╗██████╗     ██╗    ██╗██╗███╗   ██╗██╗"<<endl
		<<"███║██╔══██╗    ██║    ██║██║████╗  ██║██║"<<endl
		<<"╚██║██████╔╝    ██║ █╗ ██║██║██╔██╗ ██║██║"<<endl
		<<" ██║██╔═══╝     ██║███╗██║██║██║╚██╗██║╚═╝"<<endl
		<<" ██║██║         ╚███╔███╔╝██║██║ ╚████║██╗"<<endl
		<<" ╚═╝╚═╝          ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝"<<endl;
	cout<<endl;
}

void win2P(){
	cout<<"██████╗ ██████╗     ██╗    ██╗██╗███╗   ██╗██╗"<<endl
		<<"╚════██╗██╔══██╗    ██║    ██║██║████╗  ██║██║"<<endl
		<<" █████╔╝██████╔╝    ██║ █╗ ██║██║██╔██╗ ██║██║"<<endl
		<<"██╔═══╝ ██╔═══╝     ██║███╗██║██║██║╚██╗██║╚═╝"<<endl
		<<"███████╗██║         ╚███╔███╔╝██║██║ ╚████║██╗"<<endl
		<<"╚══════╝╚═╝          ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝"<<endl;
	cout<<endl;
}
