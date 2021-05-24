#include "event.h"
#include "menu.h"
#include "store.h"

int isMenu = 0;  //�Ƿ��ǲ˵����� 
int isStore = 0;  //�Ƿ����̵���� 
int isInit = 0;  //�Ƿ��ǳ�ʼ���� 
int isGame = 0;  //�Ƿ�����Ϸ���� 

void MouseEventProcess(int x, int y, int button, int event){
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);
	
	if ((mouseY >= GetWindowHeight() - 0.5 || isMenu) && !isInit)  //�йز˵�������MouseEvent 
		menuMouseEvent(x, y, button, event);
//	if (isStore)
//		storeMouseEvent(x, y, button, event);
}

void KeyboardEventProcess(int key, int event){
	menuKeyboardEvent(key, event);
}

