#pragma once
#ifndef INITPAGE_BUTTON
#define INITPAGE_BUTTON
#include<stdlib.h>
#include<stdio.h>
#include "graphics.h"
#include "drawing.h"
extern int isGame;
extern int isInit;
extern Button buttonArray[];

void initPageEvent(int x, int y, int button, int event);  //初始界面相关键盘回调函数

#endif
