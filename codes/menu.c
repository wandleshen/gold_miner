#include "menu.h"
#include "drawing.h"
#define H 0.3
#define W GetWindowWidth() / 3

void drawGame();  //�����Ϸ�˵� 
void drawTrainer();  //����޸����˵� 
void drawHelp();  //��������˵�
int isShow[3] = {0, 0, 0};  //���������˵���ʾ��� 
int flag = 0;  //��ʾ�Ƿ����ȷ�Ͽ� 
int i = -1;
static int isPaused = 0;  //����ֹ�Ī�������flag�������벻�����õķ����������¶�
int speedKey = 0;  //��ʾ�Ƿ��������ٶ�
int isMusicPlaying = 1; //�ж������Ƿ��ڲ���
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

void showBox(int i){  //չʾ����ȷ�Ͽ� 
	SetPenColor("Beige");
	MovePen(GetWindowWidth() / 2 - 0.5, GetWindowHeight() / 2 - 0.5);
	drawRec(4, 1);
	SetPenColor("Black");
	MovePen(GetWindowWidth() / 2 - 0.4, GetWindowHeight() / 2 + 0.2);
	if (i)
		DrawTextString("��ȷ��Ҫ������Ϸ��δ��������ݶ������ö�ʧ��");
	else
		DrawTextString("��ȷ��Ҫ�˳���Ϸ��δ��������ݶ������ö�ʧ��");
	MovePen(GetWindowWidth() / 2 - 0.3, GetWindowHeight() / 2 - 0.4);
	DrawLine(1.3, 0);
	DrawLine(0, 0.3);
	DrawLine(-1.3 , 0);
	DrawLine(0, -0.3);
	MovePen(GetWindowWidth() / 2 - 0.2, GetWindowHeight() / 2 - 0.3);
	if (i)
		DrawTextString("�Ͻ���������(y)");
	else
		DrawTextString("�Ͻ������˳�(y)");
	MovePen(GetWindowWidth() / 2 + 1.3, GetWindowHeight() / 2 - 0.4);
	DrawLine(1.5, 0);
	DrawLine(0, 0.3);
	DrawLine(-1.5 , 0);
	DrawLine(0, -0.3);
	MovePen(GetWindowWidth() / 2 + 1.4, GetWindowHeight() / 2 - 0.3);
	DrawTextString("ȷʵ���Ұ�����(n)");
}

void menuMouseEvent(int x, int y, int button, int event){
	double mouseX = ScaleXInches(x);
	double mouseY = ScaleYInches(y);

	switch(event){
		case BUTTON_DOWN:
			
			if (flag){  //����ȷ�ϻ���ȡ��������Ӧ���� 
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
						pauseGame();  //������Ϸ
					if (isGame && isPaused)
							drawMainGame();
						
				}
				i = -1;
				flag = 0;
				isMenu = 0;
			}
			
			if (mouseY >= GetWindowHeight() - H){  //��������Ӧ�˵��Ķ����˵�
				if (isGame && !isPaused && !(isShow[0] + isShow[1] + isShow[2]))  //���߼�����֮��Ī����������һ�����⣨���Ծ������ɣ�������ʺɽ�ˣ�
					pauseGame();
				if (mouseX <= W){
					isShow[2] = 0;
					isShow[1] = 0;
					isShow[0] = 1 - isShow[0];
					drawHelp();
					drawTrainer();
					//��Ӧ�Ĳ˵�Ҫ��󻭣����ⱻ���� 
					if (isShow[0] == 0){
						drawGame();
						if (isStore)
							drawStore();
						if (isGame && !isPaused)  //û��ͣ
							pauseGame();
						if (isGame && isPaused)  //��ͣ��
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
						if (isGame && !isPaused)  //û��ͣ
							pauseGame();
						if (isGame && isPaused)  //��ͣ��
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
						if (isGame && !isPaused)  //û��ͣ
							pauseGame();
						if (isGame && isPaused)  //��ͣ��
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
				if (isStore)
					drawStore();
				if (isGame && !isPaused)
					pauseGame();
				if (isGame && isPaused)
					drawMainGame();
			}
			
			else if (isShow[1]){  //�й��޸����˵�������
				if (mouseX >= W && mouseX <= 2 * W){
					if (mouseY >= GetWindowHeight() - 2 * H){  //�����ٶ�
						speedKey = 1 - speedKey;
					}
					else if (mouseY >= GetWindowHeight() - 3 * H){  //����ʱ��
						if (isGame)
							countdown += 15000;
					}
					else if (mouseY >= GetWindowHeight() - 4 * H){  //���޽�Ǯ
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
			
			else if (isShow[0]){  //�й���Ϸ�˵�������
				if (mouseX <= W){
					if (mouseY >= GetWindowHeight() - 2 * H){  //������Ϸ 
						flag = 1;
						i = 1;
					}
					else if (mouseY >= GetWindowHeight() - 3 * H){  //��ͣ 
						if (isGame)
							isPaused = 1 - isPaused;
					}
					else if (mouseY >= GetWindowHeight() - 4 * H){  //����
						if(isMusicPlaying) stopBGM();
						else welcomeMusic();
						isMusicPlaying = !isMusicPlaying; 
					}
					else if (mouseY >= GetWindowHeight() - 5 * H){  //�˳� 
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
					isMenu = 1;  //��������menu��ز��� 
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

