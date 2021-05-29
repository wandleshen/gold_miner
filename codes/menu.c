#include "menu.h"
#include "drawing.h"
#define H 0.3
#define W GetWindowWidth() / 3

void drawGame();  //绘出游戏菜单 
void drawTrainer();  //绘出修改器菜单 
void drawHelp();  //绘出帮助菜单
int isShow[3] = {0, 0, 0};  //三个二级菜单显示情况 
int flag = 0;  //表示是否呼出确认框 
int i = -1;
static int isPaused = 0;  //奇奇怪怪莫名其妙的flag，但是想不出更好的方法解决这件事儿
int speedKey = 0;  //表示是否开启超级速度
int isMusicPlaying = 1; //判断音乐是否在播放
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

void showBox(int i){  //展示二次确认框 
	SetPenColor("Beige");
	MovePen(GetWindowWidth() / 2 - 0.5, GetWindowHeight() / 2 - 0.5);
	drawRec(4, 1);
	SetPenColor("Black");
	MovePen(GetWindowWidth() / 2 - 0.4, GetWindowHeight() / 2 + 0.2);
	if (i)
		DrawTextString("您确定要载入游戏吗？未保存的内容都将永久丢失！");
	else
		DrawTextString("您确定要退出游戏吗？未保存的内容都将永久丢失！");
	MovePen(GetWindowWidth() / 2 - 0.3, GetWindowHeight() / 2 - 0.4);
	DrawLine(1.3, 0);
	DrawLine(0, 0.3);
	DrawLine(-1.3 , 0);
	DrawLine(0, -0.3);
	MovePen(GetWindowWidth() / 2 - 0.2, GetWindowHeight() / 2 - 0.3);
	if (i)
		DrawTextString("赶紧给我载入(y)");
	else
		DrawTextString("赶紧给我退出(y)");
	MovePen(GetWindowWidth() / 2 + 1.3, GetWindowHeight() / 2 - 0.4);
	DrawLine(1.5, 0);
	DrawLine(0, 0.3);
	DrawLine(-1.5 , 0);
	DrawLine(0, -0.3);
	MovePen(GetWindowWidth() / 2 + 1.4, GetWindowHeight() / 2 - 0.3);
	DrawTextString("确实是我按错了(n)");
}

