#include "initPage.h"

void quitGame(){
	ExitGraphics();
}

void gameHelp(){
	system("notepad _help");
}
int isInBox(Button a, double mouseX, double mouseY){
	//条件是鼠标恰好点击字符串 ,最长的选项长度是4，故乘5 
	return mouseX >= a.x && mouseY <= a.y +0.4 && mouseY >= a.y-0.4;
}

void initPageEvent(int x, int y, int button, int event){
		double mouseX = ScaleXInches(x);
		double mouseY = ScaleXInches(y);

		switch(event){
			case BUTTON_DOWN:{
				if(button == LEFT_BUTTON){
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


