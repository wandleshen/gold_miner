#ifndef MUSIC

#define MUSIC
#include <stdio.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <string.h>
#pragma comment (lib , "winmm.lib")


//主要函数
void playMusic(char *sourceFilePath);/*通用播放函数，参数为音频源文件的相对路径或者是绝对路径，此文件只会被播放一次*/
void loopPlayMusic(char *sourceFilePath);/*用法和上述的函数相同，但是注意此函数会循环播放音乐，并且此函数使用饿音频文件只能是wav格式文件*/
void stopBGM();/*停止所有音乐的播放*/ 
void welcomeMusic();/*开始界面的音乐，由于是循环播放因此在调用stopBGM函数之前不会停止播放*/
void levelChangeMusic();/*关卡切换音乐*/
void addScoreMusic();/*分数增加的时候播放加分音效*/
void diamondMusic();/*抓到钻石*/
void goldMusic();/*抓到金矿*/
void bombMusic();/*使用炸弹的时候播放，但是实际测试的时候发现有一到两秒的延迟（指从音效播放开始计时）*/

#endif