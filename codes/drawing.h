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

extern User currentStatus;

void drawRec(double, double);  //������ 
void defineColor();  //������ɫ 
void drawBlock(block);  //������ʯ����ʯ 
void eraseBlock(block);  //��������
void drawIniPage();  //�����ʼ���� 
void drawStore();  //����̵�

#endif
