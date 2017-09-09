#pragma once
#ifndef VALUEMAP_H
#define VALUEMAP_H
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
#define SIZE 16
class value_map
{
private:
	int size;
	int map[SIZE][SIZE];
	vector<vector<int> > candidate;
public:
	value_map(char [SIZE][SIZE]);
	value_map(char[SIZE][SIZE], int);
	~value_map();
	bool range_check(int, int);
	pair<int,int> scan_function();
	void map_set();
	void makesure_function(int ,int);
	pair<int,int> random_attack(vector<vector<int> >&,int);
	bool verge_check(int ,int);
	void show_map();
};
pair<int, int> Alphago(char [SIZE][SIZE]);
pair<int, int> THEEYE(char [SIZE][SIZE]);
#endif