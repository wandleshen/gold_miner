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

void inputKeyBoardEvent(int key,int event); //输入框键盘信息回调函数
void InputCharEvent(char c); //输入框字符信息回调函数
void deleteChar(char c); //删除当前编辑的字符串的指定位置的字符
void insertChar(char c); //在当前编辑的位置插入字符

#endif
