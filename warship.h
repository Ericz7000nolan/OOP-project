#ifndef WARSHIP_H
#define WARSHIP_H

/*
std :: pair<int, int> Enterpos();
bool Checkpos(int x,int y,char board[SIZE][SIZE]);
bool CheckEmpty(int x,int y,char board[SIZE][SIZE]);
*/
class warship{
	public:
		warship(int l,std::string s);
		virtual void attack(warship* [SIZE][SIZE], char board[SIZE][SIZE], int &Cost)=0;
		virtual bool checksunk(char board[SIZE][SIZE])=0;
		bool fire(std :: pair<int,int> p, warship* [SIZE][SIZE]);
		//回傳bool表攻擊程序是否有完成, x,y是座標
		void auto_set(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE], int time);
		void set_position(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE]);
		void Normal_fire(warship* gamedata[SIZE][SIZE],char board[SIZE][SIZE]);
		std :: pair<int,int> getposition(int i);

		const int length;
		std :: string Category;
		~warship();
	protected:
		std :: pair<int,int>* position;
		int health;
		bool sunk;
};

class Cunboat : public warship{
	public:
		Cunboat();
		void attack(warship* [SIZE][SIZE], char board[SIZE][SIZE], int &Cost);
		bool Radar(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE]);
		bool checksunk(char board[SIZE][SIZE]);
};

class Destroyer : public warship{
	public:
		Destroyer();
		void attack(warship* [SIZE][SIZE], char board[SIZE][SIZE], int &Cost);
		bool PlasmaConnon(warship* gamedata[SIZE][SIZE], char board[SIZE][SIZE]);
		bool checksunk(char board[SIZE][SIZE]);
};

class Submarine : public warship{
	public:
		Submarine();
		void attack(warship* [SIZE][SIZE], char board[SIZE][SIZE], int &Cost);
		bool Torpedo(warship* [SIZE][SIZE], char board[SIZE][SIZE]);
		bool checksunk(char board[SIZE][SIZE]);
};

class Cruiser : public warship{
	public:
		Cruiser();
		void attack(warship* [SIZE][SIZE], char board[SIZE][SIZE], int &Cost);
		bool MissileVolley(warship* [SIZE][SIZE], char board[SIZE][SIZE]);
		bool checksunk(char board[SIZE][SIZE]);
};

class AircraftCarrier : public warship{
	public:
		AircraftCarrier();
		void attack(warship* [SIZE][SIZE], char board[SIZE][SIZE], int &Cost);
		bool AirStrike(warship* [SIZE][SIZE], char board[SIZE][SIZE]);
		bool checksunk(char board[SIZE][SIZE]);
};


#endif
