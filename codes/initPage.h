#pragma once
#ifndef INITPAGE_BUTTON
#define INITPAGE_BUTTON
#include<stdlib.h>
#include<stdio.h>
#include "graphics.h"
#include "drawing.h"
#include "game.h" 
extern int isGame; //from event.h
extern int isInit;
extern int isStore;
extern Button buttonArray[];

void initPageEvent(int x, int y, int button, int event);  //��ʼ������ؼ��̻ص�����
void disableAllButton(); //ʹ���а�ť��Ч
#endif
