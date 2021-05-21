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
void playMusic(char *sourceFilePath);/*通用播放函数，参数为音频源文件的相对路径或者绝对路径,文件只会被播放一次*/
void loopPlayMusic(char *sourceFilePath);/*用法和上面的函数相同，但是注意是循环播放音乐,注意此函数使用的文件只能是wav格式文件*/
void stopBGM();/*停止所有音乐的播放（包括mcisendString）*/
void welcomeMusic();/*循环播放开始界面音乐，需要停止播放的话请调用stopBGM函数*/
void levelChangeMusic();/*关卡切换音乐*/
void addScoreMusic();/*分数增加的时候播放*/
void diamondMusic();/*抓到钻石的时候播放*/
void goldMusic();/*抓到金矿的时候播放*/
void bombMusic();/*使用炸弹的时候播放(好像有点延迟。。。)*/

#endif