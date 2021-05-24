#include "menu.h"
#include "drawing.h"
#define H 0.3
#define W GetWindowWidth() / 3

void drawGame();  //�����Ϸ�˵� 
void drawTrainer();  //����޸����˵� 
void drawHelp();  //��������˵�
int isShow[3] = {0, 0, 0};  //���������˵���ʾ��� 
extern int isMenu;  //from event.h ��ʾ���ڽ��в˵���ز��� 

void drawMenu(){  //��������˵��� 
	SetPenColor("Blue");
	MovePen(0, GetWindowHeight() - H);
	DrawLine(3 * W, 0);
	MovePen(W, GetWindowHeight() - H);
	DrawLine(0, H);
	MovePen(2 * W, GetWindowHeight() - H);
	DrawLine(0, H);
	MovePen(0.1, GetWindowHeight() - 0.2);
	DrawTextString("��Ϸ");
	MovePen(0.1 + W, GetWindowHeight() - 0.2);
	DrawTextString("�޸���");
	MovePen(0.1 + 2 * W, GetWindowHeight() - 0.2);
	DrawTextString("����");
}

void menuMouseEvent(int x, int y, int button, int event){
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);
	
	switch(event){
		case BUTTON_DOWN:
			if (mouseY >= GetWindowHeight() - H){  //��������Ӧ�˵��Ķ����˵�
				if (mouseX <= W){
					isShow[2] = 0;
					isShow[1] = 0;
					isShow[0] = 1 - isShow[0];
					drawHelp();
					drawTrainer();
					drawGame();  //��Ӧ�Ĳ˵�Ҫ��󻭣����ⱻ���� 
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
			
			else if (isShow[2]){  //�йذ����˵�������
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
			
			else if (isShow[1]){  //�й��޸����˵�������  #TODO 
				if (mouseX >= W && mouseX <= 2 * W){
					
				}
				isShow[1] = 0;
				drawTrainer();
				isMenu = 0;
			}
			
			else if (isShow[0]){  //�й���Ϸ�˵�������  #TODO
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

void drawGame(){  //�����Ϸ�˵� 
	string text[4] = {
		"������Ϸ (L)",
		"��ͣ����� (P)",
		"BGM (M)",
		"�˳� (E)"
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

void drawTrainer(){  //����޸����˵� 
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

void drawHelp(){  //��������˵� 
	string text[2] = {
		"������� (H)",
		"��������"
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

