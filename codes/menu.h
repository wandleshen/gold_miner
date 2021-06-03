#pragma once
#ifndef MENU
#define MENU
#include "game.h"
#include "imgui.h"
#include "graphics.h"
#include "extgraph.h"
#include "file.h"
#include "game.h"

extern int isMenu;  //from event.h 表示正在进行菜单相关操作 
extern int isStore;  //from event.h  表示正在商店界面 
extern int isInit;  //from event.h  表示正在开始界面 
extern int isGame;  //from event.h  表示正在游戏界面 
extern int countdown;  //from game.h  表示游戏时间
extern User currentStatus;  //from file.h 表示用户数据 

void drawMenu();  //绘出顶部菜单栏
void menuMouseEvent(int x, int y, int button, int event);  //菜单栏鼠标事件 
void menuKeyboardEvent(int key, int event);  //菜单栏键盘事件 

#endif
