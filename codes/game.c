#include "game.h"
#define wWidth GetWindowWidth()
#define wHeight GetWindowHeight()
#define PIXELSIZE 0.04
#define PI acos(-1)
#define TIMER 1
#define WIN 2
#define LOSE 3
#define SCORE 4
#define refreshRate 10
#define realX wWidth / 2 - 8 * length + currentLength * cos(angle)
#define realY wHeight - 1.4 + 2 * length - currentLength * sin(angle)
#define initLength 0.3

int mbflag = 0;  //MessageBox��flag
int target, countdown, condition;  //Ŀ�����/ʱ��/״̬
double angle;  //������ת�Ƕ�
double currentLength;  //���ӵ�ǰλ��
const double length = PIXELSIZE / 1.05;  //���ȳ���
static int dScore, dMoney;  //�ı�ļӷֺͽ�Ǯ
double dTheta;
 
void drawMiner();  //������ 
void drawBackground();  //�������
linkBlock* initBlocks();  //���ɿ��˫������ͷ����(head)���������ݣ� 
linkBlock* link;  //������
linkBlock* thisRock;  //�ض�����

void initGame(){  //��ʼ����һ����Ϸ
	isGame = 1;
	
	angle = PI;
	Randomize();
	currentLength = initLength;  //��ʼ������λ��
	link = initBlocks();
	condition = WAIT;
	target = 100 * (currentStatus.level + 1) * (currentStatus.level + 2);
	countdown = 60000;
	dTheta = 0;
	drawMainGame();
	startTimer(TIMER, refreshRate);
}

void drawTarget(){
	char s[50];
    sprintf(s, "��ǰ��Ǯ:%d ��ǰ����:%d Ŀ�����:%d ʣ��ʱ��:%ds", currentStatus.money, currentStatus.score, target, countdown / 1000);

    MovePen(0.1, wHeight * 5 / 6);
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
	DisplayClear();
	drawBackground();
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
	drawMenu();
}

