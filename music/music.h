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
void playMusic(char *sourceFilePath);/*ͨ�ò��ź���������Ϊ��ƵԴ�ļ������·�������Ǿ���·�������ļ�ֻ�ᱻ����һ��*/
void loopPlayMusic(char *sourceFilePath);/*�÷��������ĺ�����ͬ������ע��˺�����ѭ���������֣����Ҵ˺���ʹ�ö���Ƶ�ļ�ֻ����wav��ʽ�ļ�*/
void stopBGM();/*ֹͣ�������ֵĲ���*/ 
void welcomeMusic();/*��ʼ��������֣�������ѭ����������ڵ���stopBGM����֮ǰ����ֹͣ����*/
void levelChangeMusic();/*�ؿ��л�����*/
void addScoreMusic();/*�������ӵ�ʱ�򲥷żӷ���Ч*/
void diamondMusic();/*ץ����ʯ*/
void goldMusic();/*ץ�����*/
void bombMusic();/*ʹ��ը����ʱ�򲥷ţ�����ʵ�ʲ��Ե�ʱ������һ��������ӳ٣�ָ����Ч���ſ�ʼ��ʱ��*/

#endif