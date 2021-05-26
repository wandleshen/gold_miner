#include "initPage.h"

void quitGame(){
	ExitGraphics();
}

void gameHelp(){
	system("notepad _help");
}
int isInBox(Button a, double mouseX, double mouseY){

	return mouseX >= a.x &&mouseX <= a.x+1 && mouseY <= a.y +0.4 && mouseY >= a.y-0.4;
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
					for(i = 0;i < 5; i++){
						if(isInBox(buttonArray[i],mouseX,mouseY) && buttonArray[i].isDisabled == FALSE) break;
					} 
					if(i == 5) return;
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
						case 4:
							//开始游戏
						default:
							break;
				}
			}
			default:
				break;
		}
	}
}