void menuMouseEvent(int x, int y, int button, int event){
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);

	switch(event){
		case BUTTON_DOWN:
			
			if (flag){  //按下确认或者取消按键对应操作 
				if (mouseY >= GetWindowHeight() / 2 - 0.4 && mouseY <= GetWindowHeight() / 2 - 0.1
					&& mouseX >= GetWindowWidth() / 2 - 0.3 && mouseX <= GetWindowWidth() / 2 + 0.9){
					if (i == 1){
						loadGame();
						isStore = 1;
						isGame = 0;
						drawStore();
					}
					if (i == 0){
						MovePen(0, 0);
						drawIniPage();
					}
				}
				else{
					if (isStore)
						drawStore();
					if (isGame && !isPaused)
						pauseGame();  //继续游戏
					if (isGame && isPaused)
							drawMainGame();
						
				}
				i = -1;
				flag = 0;
				isMenu = 0;
			}
			
			if (mouseY >= GetWindowHeight() - H){  //绘制最顶层对应菜单的二级菜单
				if (isGame && !isPaused && !(isShow[0] + isShow[1] + isShow[2]))  //在逻辑混乱之中莫名其妙解决了一个问题（所以就这样吧，别动这坨屎山了）
					pauseGame();
				if (mouseX <= W){
					isShow[2] = 0;
					isShow[1] = 0;
					isShow[0] = 1 - isShow[0];
					drawHelp();
					drawTrainer();
					//对应的菜单要最后画，以免被擦除 
					if (isShow[0] == 0){
						drawGame();
						if (isStore)
							drawStore();
						if (isGame && !isPaused)  //没暂停
							pauseGame();
						if (isGame && isPaused)  //暂停了
							drawMainGame();
						isMenu = 0;
					}
					else{
						if (isStore)
							drawStore();
						if (isGame)
							drawMainGame();
						drawGame();
						isMenu = 1;
					}

				}
				else if (mouseX <= 2 * W){
					isShow[2] = 0;
					isShow[1] = 1 - isShow[1];
					isShow[0] = 0;
					drawHelp();
					drawGame();
					if (isShow[1] == 0){
						drawTrainer();
						if (isStore)
							drawStore();
						if (isGame && !isPaused)  //没暂停
							pauseGame();
						if (isGame && isPaused)  //暂停了
							drawMainGame();
						isMenu = 0;
					}
					else{
						if (isStore)
							drawStore();
						if (isGame)
							drawMainGame();
						drawTrainer();
						isMenu = 1;
					}
				}
				else{
					isShow[2] = 1 - isShow[2];
					isShow[1] = 0;
					isShow[0] = 0;
					drawGame();
					drawTrainer();
					if (isShow[2] == 0){
						drawHelp();
						if (isStore)
							drawStore();
						if (isGame && !isPaused)  //没暂停
							pauseGame();
						if (isGame && isPaused)  //暂停了
							drawMainGame();
						isMenu = 0;
					}
					else{
						if (isStore)
							drawStore();
						if (isGame)
							drawMainGame();
						drawHelp();
						isMenu = 1;
					}
				}
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
				if (isStore)
					drawStore();
				if (isGame && !isPaused)
					pauseGame();
				if (isGame && isPaused)
					drawMainGame();
			}
			
			else if (isShow[1]){  //有关修改器菜单的内容
				if (mouseX >= W && mouseX <= 2 * W){
					if (mouseY >= GetWindowHeight() - 2 * H){  //究极速度
						speedKey = 1 - speedKey;
					}
					else if (mouseY >= GetWindowHeight() - 3 * H){  //更多时间
						if (isGame)
							countdown += 15000;
					}
					else if (mouseY >= GetWindowHeight() - 4 * H){  //无限金钱
						currentStatus.money = 9999999;
					}
				}
				isShow[1] = 0;
				drawTrainer();
				isMenu = 0;
				if (isStore)
					drawStore();
				if (isGame && !isPaused)
					pauseGame();
				if (isGame && isPaused)
					drawMainGame();
			}
			
			else if (isShow[0]){  //有关游戏菜单的内容
				if (mouseX <= W){
					if (mouseY >= GetWindowHeight() - 2 * H){  //载入游戏 
						flag = 1;
						i = 1;
					}
					else if (mouseY >= GetWindowHeight() - 3 * H){  //暂停 
						if (isGame)
							isPaused = 1 - isPaused;
					}
					else if (mouseY >= GetWindowHeight() - 4 * H){  //静音
						if(isMusicPlaying) stopBGM();
						else welcomeMusic();
						isMusicPlaying = !isMusicPlaying; 
					}
					else if (mouseY >= GetWindowHeight() - 5 * H){  //退出 
						flag = 1;
						i = 0;
					}
				}
				isShow[0] = 0;
				drawGame();
				isMenu = 0;
				if (isStore)
					drawStore();
				if (isGame && flag || isPaused)
					drawMainGame();
				if (isGame && !flag && !isPaused)
					pauseGame();
				if (flag){
					showBox(i);
					isMenu = 1;  //继续调用menu相关操作 
				}

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
					showBox(1);
					flag = 1;
					i = 1;
					isMenu = 1;
					break;
				case 'P': case 'p':  //Pause
					isPaused = 1 - isPaused; 
					pauseGame();
					break;
				case 'M': case 'm':  //Mute
					break;
				case 'E': case 'e':  //Exit
					showBox(0);
					flag = 1;
					i = 0;
					isMenu = 1;
					break;
				case 'Y': case 'y':
					if (flag){
						if (i == 1){
							loadGame();
							isStore = 1;
							isGame = 0;
							drawStore();
						}
						if (i == 0){
							MovePen(0, 0);
							drawIniPage();
							isStore = 0;
							isGame = 0;
							isInit = 1;
						}
						i = -1;
						flag = 0;
						isMenu = 0;
					}
					break;
				case 'N': case 'n':
					if (flag){
						if (isStore)
							drawStore();
						if (isGame && isPaused)
							drawMainGame();
						if (isGame && !isPaused)
							pauseGame();
						i = -1;
						flag = 0;
						isMenu = 0;
					}
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
		"Higher Speed",
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

