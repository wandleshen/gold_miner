#pragma once
#ifndef DRAWING
#define DRAWING
#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include "file.h"

typedef enum{  //�������� 
    GOLD,
    STONE,
    DIAMOND
} rockType;

typedef enum{  //�����С 
    SMALL,
    MEDIUM,
    LARGE
} rockSize;

typedef struct{
    double x, y;  //����λ�� 
    rockSize size;
    rockType type;
} block;

typedef struct linkBlock{
    block element;
    struct linkBlock* next, *prev;
} linkBlock;

typedef struct button{ //��ʼ���水ť�ṹ 
    double x;
    double y;
    char text[20];
    int isDisabled;
} Button;
extern textPointer ptr;
extern User currentStatus;
extern int isRanking;
extern List userHead;

double buttonYPos[5];
double buttonXPos;
Button buttonArray[5];

void drawRec(double, double);  //������ 
void defineColor();  //������ɫ 
void drawBlock(block);  //������ʯ����ʯ 
void eraseBlock(block);  //��������
void drawIniPage();  //�����ʼ���� 
void drawStore();  //����̵�
void showRank(); //������а�
void drawInputBox();
void DrawCurSor();
#endif
