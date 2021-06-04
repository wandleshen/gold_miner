#pragma once
#ifndef DRAWING
#define DRAWING
#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include "file.h"
#include "music.h"
#include "strlib.h"
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

double buttonYPos[6];
double buttonXPos;
Button buttonArray[6];

void drawRec(double, double);  //������ 
void defineColor();  //������ɫ 
void drawBlock(block);  //������ʯ����ʯ 
void eraseBlock(block);  //��������
void drawIniPage();  //�����ʼ���� 
void drawStore();  //����̵�
void showRank(); //������а�
void drawInputBox();
void DrawCurSor();
void clearScreen();
void reDrawIniPage(); //��ս��沢���»���������
void drawMenu(); //���Ʋ˵�
void movePenRelative(double dx, double dy);
void drawHaiMian(double width, double height, double mostLeft,double mostLow, double myPixel);
void drawEye(double x, double y,double myPixel);
void drawHand(double x, double y, double myPixel);
void drawPartLow(double x, double y, double myPixel);
void drawPartLow(double x, double y, double myPixel);
void drawHalfDimmRec(double x, double y, string color1, string color2, int height, double myPixel);
void drawText(); 
#endif
