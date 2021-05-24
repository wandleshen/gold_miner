#pragma once
#ifndef MENU
#define MENU
#include "imgui.h"
#include "graphics.h"
#include "extgraph.h"

void drawMenu();  //绘出顶部菜单栏
void menuMouseEvent(int x, int y, int button, int event);  //菜单栏鼠标事件 
void menuKeyboardEvent(int key, int event);  //菜单栏键盘事件 

#endif
