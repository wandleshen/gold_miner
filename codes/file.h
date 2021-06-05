#pragma once
#ifndef _FILECODE
#define _FILECODE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "genlib.h"
//默认最多存储五个玩家的数据
#define MAX_USER_SAVED 5

//玩家存档数据结构
typedef struct continueUserList{
	int isDoublePlayer;
    int level;
    int score;
    int money;
    int grades[4];
} User;

//排行榜玩家结构
typedef struct userRank{
    int level;
    int score;
    char userName[10]; //用户名最多9位
    int isDoublePlayer;
    struct userRank* next;
} *List;

typedef struct Text{
	double x;
	double y;
	string data;
	int curpos;
}*textPointer;
//当前玩家游戏状态
extern User currentStatus;
//判定游戏是否结束
extern int isGame;
textPointer ptr;

void initFile();//初始化文件 
void saveGame();//将当前游戏状态存储到saveGame.txt中
void loadGame();//从saveGame.txt中读取当前游戏状态
void saveRank();//建立存档，文件默认存储5个玩家的数据
void loadRank();//将文件中的数据保存到userRank.txt中

#endif
