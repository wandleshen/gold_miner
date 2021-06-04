#include "initPage.h"

void quitGame(){
	ExitGraphics();
}

void disableButton(int id){
	buttonArray[id].isDisabled = TRUE;
}
void disableAllButton(){
	for(int i = 0; i < 5; i++){
		buttonArray[i].isDisabled = TRUE;
	}
}
void enableButton(int id){
	buttonArray[id].isDisabled = FALSE;
}
void enableAllButton(){
	for(int i = 0; i < 5; i++){
		buttonArray[i].isDisabled = FALSE;
	}
}
void gameHelp(){
	system("help.pdf");
}
int isInBox(Button a, double mouseX, double mouseY){

	return mouseX >= a.x &&mouseX <= a.x+1 && mouseY <= a.y+1+0.4 && mouseY >= a.y+1-0.4;
}
void startGameFunc(){
	currentStatus.level = 1;
	currentStatus.money = 0;
	currentStatus.score = 0;
	for(int i = 0; i<4; i++) currentStatus.grades[i] = 0;
	initGame();
	stopBGM();
	isGame = 1;
	isInit = 0;
	isStore = 0;
	drawMenu();
	welcomeMusic();
}
void initPageEvent(int x, int y, int button, int event){
		double mouseX = ScaleXInches(x);
		double mouseY = ScaleXInches(y);

		switch(event){
			case BUTTON_DOWN:{
				if(button == LEFT_BUTTON){
					if(isRanking){
						if(mouseX >= GetWindowWidth()/2-0.5&& mouseX <= GetWindowWidth()/2+0.5 && mouseY >= GetWindowHeight()/2+1.5 && mouseY <= GetWindowHeight()/2+2.5){
							reDrawIniPage();
						}
						return;
					}
					int i;
					for(i = 0;i < 6; i++){
						if(isInBox(buttonArray[i],mouseX,mouseY) && buttonArray[i].isDisabled == FALSE) break;
					} 
					if(i == 6) return;
					switch(i){
						case 0: //退出游戏 
							quitGame();
							break; 
						case 1://游戏帮助 
							gameHelp();	
							break;
						case 2://打印排行榜 
							showRank();
							break;
						case 3:
							//继续游戏
							isStore = 1;
							isGame = 0;
							isInit = 0;
							loadGame();
							drawMenu();
							drawStore();
						case 4:
							currentStatus.isDoublePlayer = 1;
							startGameFunc();
							break; 
						case 5:
							//开始游戏
							currentStatus.isDoublePlayer = 0;
							startGameFunc();
						default:
							break;
				}
			}
			default:
				break;
		}
	}
}


