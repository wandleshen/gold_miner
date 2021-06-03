#pragma once
#ifndef MENU
#define MENU
#include "game.h"
#include "imgui.h"
#include "graphics.h"
#include "extgraph.h"
#include "file.h"
#include "game.h"

extern int isMenu;  //from event.h ��ʾ���ڽ��в˵���ز��� 
extern int isStore;  //from event.h  ��ʾ�����̵���� 
extern int isInit;  //from event.h  ��ʾ���ڿ�ʼ���� 
extern int isGame;  //from event.h  ��ʾ������Ϸ���� 
extern int countdown;  //from game.h  ��ʾ��Ϸʱ��
extern User currentStatus;  //from file.h ��ʾ�û����� 

void drawMenu();  //��������˵���
void menuMouseEvent(int x, int y, int button, int event);  //�˵�������¼� 
void menuKeyboardEvent(int key, int event);  //�˵��������¼� 

#endif
