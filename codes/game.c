#include "game.h"
#define wWidth GetWindowWidth()
#define wHeight GetWindowHeight()
#define PIXELSIZE 0.04
#define PI acos(-1)
#define TIMER 1
#define WIN 2
#define LOSE 3
#define SCORE 4
#define INPUT 5
#define refreshRate 10
#define realX(i) wWidth / 2 - (70 - i * 62) * length + currentLength[i] * cos(angle[i])
#define realY(i) wHeight - 1.4 + 2 * length - currentLength[i] * sin(angle[i])
#define initLength 0.3

int mbflag = 0;  //MessageBox的flag
int target, countdown, condition[3];  //目标分数/时间/状态
double angle[3];  //钩子旋转角度
double currentLength[3];  //钩子当前位置，1是单人模式钩子，0和2是双人模式钩子
const double length = PIXELSIZE / 1.05;  //长度常数
static int dScore, dMoney;  //改变的加分和金钱
double dTheta[3];
 
void drawMiner();  //绘出矿机 
void drawBackground();  //绘出背景
linkBlock* initBlocks();  //生成矿物（双向链表，头链表(head)不储存数据） 
linkBlock* link;  //矿物链
linkBlock* thisRock[3];  //特定矿物

void initGame(){  //初始化新一局游戏
	isGame = 1;
	
	Randomize();
	for (int i = 0; i < 3; i++){
		currentLength[i] = initLength;  //初始化钩子位置
		condition[i] = WAIT;
		angle[i] = PI;
		dTheta[i] = 0;
	}
	link = initBlocks();
	target = 10 * (currentStatus.level + 1) * (currentStatus.level + 2) * (10 + currentStatus.isDoublePlayer * 5);
	countdown = 60000;
	drawMainGame();
	startTimer(TIMER, refreshRate);
}

void drawTarget(){
	char s[50];
    sprintf(s, "当前金钱:%d 当前分数:%d 目标分数:%d 剩余时间:%ds", currentStatus.money, currentStatus.score, target, countdown / 1000);

	SetPenColor("black");
	if (currentStatus.isDoublePlayer)
		MovePen(wWidth / 2 - 2.2, wHeight - 0.5);
	else
    	MovePen(0.1, wHeight * 5 / 6);
    DrawTextString(s);
}

void drawHook(int i){  //画钩子
	double size = 0.15 + currentStatus.grades[3] * 0.05;
	double x = wWidth / 2 - (70 - i * 62) * length;

	SetPenColor("Black");
	MovePen(x, wHeight - 1.4 + 2 * length);
	DrawLine(currentLength[i] * cos(angle[i]), -currentLength[i] * sin(angle[i]));
	DrawLine(size / 3.0 * 4.0 * cos(PI / 4 - angle[i]), size / 3.0 * 4.0 * sin(PI / 4 - angle[i]));
	DrawLine(size * cos(angle[i] - 2 * PI / 3 + 3 * PI / 4), -size * sin(angle[i] - 2 * PI / 3 + 3 * PI / 4));
	MovePen(x + currentLength[i] * cos(angle[i]), wHeight - 1.4 + 2 * length - currentLength[i] * sin(angle[i]));
	DrawLine(size / 3.0 * 4.0 * cos(angle[i] + PI / 4), -size / 3.0 * 4.0 * sin(angle[i] + PI / 4));
	DrawLine(size * cos(2 * PI / 3 + angle[i] - 3 * PI / 4), -size * sin(2 * PI / 3 + angle[i] - 3 * PI / 4));
}

void drawMainGame(){  //绘出主要内容 
	linkBlock* head;
	DisplayClear();
	drawBackground();
	if(currentStatus.isDoublePlayer){
		drawHaiMian(wWidth, wHeight, 0.22 * wWidth, 0.8 * wHeight, 0.0025 * wWidth);
		drawHaiMian(wWidth, wHeight, 0.7 * wWidth, 0.8 * wHeight, 0.0025 * wWidth);
	}
	else
		drawHaiMian(wWidth, wHeight, 0.45 * wWidth, 0.8 * wHeight, 0.0025 * wWidth);
	SetPenColor("Black");
	MovePen(0, wHeight - 1.4);
	DrawLine(wWidth, 0);
	if(currentStatus.isDoublePlayer){
		drawMiner(wWidth / 2 - 75 * length);
		drawMiner(wWidth / 2 + 51 * length);
	}
	else
		drawMiner(wWidth / 2 - 13 * length);
	head = link;
	while(head->next){
		head = head->next;
		drawBlock(head->element);
	}
	drawTarget();
	if(currentStatus.isDoublePlayer){
		drawHook(0);
		drawHook(2);
	}
	else
		drawHook(1);
	drawMenu();
}

