#pragma once
#ifndef EVENT
#define EVENT

#include "graphics.h"
#include "menu.h"
#include "store.h"
#include "initPage.h"
#include "game.h"
#include "drawing.h"

void MouseEventProcess(int x, int y, int button, int event);  //�����Ϣ�ص�����
void KeyboardEventProcess(int key, int event);  //������Ϣ�ص�����
void TimerEventProcess(int timerID);  //ʱ����Ϣ�ص�����
void CharEventProcess(char c);  //�ַ���Ϣ�ص�����
void deleteChar(char c); //ɾ����ǰ�༭���ַ�����ָ��λ�õ��ַ�
void insertChar(char c); //�ڵ�ǰ�༭��λ�ò����ַ� 
#endif
