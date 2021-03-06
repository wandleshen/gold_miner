#pragma once
#ifndef GAME
#define GAME
#include "drawing.h"
#include "event.h"
#include "graphics.h"
#include "extgraph.h"
#include "random.h"
#include <stdlib.h>
#include "graphics.h"
#include "drawing.h"
#include "initPage.h"
enum{
	SMALLGOLD,
	MIDDLEGOLD,
	LARGEGOLD,
	SMALLSTONE,
	MIDDLESTONE,
	DDIAMOND
}; //矿物种类

enum{
	WAIT,
	UP,
	DOWN,
	PAUSE
}; //钩子状态

enum{
	hookSpeed,
	moreScore,
	stoneValue,
	hookSize
}; //金手指
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
void anime();

#endif
