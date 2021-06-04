#pragma once
#ifndef DRAWING
#define DRAWING
#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include "file.h"
#include "music.h"
#include "strlib.h"
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

typedef struct button{ //开始界面按钮结构 
    double x;
    double y;
    char text[20];
    int isDisabled;
} Button;
extern textPointer ptr;
extern User currentStatus;
extern int isRanking;
extern List userHead;

double buttonYPos[6];
double buttonXPos;
Button buttonArray[6];

void drawRec(double, double);  //画填充框 
void defineColor();  //定义颜色 
void drawBlock(block);  //绘出金矿石块钻石 
void eraseBlock(block);  //擦除方块
void drawIniPage();  //绘出开始界面 
void drawStore();  //绘出商店
void showRank(); //输出排行榜
void drawInputBox();
void DrawCurSor();
void clearScreen();
void reDrawIniPage(); //清空界面并重新绘制主界面
void drawMenu(); //绘制菜单
void movePenRelative(double dx, double dy);
void drawHaiMian(double width, double height, double mostLeft,double mostLow, double myPixel);
void drawEye(double x, double y,double myPixel);
void drawHand(double x, double y, double myPixel);
void drawPartLow(double x, double y, double myPixel);
void drawPartLow(double x, double y, double myPixel);
void drawHalfDimmRec(double x, double y, string color1, string color2, int height, double myPixel);
void drawText(); 
#endif