void drawBackground(){  //绘出背景
	DrawPic("./media_src/image/bg.bmp");
	SetPenColor("Beige");
	MovePen(0, wHeight);
	drawRec(wWidth, -1.4);
	MovePen(0, wHeight - 1.4);
	SetPenColor("background");
	drawRec(wWidth, -0.6);
}

void drawMiner(double x){  //绘出矿机 
	double length = PIXELSIZE / 1.05;
	
	MovePen(x, wHeight - 1.4 + length);
	
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

linkBlock* getRock(int i){  //判断是否获得矿物  目前来看不稳定
	linkBlock* anchor = link;
	double targetDistance, dx, dy;

	while(anchor->next){
		anchor = anchor->next;
		dx = realX(i) - anchor->element.x;
		dy = realY(i) - anchor->element.y;
		targetDistance = (anchor->element.size + 1.0) * PIXELSIZE * (currentStatus.grades[hookSize] + 6.0);
		if (dx * dx + dy * dy <= targetDistance * targetDistance)
			return anchor;
	}

	return NULL;
}

linkBlock* initBlocks(){  //生成矿物（双向链表，头链表(head)不储存数据） 
	int numbers[6];
	int flag = 0;  //防止循环卡死 
	
	linkBlock* head = (linkBlock*)malloc(sizeof(linkBlock));
	linkBlock* p = head, *next;
	block rock;
	p->next = p->prev = NULL;
	
	numbers[SMALLGOLD] = RandomInteger(1, 5);
	numbers[MIDDLEGOLD] = RandomInteger(1, 2);
	numbers[LARGEGOLD] = RandomInteger(0, 1);
	numbers[SMALLSTONE] = RandomInteger(min(1 + currentStatus.level, 3), min(2 + currentStatus.level, 4));
	numbers[MIDDLESTONE] = RandomInteger(0, min(2 + currentStatus.level, 4));
	numbers[DDIAMOND] = RandomInteger(min(1, 1 + currentStatus.level), min(2 + currentStatus.level, 5));

	if (currentStatus.isDoublePlayer)
		for(int i = 0; i < 6; i++) numbers[i] *= 2;
	
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < numbers[i]; j++){
			next = (linkBlock*)malloc(sizeof(linkBlock));
			rock.size = i % 3;
			rock.type = (i < 3) ? 0 : (i < 5) ? 1 : 2;  //小于3是GOLD， 小于5是STONE，5是DIAMOND
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

void gameKeyboardEvent(int key, int event){  //放下钩子
	if(event == KEY_DOWN && key == VK_DOWN){
		digMusic();
		if (condition[2] == WAIT && currentStatus.isDoublePlayer)
			condition[2] = DOWN;
		if (condition[1] == WAIT && !currentStatus.isDoublePlayer)
			condition[1] = DOWN;
	}
	if(event == KEY_DOWN && (key == 'S' || key == 's')){
		digMusic();
		if (condition[0] == WAIT && currentStatus.isDoublePlayer)
			condition[0] = DOWN;
		if (condition[1] == WAIT && !currentStatus.isDoublePlayer)
			condition[1] = DOWN;
	}
}

void pauseGame() //暂停或者继续游戏游戏
{
    static int preCondition[3];
    if (condition[1] == PAUSE){  //恢复暂停的游戏
        for(int i = 0; i < 3; i++) condition[i] = preCondition[i];
	    startTimer(TIMER, refreshRate);
		drawMainGame();
    }
    else{  //暂停操作
        for(int i = 0; i < 3; i++) preCondition[i] = condition[i];
        for(int i = 0; i < 3; i++) condition[i] = PAUSE;
        cancelTimer(TIMER);
		drawMainGame();
    }
}

void drawScore(){  //绘出加分
	static double time = 0;
	static double dTime = 0.001;
	static char s[10]; 
	if (currentStatus.isDoublePlayer)
		MovePen(wWidth / 2 - 1.5, wHeight - 0.6 - time);
	else
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
				MessageBox(NULL, "恭喜过关，正在进入商店~", "成功", MB_OK);
			}
			isGame = 0;
			isStore = 1;
			drawStore();
			cancelTimer(WIN);
			break;
		case LOSE:
			isGame = 0;
			isInput = 1;
			MovePen(0, 0);
			reDrawIniPage(); 	
			cancelTimer(LOSE);
			ptr = malloc(sizeof(struct Text));
			ptr->x = GetWindowWidth()/2-2;
			ptr->y = GetWindowHeight()/2;
			ptr->curpos = 0;
			ptr->data = malloc(sizeof(10));
			memset(ptr->data,0,10);
			disableAllButton();
			clearScreen();
			startTimer(INPUT,100);
			break;
		case SCORE:
			drawScore();
			break;
		case INPUT:{
			drawInputBox();
			MovePen(ptr->x,ptr->y);
			SetPenColor("white");
			drawRec(4,0.4);
			SetPenColor("black");
			DrawCurSor(ptr->data,ptr->curpos,ptr->x,ptr->y);
			drawText();
			break;
		}
	}
}

