#pragma once
#ifndef STORE
#define STORE
#include "event.h"
#include "drawing.h"
#include "file.h"

void storeMouseEvent(int x, int y, int button, int event);  //�̵�����¼� 
extern User currentStatus;  //from file.h
extern int isStore;
extern int isGame;

#endif
