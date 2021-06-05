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
}; //��������

enum{
	WAIT,
	UP,
	DOWN,
	PAUSE
}; //����״̬

enum{
	hookSpeed,
	moreScore,
	stoneValue,
	hookSize
}; //����ָ
extern string username;
extern User currentStatus;
extern int isGame;
extern int isStore;
extern int isInit;
extern int isInput;
extern int speedKey;  //from menu.h  ����������ٶ�
extern textPointer ptr;
void initGame();  //��ʼ����Ϸ����
void gameKeyboardEvent(int key, int event);  //��Ϸ����ؼ��̻ص�����
void gameTimer(int timerID);  //��Ϸ�����ʱ�ӻص�����
void pauseGame();  //��ͣ��Ϸ
void anime();

#endif
