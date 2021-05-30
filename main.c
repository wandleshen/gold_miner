/*
      .--..--..--..--..--..--.
    .' \  (`._   (_)     _   \
  .'    |  '._)         (_)  |
  \ _.')\      .----..---.   /
  |(_.'  |    /    .-\-.  \  |
  \     0|    |   ( O| O) | o|
   |  _  |  .--.____.'._.-.  |     写完C大程大作业就去抓水母叭~
   \ (_) | o         -` .-`  |
    |    \   |`-._ _ _ _ _\ /
    \    |   |  `. |_||_|   |
    | o  |    \_      \     |     -.   .-.          海绵宝宝温馨提醒：佩戴耳机游玩体验更佳
    |.-.  \     `--..-'   O |     `.`-' .'
  _.'  .' |     `-.-'      /-.__   ' .-'                      以及，球球下手轻点
.' `-.` '.|='=.='=.='=.='=|._/_ `-'.'
`-._  `.  |________/\_____|    `-.'
   .'   ).| '=' '='\/ '=' |
   `._.`  '---------------'
           //___\   //___\
             ||       ||
             ||_.-.   ||_.-.
            (_.--__) (_.--__)

============================================================================================
开发者（按姓氏拼音首字母排序）：
		李湘
			沈加航
				 庄毅非
请务必使用我们提供的libgraphics库进行编译
创建于：2021/5/20
最后修改：2021/5/30
============================================================================================
*/






#include "codes/drawing.h"
#include "codes/event.h"
#include <stdio.h>

int isGameOver = 0;
User currentStatus;

void Main(){
	FILE* fp;
	fp = fopen("Game.save","wb");
	int a = 100;
	for(int i = 0;i<2;i++)
	fwrite(&a,4,1,fp);
	a = 0;
	for(int i = 0;i<5;i++){
		fwrite(&a,4,1,fp);
	}
	fclose(fp);
	InitGraphics();
	defineColor();
	currentStatus.level = 1;
	currentStatus.money = 0;
	currentStatus.score = 0;
	for(int i = 0; i<4; i++) currentStatus.grades[i] = 0;
	drawIniPage();
	registerKeyboardEvent(KeyboardEventProcess);
	registerMouseEvent(MouseEventProcess);
	registerTimerEvent(TimerEventProcess);
	registerCharEvent(CharEventProcess);
}
