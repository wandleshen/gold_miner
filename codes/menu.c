#include "menu.h"
#include "drawing.h"
#define H 0.3
#define W GetWindowWidth() / 3

void drawGame();  //绘出游戏菜单 
void drawTrainer();  //绘出修改器菜单 
void drawHelp();  //绘出帮助菜单
int isShow[3] = {0, 0, 0};  //三个二级菜单显示情况 
extern int isMenu;  //from event.h 表示正在进行菜单相关操作 

void drawMenu(){  //绘出顶部菜单栏 
	SetPenColor("Blue");
	MovePen(0, GetWindowHeight() - H);
	DrawLine(3 * W, 0);
	MovePen(W, GetWindowHeight() - H);
	DrawLine(0, H);
	MovePen(2 * W, GetWindowHeight() - H);
	DrawLine(0, H);
	MovePen(0.1, GetWindowHeight() - 0.2);
	DrawTextString("游戏");
	MovePen(0.1 + W, GetWindowHeight() - 0.2);
	DrawTextString("修改器");
	MovePen(0.1 + 2 * W, GetWindowHeight() - 0.2);
	DrawTextString("帮助");
}

void menuMouseEvent(int x, int y, int button, int event){
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);
	
	switch(event){
		case BUTTON_DOWN:
			if (mouseY >= GetWindowHeight() - H){  //绘制最顶层对应菜单的二级菜单
				if (mouseX <= W){
					isShow[2] = 0;
					isShow[1] = 0;
					isShow[0] = 1 - isShow[0];
					drawHelp();
					drawTrainer();
					drawGame();  //对应的菜单要最后画，以免被擦除 
				}
				else if (mouseX <= 2 * W){
					isShow[2] = 0;
					isShow[1] = 1 - isShow[1];
					isShow[0] = 0;
					drawHelp();
					drawGame();
					drawTrainer();
				}
				else{
					isShow[2] = 1 - isShow[2];
					isShow[1] = 0;
					isShow[0] = 0;
					drawGame();
					drawTrainer();
					drawHelp();
				}
				isMenu = 1;
			}
			
			else if (isShow[2]){  //有关帮助菜单的内容
				if (mouseX >= 2 * W){
					if (mouseY >= GetWindowHeight() - 2 * H)
						system("notepad _help");
					else if(mouseY >= GetWindowHeight() - 3 * H)
						system("notepad _about.us");
				}
				isShow[2] = 0;
				drawHelp();
				isMenu = 0;
			}
			
			else if (isShow[1]){  //有关修改器菜单的内容  #TODO 
				if (mouseX >= W && mouseX <= 2 * W){
					
				}
				isShow[1] = 0;
				drawTrainer();
				isMenu = 0;
			}
			
			else if (isShow[0]){  //有关游戏菜单的内容  #TODO
				if (mouseX <= W){
					
				}
				isShow[0] = 0;
				drawGame();
				isMenu = 0;
			}
			break;
	}
}

void menuKeyboardEvent(int key, int event){
	switch(event){
		case KEY_DOWN:
			switch(key){
				case 'H': case 'h':  //Help
					system("notepad _help");
					break;
				case 'L': case 'l':  //Load Game
					break;
				case 'P': case 'p':  //Pause
					break;
				case 'M': case 'm':  //Mute
					break;
				case 'E': case 'e':  //Exit
					break;
			}
		break;
	}
}

void drawGame(){  //绘出游戏菜单 
	string text[4] = {
		"载入游戏 (L)",
		"暂停与继续 (P)",
		"BGM (M)",
		"退出 (E)"
	};
	
	if (isShow[0] == 0)
		SetEraseMode(1);
	SetPenColor("Blue");
	for (int i = 2; i < 6; i++){
		MovePen(0, GetWindowHeight() - i * H);
		DrawLine(W, 0);
		DrawLine(0, H);
	}
	for (int i = 1; i < 5; i++){
		MovePen(0.1, GetWindowHeight() - 0.2 - i * H);
		DrawTextString(text[i - 1]);
	}
	
	SetEraseMode(0);
}

void drawTrainer(){  //绘出修改器菜单 
	string text[3] = {
		"God Mode",
		"More Time",
		"Infinity Money"
	};
	
	if (isShow[1] == 0)
		SetEraseMode(1);
	SetPenColor("Blue");
	for (int i = 1; i < 4; i++){
		MovePen(W, GetWindowHeight() - i * H);
		DrawLine(0, -H);
		DrawLine(W, 0);
		DrawLine(0, H);
	}
	for (int i = 1; i < 4; i++){
		MovePen(0.1 + W, GetWindowHeight() - 0.2 - i * H);
		DrawTextString(text[i - 1]);
	}
	
	SetEraseMode(0);
}

void drawHelp(){  //绘出帮助菜单 
	string text[2] = {
		"如何游玩 (H)",
		"关于我们"
	};
	
	if (isShow[2] == 0)
		SetEraseMode(1);
	SetPenColor("Blue");
	for (int i = 1; i < 3; i++){
		MovePen(2 * W, GetWindowHeight() - i * H);
		DrawLine(0, -H);
		DrawLine(W, 0);
	}
	for (int i = 1; i < 3; i++){
		MovePen(0.1 + 2 * W, GetWindowHeight() - 0.2 - i * H);
		DrawTextString(text[i - 1]);
	}
	
	SetEraseMode(0);
}

