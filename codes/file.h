#pragma once
#ifndef _FILECODE
#define _FILECODE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "genlib.h"
//Ĭ�����洢�����ҵ�����
#define MAX_USER_SAVED 5

//��Ҵ浵���ݽṹ
typedef struct continueUserList{
	int isDoublePlayer;
    int level;
    int score;
    int money;
    int grades[4];
} User;

//���а���ҽṹ
typedef struct userRank{
    int level;
    int score;
    char userName[10]; //�û������9λ
    int isDoublePlayer;
    struct userRank* next;
} *List;

typedef struct Text{
	double x;
	double y;
	string data;
	int curpos;
}*textPointer;
//��ǰ�����Ϸ״̬
extern User currentStatus;
//�ж���Ϸ�Ƿ����
extern int isGame;
textPointer ptr;

void initFile();//��ʼ���ļ� 
void saveGame();//����ǰ��Ϸ״̬�洢��saveGame.txt��
void loadGame();//��saveGame.txt�ж�ȡ��ǰ��Ϸ״̬
void saveRank();//�����浵���ļ�Ĭ�ϴ洢5����ҵ�����
void loadRank();//���ļ��е����ݱ��浽userRank.txt��

#endif