void anime(){
	static double thisSpeed[3];
	int i;
	double speed = 0.045 + 0.01 * currentStatus.grades[hookSpeed];
	if (speedKey)
		speed = 0.15;

	for(int i = 0; i < 3; i++) thisSpeed[i] = speed;
	countdown -= 2*refreshRate;

	if(countdown <= 0 || link->next == NULL){
		stopBGM(); 
		cancelTimer(TIMER);
		mbflag = 1;
		if(currentStatus.score >= target)
			startTimer(WIN, 500);
		else{
			//clearScreen();
			startTimer(LOSE,500);
			//GetLine();
			//FreeConsole();
			//startTimer(WIN,500);
		}
	}
	if (!currentStatus.isDoublePlayer) i = 1;
	else i = 0;
	do{
		switch(condition[i]){
			case WAIT:  //钩子愉快环绕
				dTheta[i] += 0.001 * cos(angle[i]);
				angle[i] += dTheta[i];
				break;
			case DOWN:  //钩子下降
				currentLength[i] += speed;
				thisRock[i] = getRock(i);
				for (int j = 0; j < 3; j++){
					if (i != j && thisRock[i] && thisRock[i] == thisRock[j])
						thisRock[i] = NULL;
				}
				if (thisRock[i]){  //抓到矿石
					switch(thisRock[i]->element.type){
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
					condition[i] = UP;
					thisSpeed[i] = speed / (double)(thisRock[i]->element.size + 2);
				}
				else if (realX(i) <= 0.0 || realX(i) >= wWidth || realY(i) <= 0.0){
					condition[i] = UP;
					thisSpeed[i] = 2 * speed;
				}
				break;
			case UP:  //钩子上升
				currentLength[i] -= thisSpeed[i];
				if (thisRock[i]){  //抓到矿石
					eraseBlock(thisRock[i]->element);
					thisRock[i]->element.x += thisSpeed[i] * cos(PI - angle[i]);
					thisRock[i]->element.y += thisSpeed[i] * sin(PI - angle[i]);
				}
				if (currentLength[i] - initLength <= 0.01){
					condition[i] = WAIT;
					if(thisRock[i]){  //得分
						if(thisRock[i]->element.type == GOLD){
							goldMusic();
							dScore = 200 * (1 + thisRock[i]->element.size + currentStatus.grades[moreScore]);
							dMoney = 200 * (1 + thisRock[i]->element.size);
						}
						else if(thisRock[i]->element.type == STONE){
							dScore = 50 * (1 + thisRock[i]->element.size + currentStatus.grades[moreScore]);
							dMoney = 50 * (1 + thisRock[i]->element.size + currentStatus.grades[stoneValue]);
						}
						else{
							diamondMusic();
							dScore = 600 * (currentStatus.grades[moreScore] + 1);
							dMoney = 800;
						}
						thisRock[i]->prev->next = thisRock[i]->next;
						if (thisRock[i]->next)
							thisRock[i]->next->prev = thisRock[i]->prev;
							free(thisRock[i]);
						currentStatus.score += dScore;
						currentStatus.money += dMoney;
						startTimer(SCORE, refreshRate);
					}
				}
				break;
		}
		i += 2;
	}while(i < 3);
	drawMainGame();
}