void drawBackground(){  //�������
	DrawPic("./media_src/image/bg.bmp");
	SetPenColor("Beige");
	MovePen(0, wHeight);
	drawRec(wWidth, -1.4);
	MovePen(0, wHeight - 1.4);
	SetPenColor("background");
	drawRec(wWidth, -0.6);
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

linkBlock* getRock(){  //�ж��Ƿ��ÿ���  Ŀǰ�������ȶ�
	linkBlock* anchor = link;
	double targetDistance, dx, dy;

	while(anchor->next){
		anchor = anchor->next;
		dx = realX - anchor->element.x;
		dy = realY - anchor->element.y;
		targetDistance = (anchor->element.size + 1.0) * PIXELSIZE * (currentStatus.grades[hookSize] + 6.0);
		if (dx * dx + dy * dy <= targetDistance * targetDistance)
			return anchor;
	}

	return NULL;
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
			if (i == DDIAMOND)
				rock.size = 0;
			do{
				rock.x = RandomReal(0.1 + 4 * PIXELSIZE * (rock.size + 1), wWidth - 0.1 - 4 * PIXELSIZE * (rock.size + 1));
				rock.y = RandomReal(5 * PIXELSIZE * (rock.size + 1), wHeight - 1.6 - 10 * PIXELSIZE * (rock.size + 1));
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
	if(event == KEY_DOWN && (key == VK_DOWN || key == 's' || key == 'S') && condition == WAIT){
		digMusic();
		condition = DOWN;
	}
}

void pauseGame() //��ͣ���߼�����Ϸ��Ϸ
{
    static int preCondition;
    if (condition == PAUSE){  //�ָ���ͣ����Ϸ
        condition = preCondition;
	    startTimer(TIMER, refreshRate);
		drawMainGame();
    }
    else{  //��ͣ����
        preCondition = condition;
        condition = PAUSE;
        cancelTimer(TIMER);
		drawMainGame();
    }
}

void drawScore(){  //����ӷ�
	static double time = 0;
	static double dTime = 0.001;
	static char s[10]; 
	MovePen(1.0, wHeight * 5 / 6 + 0.1 + time);
	sprintf(s, "+%d    +%d", dMoney, dScore);
	DrawTextString(s);
	time += dTime;

	if (time >= 0.05){
		time = 0;
		cancelTimer(SCORE);

	}
}

void gameTimer(int timerID){
	switch(timerID){
		case TIMER:
			anime();
			break;
		case WIN: 
			levelChangeMusic();
			if(mbflag){
				mbflag = 0;
				MessageBox(NULL, "��ϲ���أ����ڽ����̵�~", "�ɹ�", MB_OK);
			}
			isGame = 0;
			isStore = 1;
			drawStore();
			cancelTimer(WIN);
			break;
		case LOSE:
			isGame = 0;
			isInit = 1;
			MovePen(0, 0);
			reDrawIniPage(); 	
			cancelTimer(LOSE);
			break;
		case SCORE:
			drawScore();
			break;
	}
}

void anime(){
	static double thisSpeed;
	double speed = 0.045 + 0.01 * currentStatus.grades[hookSpeed];
	if (speedKey)
		speed = 0.15;

	thisSpeed = speed;
	countdown -= refreshRate;

	if(countdown <= 0){
		stopBGM(); 
		cancelTimer(TIMER);
		mbflag = 1;
		if(currentStatus.score >= target)
			startTimer(WIN, 500);
		else{
			InitConsole();
			MessageBox(NULL,"�����ն������������û���","�ȴ�����",0);
			fflush(stdin);
			username = GetLine();
			isGameOver = 1;
			saveRank();
			
			printf("��л�������棡%s\n",username);
			printf("��Ϸ���ݱ���ɹ���"); 
			
			//FreeConsole();
			startTimer(LOSE,500);
		}

	switch(condition){
		case WAIT:  //������컷��
			SetEraseMode(1);
			drawHook();
			SetEraseMode(0);
			dTheta += 0.001 * cos(angle);
        	angle += dTheta;
			break;
		case DOWN:  //�����½�
			SetEraseMode(1);
			drawHook();
			SetEraseMode(0);
			currentLength += speed;
			thisRock = getRock();
			if (thisRock){  //ץ����ʯ
				switch(thisRock->element.type){
					case GOLD:
						goldMusic();
						break;
					case  DIAMOND:
						diamondMusic();
						break;
					case STONE:
						rockMusic();
						break;
					default:
						break;
				}
				condition = UP;
				thisSpeed = speed / (double)(thisRock->element.size + 2);
			}
			else if (realX <= 0.0 || realX >= wWidth || realY <= 0.0){
            	condition = UP;
            	thisSpeed = 2 * speed;
        	}
			break;
		case UP:  //��������
			SetEraseMode(1);
			drawHook();
			SetEraseMode(0);
			currentLength -= thisSpeed;
			if (thisRock){  //ץ����ʯ
				eraseBlock(thisRock->element);
				thisRock->element.x += thisSpeed * cos(PI - angle);
				thisRock->element.y += thisSpeed * sin(PI - angle);
			}
			if (fabs(currentLength - initLength) <= 0.01){
				condition = WAIT;
				if(thisRock){  //�÷�
					if(thisRock->element.type == GOLD){
						goldMusic();
						dScore = 200 * (1 + thisRock->element.size + currentStatus.grades[moreScore]);
						dMoney = 200 * (1 + thisRock->element.size);
					}
					else if(thisRock->element.type == STONE){
						dScore = 50 * (1 + thisRock->element.size + currentStatus.grades[moreScore]);
						dMoney = 50 * (1 + thisRock->element.size + currentStatus.grades[stoneValue]);
					}
					else{
						diamondMusic();
						dScore = 600 * (currentStatus.grades[moreScore] + 1);
						dMoney = 800;
					}
					thisRock->prev->next = thisRock->next;
					if (thisRock->next)
						thisRock->next->prev = thisRock->prev;
					free(thisRock);
					currentStatus.score += dScore;
					currentStatus.money += dMoney;
					startTimer(SCORE, refreshRate);
				}
			}
			break;
	}

	drawMainGame();
}
