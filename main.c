#define DEBUG
#ifdef DEBUG 
#include "codes/drawing.h"
#include "codes/event.h"
#include<stdio.h>

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
	InitConsole();
	defineColor();
	currentStatus.level = 1;
	currentStatus.money = 100000;
	currentStatus.score = 1;
	for(int i = 0; i<4; i++) currentStatus.grades[i] = 0;
	drawIniPage();
	registerKeyboardEvent(KeyboardEventProcess);
	registerMouseEvent(MouseEventProcess);
	registerTimerEvent(TimerEventProcess);
}
#endif
