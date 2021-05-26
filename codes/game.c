#include "game.h"
#define wWidth GetWindowWidth()
#define wHeight GetWindowHeight()
#define PIXELSIZE 0.04
#define PI acos(-1)
#define TIMER 1
#define WIN 2
#define LOSE 3
#define refreshRate 10
#define realX wWidth / 2 - 8 * length + currentLength * cos(angle)
#define realY wHeight - 1.4 + 2 * length - currentLength * sin(angle)
#define initLength 0.3

int target, countdown, condition;  //Ŀ�����/ʱ��/״̬
double angle;  //������ת�Ƕ�
double currentLength;  //���ӵ�ǰλ��
const double length = PIXELSIZE / 1.05;  //���ȳ���

void drawMiner();  //������ 
linkBlock* initBlocks();  //���ɿ��˫������ͷ����(head)���������ݣ� 

linkBlock* link;

void initGame(){  //��ʼ����һ����Ϸ
	angle = PI / 20;
	Randomize();
	currentLength = initLength;  //��ʼ������λ��
	link = initBlocks();
	condition = WAIT;
	target = 100 * (currentStatus.level + 1) * (currentStatus.level + 2);
	countdown = 60000;
	drawMainGame();
	startTimer(TIMER, refreshRate);
}

void drawTarget(){
	char s[50];
    sprintf(s, " ��ǰ������%d  Ŀ�������%d  ʣ��ʱ�䣺%ds", currentStatus.score, target, countdown / 1000);

    MovePen(0.5, wHeight * 5 / 6);
    DrawTextString(s);
}

void drawHook(){  //������
	double size = 0.15 + currentStatus.grades[3] * 0.05;

	SetPenColor("Black");
	MovePen(wWidth / 2 - 8 * length, wHeight - 1.4 + 2 * length);
	DrawLine(currentLength * cos(angle), -currentLength * sin(angle));
	DrawLine(size / 3.0 * 4.0 * cos(PI / 4 - angle), size / 3.0 * 4.0 * sin(PI / 4 - angle));
	DrawLine(size * cos(angle - 2 * PI / 3 + 3 * PI / 4), -size * sin(angle - 2 * PI / 3 + 3 * PI / 4));
	MovePen(wWidth / 2 - 8 * length + currentLength * cos(angle), wHeight - 1.4 + 2 * length - currentLength * sin(angle));
	DrawLine(size / 3.0 * 4.0 * cos(angle + PI / 4), -size / 3.0 * 4.0 * sin(angle + PI / 4));
	DrawLine(size * cos(2 * PI / 3 + angle - 3 * PI / 4), -size * sin(2 * PI / 3 + angle - 3 * PI / 4));
}

void drawMainGame(){  //�����Ҫ���� 
	linkBlock* head;
	SetPenColor("background");
	MovePen(0, 0);
	drawRec(wWidth, wHeight - 0.31);
	drawHaiMian(wWidth, wHeight, 0.45 * wWidth, 0.8 * wHeight, 0.0025 * wWidth);
	SetPenColor("Black");
	MovePen(0, wHeight - 1.4);
	DrawLine(wWidth, 0);
	drawMiner();
	head = link;
	while(head->next){
		head = head->next;
		drawBlock(head->element);
	}
	drawTarget();
	drawHook();
}

void drawMiner(){  //������ 
	double length = PIXELSIZE / 1.05;
	
	MovePen(wWidth / 2 - 13 * length, wHeight - 1.4 + length);
	
	SetPenColor("lightMiner");
	drawRec(length, 8 * length);
	SetPenColor("darkMiner");
	movePenRelative(length, 0);
	drawRec(length * 3, 8 * length);
	movePenRelative(6 * length, 0.0);
	
	SetPenColor("lightMiner");
	drawRec(length, 8 * length);
	SetPenColor("darkMiner");
	movePenRelative(length, 0);
	drawRec(length * 3, 8 * length);
	
	SetPenColor("greyMiner");
	movePenRelative(-5 * length, length);
	for (int i = 0; i < 2; i++){
		drawRec(length, 6 * length);
		movePenRelative(2 * length, 0);
	}

	
	SetPenColor("Black");
	movePenRelative(-5 * length, 0.0);
	for (int i = 0; i < 3; i++){
		drawRec(length, 6 * length);
		movePenRelative(2 * length, 0);
	}
	
	SetPenColor("greyMiner");
	movePenRelative(2 * length, length);
	drawRec(length, length);
	movePenRelative(length, 0.0);
	drawRec(length, -length);
	movePenRelative(length, -length);
	drawRec(length, -2 * length);
	movePenRelative(-13 * length, 0);
	drawRec(length, -length);
	movePenRelative(-length, -length);
	drawRec(length, -2 * length);
}

