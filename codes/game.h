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
extern int speedKey;  //from menu.h  超级速度开�?
void initGame();
void gameKeyboardEvent(int key, int event);
void gameTimer(int timerID);
void pauseGame();

#endif
