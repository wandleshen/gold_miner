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
extern textPointer ptr; //文本指针
extern User currentStatus; //当前状态
extern int isRanking; //是否正在显示排行榜
extern List userHead; //用户链表头

double buttonYPos[6]; //按钮竖直位置
double buttonXPos; //按钮水平位置
Button buttonArray[6]; //按钮数组

void drawRec(double, double);  //画填充框 
void defineColor();  //定义颜色 
void drawBlock(block);  //绘出金矿石块钻石 
void eraseBlock(block);  //擦除方块
void drawIniPage();  //绘出开始界面 
void drawStore();  //绘出商店
void showRank(); //输出排行榜
void drawInputBox(); //绘制一个输入窗口
void DrawCurSor(); //绘制光标
void clearScreen(); //清空屏幕
void drawMainGame(); //绘制游戏界面
void reDrawIniPage(); //清空界面并重新绘制主界面
void drawMenu(); //绘制菜单
void movePenRelative(double dx, double dy); //移动相对距离
void drawHaiMian(double width, double height, double mostLeft,double mostLow, double myPixel); //画一个海绵宝宝
void drawEye(double x, double y,double myPixel); //画海绵宝宝的眼睛
void drawHand(double x, double y, double myPixel); //画海绵宝宝的手
void drawPartLow(double x, double y, double myPixel); //画海绵宝宝的下半身
void drawHalfDimmRec(double x, double y, string color1, string color2, int height, double myPixel); //辅助函数
void drawText(); //绘制文本
#endif
