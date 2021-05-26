//#define DEBUG
#ifdef DEBUG 
#include "codes/drawing.h"
#include "codes/event.h"
#include<stdio.h>

int isGameOver = 0;
User currentStatus;
void Main(){
	FILE* fp;
	fp = fopen("Rank.user","wb");
	if(fp == NULL) return;
    List newUser =  (List) malloc(sizeof(struct userRank));
    newUser->level = 1;
    newUser->score = 1;
    strcpy(newUser->userName,"hello");
    newUser->next = NULL;
    fwrite(&(newUser->level),4,1,fp);
    fwrite(&(newUser->score),4,1,fp);
    fwrite((newUser->userName),10,1,fp);
    newUser->level = 0;
    newUser->score = 0;
    
    for(int i= 1;i<5;i++){
    	fwrite(&(newUser->level),4,1,fp);
    	fwrite(&(newUser->score),4,1,fp);
    	fwrite((newUser->userName),10,1,fp);
	}
	fclose(fp);
	InitGraphics();
	InitConsole();
	defineColor();
	currentStatus.level = 1;
	currentStatus.money = 1;
	currentStatus.score = 1;
	for(int i = 0; i<4; i++) currentStatus.grades[i] = 0;
	drawIniPage();
	registerKeyboardEvent(KeyboardEventProcess);
	registerMouseEvent(MouseEventProcess);
}
#endif
