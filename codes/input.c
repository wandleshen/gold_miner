#include "input.h"

void inputKeyBoardEvent(int key,int event){
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

void InputCharEvent(char c){
    if(isInput){
		switch(c){	
			case '\r': //输入回车则输入结束，回到开始界面
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




