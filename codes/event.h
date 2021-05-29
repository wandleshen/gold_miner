#pragma once
#ifndef EVENT
#define EVENT

#include "graphics.h"
#include "menu.h"
#include "store.h"
#include "initPage.h"
#include "game.h"
#include "drawing.h"

void MouseEventProcess(int x, int y, int button, int event);  //鼠标信息回调函数
void KeyboardEventProcess(int key, int event);
void TimerEventProcess(int timerID);
void CharEventProcess(char c);
#endif
