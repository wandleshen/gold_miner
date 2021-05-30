/*
      .--..--..--..--..--..--.
    .' \  (`._   (_)     _   \
  .'    |  '._)         (_)  |
  \ _.')\      .----..---.   /
  |(_.'  |    /    .-\-.  \  |
  \     0|    |   ( O| O) | o|
   |  _  |  .--.____.'._.-.  |     д��C��̴���ҵ��ȥץˮĸ��~
   \ (_) | o         -` .-`  |
    |    \   |`-._ _ _ _ _\ /
    \    |   |  `. |_||_|   |
    | o  |    \_      \     |     -.   .-.          ���౦����ܰ���ѣ�������������������
    |.-.  \     `--..-'   O |     `.`-' .'
  _.'  .' |     `-.-'      /-.__   ' .-'                      �Լ��������������
.' `-.` '.|='=.='=.='=.='=|._/_ `-'.'
`-._  `.  |________/\_____|    `-.'
   .'   ).| '=' '='\/ '=' |
   `._.`  '---------------'
           //___\   //___\
             ||       ||
             ||_.-.   ||_.-.
            (_.--__) (_.--__)

============================================================================================
�����ߣ�������ƴ������ĸ���򣩣�
		����
			��Ӻ�
				 ׯ���
�����ʹ�������ṩ��libgraphics����б���
�����ڣ�2021/5/20
����޸ģ�2021/5/30
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