int isCovered(linkBlock* head, block tar){
	linkBlock* anchor = head;
	double distance;
	
	while(anchor->next){
		anchor = anchor->next;
		distance = (anchor->element.size + tar.size + 2) * PIXELSIZE * 8; 
		if (fabs(anchor->element.x - tar.x) <= distance && fabs(anchor->element.y - tar.y) <= distance)
			return 1;
	}
	
	return 0;
}

linkBlock* initBlocks(){  //���ɿ��˫������ͷ����(head)���������ݣ� 
	int numbers[6];
	int flag = 0;  //��ֹѭ������ 
	
	linkBlock* head = (linkBlock*)malloc(sizeof(linkBlock));
	linkBlock* p = head, *next;
	block rock;
	p->next = p->prev = NULL;
	
	numbers[SMALLGOLD] = RandomInteger(1, 4);
	numbers[MIDDLEGOLD] = RandomInteger(1, 2);
	numbers[LARGEGOLD] = RandomInteger(0, 1);
	numbers[SMALLSTONE] = RandomInteger(min(1 + currentStatus.level, 3), min(2 + currentStatus.level, 4));
	numbers[MIDDLESTONE] = RandomInteger(min(2, 1 + currentStatus.level), min(2 + currentStatus.level, 4));
	numbers[DDIAMOND] = RandomInteger(min(1, 1 + currentStatus.level), min(2 + currentStatus.level, 5));
	
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < numbers[i]; j++){
			next = (linkBlock*)malloc(sizeof(linkBlock));
			rock.size = i % 3;
			rock.type = (i < 3) ? 0 : (i < 5) ? 1 : 2;  //С��3��GOLD�� С��5��STONE��5��DIAMOND
			do{
				rock.x = RandomReal(0.1 + 4 * PIXELSIZE * (rock.size + 1), wWidth - 0.1 - 4 * PIXELSIZE * (rock.size + 1));
				rock.y = RandomReal(5 * PIXELSIZE * (rock.size + 1), wHeight - 1.6 - 8 * PIXELSIZE * (rock.size + 1));
				++flag;
			} while(isCovered(head, rock) && flag <= 50);
			next->element = rock;
			next->prev = p;
			p->next = next;
			p = next;
			p->next = NULL;
		} 
	}
	
	return head;
}

void gameKeyboardEvent(int key, int event){  //���¹���
	if(event == KEY_DOWN && (key == VK_DOWN || key == 's' || key == 'S') && condition == WAIT)
		condition = DOWN;
}

void pauseGame() //��ͣ��Ϸ
{
    static int preCondition;
    if (condition == PAUSE){  //�ָ���ͣ����Ϸ
        condition = preCondition;
	    startTimer(TIMER, refreshRate);
    }
    else{  //��ͣ����
        preCondition = condition;
        condition = PAUSE;
        cancelTimer(TIMER);
    }
}

void gameTimer(int timerID){
	switch(timerID){
		case TIMER:
			anime();
			break;
		case WIN:
			isGame = 0;
			isStore = 1;
			MessageBox(NULL,"��ϲ���أ����������̵�~","�ɹ�",0);
			drawStore();
			cancelTimer(WIN);
			break;
		case LOSE:
			isGame = 0;
			isInit = 1;
			//�����û�������ɼ�  #TODO
			drawIniPage();
			cancelTimer(LOSE);
			break;
	}
}

void anime(){
	static double dTheta = 0;
	static double thisSpeed;
	double speed = 0.075 + 0.025 * currentStatus.grades[0];

	thisSpeed = speed;
	countdown -= refreshRate;
	switch(condition){
		case WAIT:  //������컷��
			dTheta += 0.001 * cos(angle);
        	angle += dTheta;
			break;
		case DOWN:  //�����½�  �й�ץȡ��ʯ#TODO
			currentLength += speed;
			if (realX <= 0.0 || realX >= wWidth || realY <= 0.0){
            	condition = UP;
            	thisSpeed = 2 * speed;
        	}
			break;
		case UP:  //��������
			currentLength -= thisSpeed;
			if (fabs(currentLength - initLength) <= 0.01){
				condition = WAIT;
			}
			break;
	}

	drawMainGame();
}
