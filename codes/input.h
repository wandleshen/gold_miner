#pragma once

#ifndef _INPUTCODE_
#define _INPUTCODE_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "file.h"
#include "drawing.h"

extern textPointer ptr;
extern int isInput;
extern int isGame;
extern int isInit;
extern char* username;

void inputKeyBoardEvent(int key,int event); //����������Ϣ�ص�����
void InputCharEvent(char c); //������ַ���Ϣ�ص�����
void deleteChar(char c); //ɾ����ǰ�༭���ַ�����ָ��λ�õ��ַ�
void insertChar(char c); //�ڵ�ǰ�༭��λ�ò����ַ�

#endif
