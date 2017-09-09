#define SIZE 16

#ifndef DISPLAY_H
#define DISPLAY_H
	void instruction(void);
	void warnAndExit(void);
	void coloredOutput(char);
	void printOneDetail(char[SIZE][SIZE]);
	void printDetail(char[SIZE][SIZE],char[SIZE][SIZE]);
	void printAHidden(char[SIZE][SIZE],char[SIZE][SIZE]);
	void printBHidden(char[SIZE][SIZE],char[SIZE][SIZE]);
	void printBothHidden(char[SIZE][SIZE],char[SIZE][SIZE]);
	void win(void);
	void lose(void);
	void win1P(void);
	void win2P(void);
#endif

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[034m"
#define PURPLE "\033[035m"
#define CYAN "\033[36m"
#define WHITE_FOREGROUND "\033[30;47m"
#define RESET "\033[0m"
#define WF WHITE_FOREGROUND

