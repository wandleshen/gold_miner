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
void KeyboardEventProcess(int key, int event);  //键盘信息回调函数
void TimerEventProcess(int timerID);  //时钟信息回调函数
void CharEventProcess(char c);  //字符信息回调函数
void deleteChar(char c); //删除当前编辑的字符串的指定位置的字符
void insertChar(char c); //在当前编辑的位置插入字符 
#endif
