#pragma once
#ifndef DRAWING
#define DRAWING
#include "graphics.h"
#include "extgraph.h"

typedef enum{  //矿物类型 
    GOLD,
    STONE,
    DIAMOND
} rockType;

typedef enum{  //矿物大小 
    SMALL,
    MEDIUM,
    LARGE
} rockSize;

typedef struct{
    double x, y;  //矿物位置 
    rockSize size;
    rockType type;
} block;

typedef struct linkBlock{
    block element;
    struct linkBlock* next, *prev;
} linkBlock;

void defineColor();  //定义颜色 
void drawBlock(block);  //绘出金矿石块钻石 
void eraseBlock(block);  //擦除方块
void drawScene();  //绘出场景 

#endif
