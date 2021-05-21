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

void defineColor();
void drawBlock(block);
void eraseBlock(block);

#endif
