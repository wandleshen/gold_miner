#pragma once
#ifndef MENU
#define MENU
#include "imgui.h"
#include "graphics.h"
#include "extgraph.h"

void drawMenu();  //��������˵���
void menuMouseEvent(int x, int y, int button, int event);  //�˵�������¼� 
void menuKeyboardEvent(int key, int event);  //�˵��������¼� 

#endif
