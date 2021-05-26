#include "initPage.h"

void quitGame(){
	ExitGraphics();
}

void gameHelp(){
	system("notepad _help");
}
int isInBox(Button a, double mouseX, double mouseY){
	//���������ǡ�õ���ַ��� ,���ѡ�����4���ʳ�5 
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
						case 4:
							//��ʼ��Ϸ
						default:
							break;
				}
			}
			default:
				break;
		}
	}
}


