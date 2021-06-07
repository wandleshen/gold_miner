#include "event.h"


int isMenu = 0;  //是否是菜单操作 
int isStore = 0;  //是否是商店界面 
int isInit = 1;  //是否是初始界面 
int isGame = 0;  //是否是游戏界面 
int isRanking = 0; //是否正在显示排行榜 
int isInput = 0; //是否正在输入用户名

void MouseEventProcess(int x, int y, int button, int event){
	//printf("x:%d,y:%d",x,y);
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);
	
	if (event == BUTTON_DOWN && isInit) 
		initPageEvent(x, y, button, event); //开始界面按钮（帮助/排行榜/退出，未完成开始游戏和继续游戏） 
	if ((mouseY >= GetWindowHeight() - 0.5 || isMenu) && !isInit)  //有关菜单操作的MouseEvent 
		menuMouseEvent(x, y, button, event);
	if (isStore)  //有关商店操作的MouseEvent 
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
