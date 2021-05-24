#include "event.h"
#include "menu.h"

int isMenu = 0;

void MouseEventProcess(int x, int y, int button, int event){
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);
	
	if (mouseY >= GetWindowHeight() - 0.5 || isMenu)  //有关菜单操作的MouseEvent 
		menuMouseEvent(x, y, button, event);
}

void KeyboardEventProcess(int key, int event){
	menuKeyboardEvent(key, event);
}

