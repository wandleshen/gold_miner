#pragma once
#ifndef EVENT
#define EVENT

#include "graphics.h"
#include "menu.h"
#include "store.h"
#include "initPage.h"

void MouseEventProcess(int x, int y, int button, int event);  //���ڷ������event��� 
void KeyboardEventProcess(int key, int event);

#endif
