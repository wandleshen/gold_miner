#include "event.h"
#include "menu.h"
#include "store.h"

int isMenu = 0;  //是否是菜单操作 
int isStore = 0;  //是否是商店界面 
int isInit = 0;  //是否是初始界面 
int isGame = 0;  //是否是游戏界面 

void MouseEventProcess(int x, int y, int button, int event){
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);
	
	if ((mouseY >= GetWindowHeight() - 0.5 || isMenu) && !isInit)  //有关菜单操作的MouseEvent 
		menuMouseEvent(x, y, button, event);
//	if (isStore)
//		storeMouseEvent(x, y, button, event);
}

void KeyboardEventProcess(int key, int event){
	menuKeyboardEvent(key, event);
}

