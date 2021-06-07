#include "event.h"


int isMenu = 0;  //�Ƿ��ǲ˵����� 
int isStore = 0;  //�Ƿ����̵���� 
int isInit = 1;  //�Ƿ��ǳ�ʼ���� 
int isGame = 0;  //�Ƿ�����Ϸ���� 
int isRanking = 0; //�Ƿ�������ʾ���а� 
int isInput = 0; //�Ƿ����������û���

void MouseEventProcess(int x, int y, int button, int event){
	//printf("x:%d,y:%d",x,y);
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);
	
	if (event == BUTTON_DOWN && isInit) 
		initPageEvent(x, y, button, event); //��ʼ���水ť������/���а�/�˳���δ��ɿ�ʼ��Ϸ�ͼ�����Ϸ�� 
	if ((mouseY >= GetWindowHeight() - 0.5 || isMenu) && !isInit)  //�йز˵�������MouseEvent 
		menuMouseEvent(x, y, button, event);
	if (isStore)  //�й��̵������MouseEvent 
		storeMouseEvent(x, y, button, event);
}

void KeyboardEventProcess(int key, int event){
	
	if(isRanking && key == VK_ESCAPE && event == KEY_DOWN){
		reDrawIniPage();
	}
	if(!isInit && !isInput){
		menuKeyboardEvent(key, event);
	}
	if(isGame){
		gameKeyboardEvent(key, event);
	}
	if(isInput){
		inputKeyBoardEvent(key,event);
	}
}

void TimerEventProcess(int timerID){
	gameTimer(timerID);
}

void CharEventProcess(char c){
	InputCharEvent(c);
}
