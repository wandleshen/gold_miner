#pragma once
#ifndef EVENT
#define EVENT
#include "graphics.h"

void MouseEventProcess(int x, int y, int button, int event);  //用于分配各种event情况 
void KeyboardEventProcess(int key, int event);

#endif
