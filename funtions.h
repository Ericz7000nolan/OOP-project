#define SIZE 16
#ifndef FUNTIONS_H
#define FUNTIONS_H

std :: pair<int, int> Enterpos();
bool Checkpos(int x,int y,char board[SIZE][SIZE]);
bool CheckEmpty(int x,int y,char board[SIZE][SIZE]);
std :: vector<int> getrand(int n,int div);

#endif
