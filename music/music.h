#ifndef MUSIC

#define MUSIC
#include <stdio.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <string.h>
#pragma comment (lib , "winmm.lib")


//��Ҫ����
void playMusic(char *sourceFilePath);/*ͨ�ò��ź���������Ϊ��ƵԴ�ļ������·�����߾���·��,�ļ�ֻ�ᱻ����һ��*/
void loopPlayMusic(char *sourceFilePath);/*�÷�������ĺ�����ͬ������ע����ѭ����������,ע��˺���ʹ�õ��ļ�ֻ����wav��ʽ�ļ�*/
void stopBGM();/*ֹͣ�������ֵĲ��ţ�����mcisendString��*/
void welcomeMusic();/*ѭ�����ſ�ʼ�������֣���Ҫֹͣ���ŵĻ������stopBGM����*/
void levelChangeMusic();/*�ؿ��л�����*/
void addScoreMusic();/*�������ӵ�ʱ�򲥷�*/
void diamondMusic();/*ץ����ʯ��ʱ�򲥷�*/
void goldMusic();/*ץ������ʱ�򲥷�*/
void bombMusic();/*ʹ��ը����ʱ�򲥷�(�����е��ӳ١�����)*/

#endif