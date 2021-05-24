#ifndef FILECODE
#define FILECODE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

//Ĭ�����洢�����ҵ�����
#define MAX_USER_SAVED 5

//��Ҵ浵���ݽṹ
typedef struct continueUserList{
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
    struct userRank* next;
} *List;
//��ǰ�����Ϸ״̬
extern User currentStatus;
//�ж���Ϸ�Ƿ����
extern int isGameOver;


void saveGame();//����ǰ��Ϸ״̬�洢��saveGame.txt��
void loadGame();//��saveGame.txt�ж�ȡ��ǰ��Ϸ״̬
void saveRank();//�����浵���ļ�Ĭ�ϴ洢5����ҵ�����
void loadRank();//���ļ��е����ݱ��浽userRank.txt�У�ע����ļ���ʼ�����0ֵ��������ɾ��

#endif