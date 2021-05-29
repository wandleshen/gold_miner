#include "event.h"


int isMenu = 0;  //�Ƿ��ǲ˵����� 
int isStore = 0;  //�Ƿ����̵���� 
int isInit = 1;  //�Ƿ��ǳ�ʼ���� 
int isGame = 0;  //�Ƿ�����Ϸ���� 
int isRanking = 0; //�Ƿ�������ʾ���а� 
int isInput = 0;
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
		if(event == KEY_DOWN){
			switch(key){
				case VK_LEFT:
					SetPenColor("white");
					
					DrawCurSor(ptr->data,ptr->curpos,ptr->x,ptr->y);
					if(ptr->curpos > 0) ptr->curpos--;
					break;
				case VK_RIGHT:
					SetPenColor("white");
					
					DrawCurSor(ptr->data,ptr->curpos,ptr->x,ptr->y);
					if(ptr->curpos<10 && ptr->curpos<strlen(ptr->data)) ptr->curpos++;
					break;
				default:
					break;
			}
		}
	}
}

void TimerEventProcess(int timerID){
	gameTimer(timerID);
}
void CharEventProcess(char c){
	if(isInput){
		switch(c){	
			case '\r':
				cancelTimer(5);
				username = malloc(11);
				strcpy(username,ptr->data);
				free(ptr);
				isGame = 0;
				isInit = 1;
				saveRank();
				reDrawIniPage();
				break;
			case '\b':
				SetPenColor("white");
				
				DrawCurSor(ptr->data,ptr->curpos,ptr->x,ptr->y);
				deleteChar(c);
				break;
			default:
				printf("default");
				if(strlen(ptr->data) >= 8) return;
				SetPenColor("white");
				
				DrawCurSor(ptr->data,ptr->curpos,ptr->x,ptr->y);
				insertChar(c);
				SetPenColor("red");
				DrawCurSor(ptr->data,ptr->curpos,ptr->x,ptr->y);
				printf("\ncurpos%d\n",ptr->curpos);
				break;
		}
	}
}
void insertChar(char c){
	//printf("curpos:%d\n",ptr->curpos);
	int move = strlen(ptr->data);
	while(move > ptr->curpos){
		ptr->data[move+1] = ptr->data[move];
		move --;
	}
	ptr->data[move] = c;
	ptr->curpos++;
}
void deleteChar(char c){
	int move = ptr->curpos-1;
	int len = strlen(ptr->data);
	while(move < len){
		ptr->data[move] = ptr->data[move+1];
		move++;
	}
	if(ptr->curpos>0) ptr->curpos--;
	
}
