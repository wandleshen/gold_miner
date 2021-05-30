#pragma once
#ifndef GAME
#define GAME
#include "drawing.h"
#include "event.h"
#include "graphics.h"
#include "extgraph.h"
#include "random.h"
#include <stdlib.h>

typedef enum{
	SMALLGOLD,
	MIDDLEGOLD,
	LARGEGOLD,
	SMALLSTONE,
	MIDDLESTONE,
	DDIAMOND
};

typedef enum{
	WAIT,
	UP,
	DOWN,
	PAUSE
};

typedef enum{
	hookSpeed,
	moreScore,
	stoneValue,
	hookSize
};
extern string username;
extern User currentStatus;
extern int isGame;
extern int isStore;
extern int isInit;
extern int isInput;
extern int speedKey;  //from menu.h  钩子下落的速度
extern textPointer ptr;
void initGame();  //初始化游戏界面
void gameKeyboardEvent(int key, int event);  //游戏内相关键盘回调函数
void gameTimer(int timerID);  //游戏内相关时钟回调函数
void pauseGame();  //暂停游戏

#endif
