#include "valueMap.h"
#include<vector>
#include<ctime>
#include<iostream>
#include<iomanip>
#include<utility>
#include<cstdlib>
using namespace std;
value_map::value_map(char a[SIZE][SIZE]) // 吃對方盤面資料
{
	size = SIZE;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			map[i][j] = 0;
			if(a[i][j]=='X' || a[i][j]=='s')
				map[i][j] = -1;
			else if(a[i][j]=='*')
				map[i][j] = -5;
		}
	//show_map();
	map_set();
	candidate.resize(size*size);
	for (int j = 0; j < size*size; j++)
		candidate[j].resize(2);
}
value_map::value_map(char a[SIZE][SIZE] ,int hard) // 吃對方盤面資料
{
	size = SIZE;
	if (hard)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				map[i][j] = 0;
				/*
				if (a[i][j] == 'X' || a[i][j] == 's')
					map[i][j] = -1;
				else if (a[i][j] == '*')
					map[i][j] = -5;*/
				if (a[i][j] == 'A' || a[i][j] == 'B' || a[i][j] == 'C' || a[i][j] == 'D' || a[i][j] == 'S')
					map[i][j] = 10;
			}
	}
	//map_set();
	candidate.resize(size*size);
	for (int j = 0; j < size*size; j++)
		candidate[j].resize(2);
}
value_map::~value_map()
{
	size = 0;
	candidate.clear();
}
bool value_map::range_check(int x, int y)
{
	if (x >= SIZE || y >= SIZE || x < 0 || y < 0)
		return false;
	else
		return true;
}
void value_map::map_set()
{
	for (int x = 0; x < SIZE;x++)
		for (int y = 0; y < SIZE; y++)
		{
			makesure_function(x,y);
			//show_map();
			//system("pause");
		}
}
bool value_map::verge_check(int x, int y)
{
	int verge_result = 0;
	//int verge_while = 0;
	int count = 1; 
	if (range_check(x + 1, y))
		if ((map[x + 1][y] == -5 || map[x + 1][y] == 10)&& (!range_check(x - 1, y)||map[x-1][y]==-1)) //在邊邊
		{
			/*
			if (range_check(x + 1, y + 1))
				if (map[x + 1][y + 1] == 5)
					map[x + 1][y + 1] = 0;
			if (range_check(x + 1, y - 1))
				if (map[x + 1][y - 1] == 5)
					map[x + 1][y - 1] = 0;
			*/
			while (range_check(x + count, y) )
			{
				if (map[x + count][y] == 5|| map[x + count][y] == 0 || map[x + count][y] == 10)
				{
					map[x + count][y] = 10;
					//return true;
					verge_result = 1;
					break;
				}
				count++;
			}
			//return true;
			verge_result = 1;
		}
	count = 1;
	if (range_check(x - 1, y))
		if ((map[x - 1][y] == -5 || map[x-1][y] == 10) && (!(range_check(x + 1, y)) || map[x + 1][y] == -1))//在邊邊
		{
			/*
			if (range_check(x - 1, y + 1))
				if (map[x - 1][y + 1] == 5)
					map[x - 1][y + 1] = 0;
			if (range_check(x - 1, y - 1))
				if (map[x - 1][y - 1] == 5)
					map[x - 1][y - 1] = 0;
			*/
			while (range_check(x - count, y))
			{

				if (map[x - count][y] == 5 || map[x-count][y] == 0 || map[x-count][y] == 10)
				{
					map[x - count][y] = 10;
					//return true;
					verge_result = 1;
					break;
				}
				count++;
			}
			//return true;
			verge_result = 1;
		}
	count = 1;
	if (range_check(x, y + 1))
		if ((map[x][y + 1] == -5 || map[x][y + 1] == 10) && ((!range_check(x, y - 1))||map[x][y-1]==-1))//在邊邊
		{
			/*
			if (range_check(x + 1, y + 1))
				if (map[x + 1][y + 1] == 5)
					map[x + 1][y + 1] = 0;
			if (range_check(x - 1, y - 1))
				if (map[x - 1][y + 1] == 5)
					map[x - 1][y + 1] = 0;
			*/
			while (range_check(x, y + count))
			{
				//cout << "X:" << x << " Y:" << y << " count:"<<count<<"map[x][y+count]"<<map[x][y+count]<<endl;
				if (map[x][y + count] == 5 || map[x][y + count] == 0 || map[x][y + count] == 10)
				{
					//return true;
					verge_result = 1;
					break;
				}
				count++;
			}
			//return true;
			verge_result = 1;
		}
	count = 1;
	if (range_check(x, y - 1))
		if ((map[x][y - 1] == -5 || map[x][y - 1] == 10) && ((!range_check(x, y + 1))||map[x][y+1]==-1))//在邊邊
		{
			/*
			if (range_check(x + 1, y - 1))
				if (map[x + 1][y - 1] == 5)
					map[x + 1][y - 1] = 0;
			if (range_check(x - 1, y - 1))
				if (map[x - 1][y - 1] == 5)
					map[x - 1][y - 1] = 0;
			*/
			while (range_check(x, y - count))
			{
				if (map[x][y - count] == 5 || map[x ][y-count] == 0 || map[x ][y-count] == 10)
				{
					map[x][y - count] = 10;
					//return true;
					verge_result = 1;
					break;
				}
				count++;
				//return true;
				verge_result = 1;
			}
		}
	/*if (verge_result)
		return true;*/
	count = 1;
	//if (x == 0 || y == 0 || x == SIZE-1 || y == SIZE-1)
	
	if (x != 0 && y != 0 && x != SIZE - 1 && y != SIZE - 1) 
		{
			if (range_check(x + 1, y))
			{
				if (map[x + 1][y] == -5)
					goto there;
			}
			if (range_check(x - 1, y))
			{
				if (map[x - 1][y] == -5)
					goto there;
			}
			if (range_check(x, y + 1))
			{
				if (map[x][y + 1] == -5)
					goto there;
			}
			if (range_check(x, y - 1))
			{
				if (map[x][y - 1] == -5)
					goto there;
			}
			return false;
		}
	there:
		while (range_check(x + count, y) && map[x + count][y] == -5)
		{
			if (!range_check(x + count + 1, y) || map[x + count + 1][y] == 10 || map[x + count + 1][y] == -1)
			{
				if (map[x - 1][y] != -5 && map[x - 1][y] != -1&&range_check(x-1, y))
					map[x - 1][y] = 10;
				/*if (range_check(x + 1, y + 1))
					if (map[x + 1][y + 1] == 5)
						map[x + 1][y + 1] = 0;
				if (range_check(x + 1, y - 1))
					if (map[x + 1][y - 1] == 5)
						map[x + 1][y - 1] = 0;*/
				//return true;
				verge_result = 1;
			}
			count++;
		}
		count = 1;

		while (range_check(x - count, y) && map[x - count][y] == -5)
		{
			//cout << "2" << endl;
			if (!range_check(x - count - 1, y) || map[x-count-1][y] == 10 || map[x-count-1][y] == -1)
			{
				if (map[x + 1][y] != -5 && map[x + 1][y] != -1 && range_check(x+1, y))
					map[x + 1][y] = 10;
				/*if (range_check(x - 1, y + 1))
					if (map[x - 1][y + 1] == 5)
						map[x - 1][y + 1] = 0;
				if (range_check(x - 1, y - 1))
					if (map[x - 1][y - 1] == 5)
						map[x - 1][y - 1] = 0;*/
				//return true;
				verge_result = 1;
			}
			count++;
		}

		count = 1;
		while (range_check(x, y + count) && map[x][y + count] == -5)
		{
			//cout << "3" << endl;
			if (!range_check(x, y + count + 1) || map[x][y + count + 1] == 10 || map[x][y + count + 1] == -1)
			{
				if (map[x][y - 1] != -5 && map[x][y - 1] != -1 && range_check(x, y-1))
					map[x][y - 1] = 10;
				/*if (range_check(x + 1, y + 1))
					if (map[x + 1][y + 1] == 5)
						map[x + 1][y + 1] = 0;
				if (range_check(x - 1, y + 1))
					if (map[x - 1][y + 1] == 5)
						map[x - 1][y + 1] = 0;*/
				//return true;
				verge_result = 1;
			}
			count++;
		}
		count = 1;
		while (range_check(x, y - count) && map[x][y - count] == -5)
		{
			//cout << "4" << endl;
			if (!range_check(x, y - count - 1)||map[x][y-count-1]==10||map[x][y-count-1]==-1)
			{
				if (map[x][y + 1] != -5 && map[x][y + 1] != -1 && range_check(x, y+1))
					map[x][y + 1] = 10;
				/*if (range_check(x + 1, y + 1))
					if (map[x + 1][y + 1] == 5)
						map[x + 1][y + 1] = 0;
				if (range_check(x - 1, y + 1))
					if (map[x - 1][y + 1] == 5)
						map[x - 1][y + 1] = 0;*/
				//return true;
				verge_result = 1;
			}
			count++;
		}
		if (verge_result == 1)
			return true;
	return false;
}
void value_map::makesure_function(int x, int y)
{
	//cout << "x:" << x << " y:" << y << " map[x][y]:" << map[x][y] << endl;
	if (map[x][y] == -5)
	{
		map[x][y] = -5;
		if (verge_check(x, y))
		{
			return;
		}
		else if (map[x + 1][y] == -5 || map[x][y + 1] == -5 || map[x - 1][y] == -5 || map[x][y - 1] == -5)
		{
			if (range_check(x + 1, y) && map[x + 1][y] == -5)
			{
				if (map[x - 1][y] == 0)
					map[x - 1][y] = 5;
				if (map[x + 1][y + 1] == 5 && range_check(x+1, y+1))
					map[x + 1][y + 1] = 0;
				if (map[x + 1][y - 1] == 5 && range_check(x+1, y-1))
					map[x + 1][y - 1] = 0;
			}
			if (range_check(x , y+1) && map[x][y + 1] == -5)
			{
				if (map[x][y - 1] == 0)
					map[x][y - 1] = 5;
				if (map[x + 1][y + 1] == 5 && range_check(x+1, y+1))
					map[x + 1][y + 1] = 0;
				if (map[x - 1][y + 1] == 5 && range_check(x-1, y+1))
					map[x - 1][y + 1] = 0;
			}
			if (range_check(x-1,y)&&map[x - 1][y] == -5)
			{
				if (map[x + 1][y] == 0)
					map[x + 1][y] = 5;
				if (map[x - 1][y + 1] == 5 && range_check(x-1, y+1))
					map[x - 1][y + 1] = 0;
				if (map[x - 1][y - 1] == 5 && range_check(x-1, y-1))
					map[x - 1][y - 1] = 0;
			}
			if (range_check(x , y-1) && map[x][y - 1] == -5)
			{
				if (map[x][y + 1] == 0)
					map[x][y + 1] = 5;
				if (map[x + 1][y - 1] == 5 && range_check(x+1, y-1))
					map[x + 1][y - 1] = 0;
				if (map[x - 1][y - 1] == 5 && range_check(x-1, y-1))
					map[x - 1][y - 1] = 0;
			}
		}
		else
		{
			if (range_check(x+1, y ))
			{
				if (map[x + 1][y] == 0)
				map[x + 1][y] = 5;
			}
			if (range_check(x-1, y  ))
			{
				if (map[x - 1][y] == 0)
				map[x - 1][y] = 5;
			}
			if (range_check(x, y - 1))
			{
				if (map[x][y - 1] == 0)
				map[x][y - 1] = 5;
			}
			if (range_check(x,y+1))
			{
				if (map[x][y + 1] == 0)
				map[x][y + 1] = 5;
			}
		}
	}
}
pair<int, int> value_map::scan_function()
{
	int target = -10;
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j]>target)
				target = map[i][j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j] == target)
			{
				candidate[count][0] = i;
				candidate[count][1] = j;
				count++;
			}
		}
	}
	return random_attack(candidate, count);
}
pair<int,int> value_map::random_attack(vector<vector<int> >& a,int n)
{
	int tar = rand() % n;
	pair<int, int> re;
	re.first = candidate[tar][0];
	re.second = candidate[tar][1];
	return re;
}
void value_map::show_map()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << setw(2) << setfill(' ')<<map[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
pair<int, int> Alphago(char map[SIZE][SIZE])
{
	
	value_map a(map);
	//a.show_map();
	return a.scan_function();
}
pair<int, int> THEEYE(char map[SIZE][SIZE])
{
	value_map a(map,1);
	//a.show_map();
	return a.scan_function();
}