#pragma once
#ifndef DRAWING
#define DRAWING
#include "graphics.h"
#include "extgraph.h"

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

void defineColor();  //������ɫ 
void drawBlock(block);  //������ʯ����ʯ 
void eraseBlock(block);  //��������
void drawScene();  //������� 

#endif
