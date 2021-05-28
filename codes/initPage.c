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
						case 0: //�˳���Ϸ 
							quitGame();
							break; 
						case 1://��Ϸ���� 
							gameHelp();
							break;
						case 2://��ӡ���а� 
							showRank();
							break;
						case 3:
							//������Ϸ
							isGame = 1;
							isInit = 0;
							loadGame();
							drawMenu();
							initGame();
						case 4:
							//��ʼ��Ϸ
							initGame();
							stopBGM();
							isGame = 1;
							isInit = 0;
							drawMenu();
							welcomeMusic();
						default:
							break;
				}
			}
			default:
				break;
		}
	}
}


