#include "store.h"
#define wHeight GetWindowHeight()
#define wWidth GetWindowWidth()
#define PRICE(i) pow(2, (currentStatus.grades[i] + 1)) * 1000

int isAgree = 0;  //表示是否同意交易 
int isDone = 0;  //表示是否完成交易 
int isStart = 0;  //表示是否开始交易 
void buyStuff(int i);

void showStoreBox(int i){  //展示二次确认框 
	char s[2];
	
	SetPenColor("Beige");
	MovePen(GetWindowWidth() / 2 - 0.5, GetWindowHeight() / 2 - 0.5);
	drawRec(3, 1);
	SetPenColor("Black");
	MovePen(GetWindowWidth() / 2 - 0.4, GetWindowHeight() / 2 + 0.2);
	if (i)
		DrawTextString("您确定要升级吗？");
	else
		DrawTextString("金币不足或已到达等级上限，无法购买");
	MovePen(GetWindowWidth() / 2 - 0.3, GetWindowHeight() / 2 - 0.4);
	DrawLine(0.7, 0);
	DrawLine(0, 0.3);
	DrawLine(-0.7 , 0);
	DrawLine(0, -0.3);
	MovePen(GetWindowWidth() / 2 - 0.2, GetWindowHeight() / 2 - 0.3);
	if (i){
		DrawTextString("给爷买！");
		MovePen(GetWindowWidth() / 2 + 1.3, GetWindowHeight() / 2 - 0.4);
		DrawLine(0.8, 0);
		DrawLine(0, 0.3);
		DrawLine(-0.8 , 0);
		DrawLine(0, -0.3);
		MovePen(GetWindowWidth() / 2 + 1.4, GetWindowHeight() / 2 - 0.3);
		DrawTextString("算了算了");
	}
	else
		DrawTextString("好的吧");
}

void storeMouseEvent(int x, int y, int button, int event){  //商店鼠标事件 
	static int tar = 0;
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);
	
	switch(event){
		case BUTTON_DOWN:
			if (isStart){  //同意框的按键 
				if (mouseX >= GetWindowWidth() / 2 - 0.3 && mouseX <= GetWindowWidth() / 2 + 0.4
				&& mouseY >= GetWindowHeight() / 2 - 0.4 && mouseY <= GetWindowHeight() / 2 - 0.1)
					isAgree = 1;
				else
					isAgree = 0;
				isDone = 1;
				purchaseMusic();
				buyStuff(tar);
			}
			else {
				for (int i = 0; i < 4; i++){  //购买内容 
					if (mouseX >= 4.6 && mouseX <= 5.1
					&& mouseY >= wHeight - 2.7 - i * 1.1 && mouseY <= wHeight - 2.5 - i * 1.1){
						tar = i;
						buyStuff(i);
						isStart = 1;
					}
				}
			}
			
			if (mouseX >= wWidth - 2 && mouseX <= wWidth - 1  //下一关
				&& mouseY >= wHeight - 1 && mouseY <= wHeight - 0.6){
					welcomeMusic();
					isStore = 0;
					isGame = 1;
					++currentStatus.level;
					initGame();
				}
			if (mouseX >= wWidth - 2 && mouseX <= wWidth - 1  //保存游戏
				&& mouseY >= wHeight - 1.5 && mouseY <= wHeight - 1.1){
					saveGame();
					MessageBox(NULL,"保存成功","完成",0);
				}
			break;
	}
}

void buyStuff(int i){
	if (currentStatus.money >= PRICE(i) && currentStatus.grades[i] < 5){
		showStoreBox(1);
		if (isAgree){  //完成交易 
			currentStatus.money -= PRICE(i);
			++currentStatus.grades[i];
			isAgree = 0;
		}
	}
	else
		showStoreBox(0);
	if (isDone){
		drawStore();
	}
	isDone = 0;
	isStart = 0;
}
