#include "drawing.h"
#define PIXELSIZE 0.05
#define heightRatio 0.14
#define widthRatio 0.1
#define indent 0.15
#define wWidth GetWindowWidth()
#define wHeight GetWindowHeight()
#define CURSOR "_"



void drawRec(double dx, double dy){  //画矩形
	StartFilledRegion(1);
	DrawLine(dx, 0);
	DrawLine(0, dy);
	DrawLine(-dx, 0);
	DrawLine(0, -dy);
	EndFilledRegion();
}

void movePenRelative(double dx, double dy){  //移动相对距离
	double x = GetCurrentX();
	double y = GetCurrentY();
	MovePen(x + dx, y + dy);
}

void defineColor(){
	DefineColor("edgeStone", 112 / 255.0, 112 / 255.0, 112 / 255.0);
	DefineColor("darkStone", 117 / 255.0, 117 / 255.0, 117 / 255.0);
	DefineColor("middleStone", 128 / 255.0, 128 / 255.0, 128 / 255.0);
	DefineColor("lightStone", 133 / 255.0, 133 / 255.0, 133 / 255.0);
	DefineColor("dimStone", 144 / 255.0, 144 / 255.0, 144 / 255.0);
	DefineColor("edgeGold", 144 / 255.0, 130 / 255.0, 25 / 255.0);
	DefineColor("darkGold", 237 / 255.0, 220 / 255.0, 50 / 255.0);
	DefineColor("middleGold", 253 / 255.0, 241 / 255.0, 92 / 255.0);
	DefineColor("lightGold", 253 / 255.0, 244 / 255.0, 121 / 255.0);
	DefineColor("dimGold", 254 / 255.0, 250 / 255.0, 180 / 255.0);
	DefineColor("Diamond", 61 / 255.0, 89 / 255.0, 171 / 255.0);
	DefineColor("shadow",108 / 255.0, 97 / 255.0, 97 / 255.0);
	DefineColor("shadowBrown", 102 / 255.0, 51 / 255.0, 0 / 255.0);
	DefineColor("background", 214 / 255.0, 169 / 255.0, 102 / 255.0);
	DefineColor("eye", 0 / 255.0, 51 / 255.0, 51 / 255.0);
	DefineColor("shadowRed", 153 / 255.0, 0, 0);
	DefineColor("tongue", 255 / 255.0, 102 / 255.0, 102 / 255.0);
	DefineColor("tie", 255 / 255.0, 51 / 255.0, 51 / 255.0);
	DefineColor("pants", 204 / 255.0, 102 / 255.0, 0 / 255.0);
	DefineColor("shadowYellow", 204 / 255.0, 204 / 255.0, 0 / 255.0);
	DefineColor("Beige", 245 / 255.0, 245 / 255.0, 220 / 255.0);
	DefineColor("shadowBlue", 0 / 255.0, 204 / 255.0, 204 / 255.0);
	DefineColor("lightMiner", 144 / 255.0, 79 / 255.0, 14 / 255.0);
	DefineColor("darkMiner", 78 / 255.0, 42 / 255.0, 2 / 255.0);
	DefineColor("greyMiner", 128 / 255.0, 128 / 255.0, 128 / 255.0);
	DefineColor("grey", 224 / 255.0, 224 / 255.0, 224 / 255.0);
}


void drawBlock(block tar){
	string color[5];
	double length = (tar.size + 1) * PIXELSIZE;
	
	if (tar.type == DIAMOND){
		SetPenColor("Diamond");
		MovePen(tar.x, tar.y);
		StartFilledRegion(1);
		DrawLine(PIXELSIZE, PIXELSIZE);
    	DrawLine(PIXELSIZE * 2, 0);
    	DrawLine(PIXELSIZE, -PIXELSIZE);
    	DrawLine(-PIXELSIZE * 2, -PIXELSIZE * 2);
    	DrawLine(-PIXELSIZE * 2, PIXELSIZE * 2);
    	EndFilledRegion();
    	return;
	}
	
	if (tar.type == STONE){
		color[0] = "edgeStone";
		color[1] = "darkStone";
		color[2] = "middleStone";
		color[3] = "lightStone";
		color[4] = "dimStone";
	}
	
	if (tar.type == GOLD){
		color[0] = "edgeGold";
		color[1] = "darkGold";
		color[2] = "middleGold";
		color[3] = "lightGold";
		color[4] = "dimGold";
	}
	
	MovePen(tar.x, tar.y);
	
	//大致思路就是逐行绘制矩形
	SetPenColor(color[0]);
	
	movePenRelative(-2 * length, 3 * length);
	for (int i = 4; i <= 8; i += 2){
		drawRec(i * length, length);
		movePenRelative(-length, -length);
	}
	movePenRelative(length, -length);
	drawRec(9 * length, 2 * length);
	movePenRelative(length, -length);
	drawRec(8 * length, length);
	movePenRelative(length, -length);
	drawRec(6 * length, length);
	movePenRelative(length, -length);
	drawRec(4 * length, length);
	
	SetPenColor(color[1]);
	movePenRelative(0, length);
	drawRec(4 * length, length);
	movePenRelative(3 * length, length);
	drawRec(2 * length, length);
	movePenRelative(length, length);
	drawRec(length, length);
	
	SetPenColor(color[2]);
	movePenRelative(-5 * length, -length);
	drawRec(4 * length, length);
	movePenRelative(3 * length, length);
	drawRec(2 * length, length);
	movePenRelative(0, length);
	drawRec(3 * length, length);
	
	SetPenColor(color[3]);
	movePenRelative(-4 * length, -length);
	drawRec(4 * length, length);
	movePenRelative(length, length);
	drawRec(3 * length, length);
	movePenRelative(length, length);
	drawRec(4 * length, length);
	
	SetPenColor(color[4]);
	movePenRelative(-2 * length, -length);
	drawRec(length, length);
	movePenRelative(0, length);
	drawRec(2 * length, length);
	movePenRelative(length, length);
	drawRec(4 * length, length);
}
 
void drawIniPage(){
	welcomeMusic();
	static int flag = 0;
	//第一次进入的时候执行初始化 
	if(flag == 0){
		buttonXPos = (widthRatio+0.5+indent)*wWidth;
		for(int i = 0;i<5;i++){
			buttonYPos[i] = ((4-i+1.7)*heightRatio)*wHeight;
		}
		flag = 1;
	}
    string text[5] = {"开始游戏","继续游戏","排行榜","游戏帮助","退出游戏"};
	for(int i = 0;i<5;i++){
		buttonArray[i].x = buttonXPos;
		buttonArray[i].y = buttonYPos[i];
		strcpy(buttonArray[i].text, text[i]);
		buttonArray[i].isDisabled = FALSE;
	}
    block *tempBlock = (block*)malloc(sizeof(block));
    tempBlock->size = (0.1+heightRatio)*wHeight;
    tempBlock->type = GOLD;
    tempBlock->x = (widthRatio+0.68)*wWidth;
    tempBlock->y = (0.1+heightRatio*5)*wHeight;
    SetPenColor("Beige");
    drawRec(wWidth,wHeight);
    for(int i = 0;i<5;i++){
        drawBlock(*tempBlock);
        SetPenColor("black");
        MovePen(buttonArray[i].x,buttonArray[i].y);
        tempBlock->y -= heightRatio*wHeight;
    }
    for(int i = 0;i<5;i++){
    	MovePen(buttonArray[i].x,buttonArray[i].y);
    	DrawTextString(buttonArray[i].text);
	}
	free(tempBlock);
	drawHaiMian(wWidth, wHeight, 0.15 * wWidth, 0.1 * wHeight, 0.02 * wWidth);
}

/*画一个海绵宝宝（bushi）*/
void drawHaiMian(double width, double height, double mostLeft,double mostLow, double myPixel){
    SetPenColor("black");
    MovePen(mostLeft,mostLow+myPixel*6);
    drawRec(myPixel,20*myPixel);
    MovePen(mostLeft+myPixel,mostLow+26*myPixel);
    drawRec(17*myPixel,myPixel);
    MovePen(mostLeft+18*myPixel,mostLow+26*myPixel);
    drawRec(myPixel,-20*myPixel);
    MovePen(mostLeft+myPixel,mostLow+5*myPixel);
    drawRec(myPixel*17,myPixel);
    drawHalfDimmRec(mostLeft+myPixel, mostLow+6*myPixel, "pants", "brown", 3,myPixel);
    drawHalfDimmRec(mostLeft+myPixel, mostLow+9*myPixel, "white", "dimStone", 1, myPixel);
    drawHalfDimmRec(mostLeft+myPixel, mostLow+10*myPixel, "middleGold", "shadowYellow",16,  myPixel);
	//画眼睛
    drawEye(mostLeft+2*myPixel,mostLow+18*myPixel,myPixel);
	drawEye(mostLeft+8*myPixel,mostLow+18*myPixel,myPixel);
    //画裤子
    SetPenColor("shadowRed");
    MovePen(mostLeft+myPixel*5,mostLow+13*myPixel);
    drawRec(5*myPixel,2*myPixel);
    MovePen(mostLeft+myPixel*6,mostLow+12*myPixel);
    drawRec(myPixel,myPixel);
    MovePen(mostLeft+myPixel*10,mostLow+14*myPixel);
    drawRec(myPixel,myPixel);
    MovePen(mostLeft+myPixel*11,mostLow+15*myPixel);
    drawRec(myPixel,myPixel); 
    SetPenColor("tongue");
    MovePen(mostLeft+myPixel*7,mostLow+12*myPixel);
    drawRec(2*myPixel,myPixel);
    SetPenColor("white");
	MovePen(mostLeft+myPixel*6,mostLow+14*myPixel);
    drawRec(myPixel,myPixel);
    MovePen(mostLeft+myPixel*8,mostLow+14*myPixel);
    drawRec(myPixel,myPixel);
    //画领带
	SetPenColor("tie");
	MovePen(mostLeft+myPixel*7,mostLow+9*myPixel);
	drawRec(myPixel,myPixel);
	SetPenColor("tongue");
	MovePen(mostLeft+myPixel*7,mostLow+7*myPixel);
	drawRec(myPixel,2*myPixel);
	//画腰带
	SetPenColor("black");
	for(int i = 0; i < 4; i++){
		MovePen(mostLeft+myPixel*(2+3*i),mostLow+8*myPixel);
		drawRec(myPixel*2,myPixel);
	}
	//画手
	drawHand(mostLeft+15*myPixel,mostLow+11*myPixel,myPixel);
	//画脚
	SetPenColor("middleGold");
	MovePen(mostLeft+2*myPixel,mostLow+5*myPixel);
	drawRec(myPixel,myPixel);
	SetPenColor("black");
	MovePen(mostLeft+2*myPixel,mostLow+4*myPixel);
	drawRec(myPixel,myPixel);
	drawPartLow(mostLeft+2*myPixel,mostLow+5*myPixel,myPixel);
	drawPartLow(mostLeft+9*myPixel,mostLow+5*myPixel,myPixel);
}

void drawEye(double x, double y,double myPixel){
    string saveColor = GetPenColor();
    SetPenColor("white");
    MovePen(x,y);
    drawRec(5*myPixel,3*myPixel);
    MovePen(x+myPixel,y-myPixel);
    drawRec(2*myPixel,5*myPixel);
    SetPenColor("black");
    MovePen(x+2*myPixel,y);
    drawRec(myPixel,myPixel);
    SetPenColor("eye");
    MovePen(x+2*myPixel,y+myPixel);
    drawRec(myPixel,myPixel);
    MovePen(x+3*myPixel,y);
    drawRec(myPixel,myPixel);
    SetPenColor(saveColor);
}

void drawHand(double x, double y, double myPixel){
	SetPenColor("white");
	MovePen(x,y);
	drawRec(3*myPixel,myPixel);
	SetPenColor("middleGold");
	MovePen(x+3*myPixel,y);
	drawRec(3*myPixel,myPixel);
	MovePen(x+6*myPixel,y);
	drawRec(myPixel,-6*myPixel);
	MovePen(x+5*myPixel,y-2*myPixel);
	drawRec(myPixel,-2*myPixel);
	SetPenColor("black");
	MovePen(x+4*myPixel,y+myPixel);
	drawRec(2*myPixel,myPixel);
	MovePen(x+4*myPixel,y-myPixel);
	drawRec(2*myPixel,myPixel);
	MovePen(x+6*myPixel,y);
	drawRec(myPixel,myPixel);
	MovePen(x+7*myPixel,y);
	drawRec(myPixel,-6*myPixel);
	MovePen(x+6*myPixel,y-7*myPixel);
	drawRec(myPixel,myPixel);
	MovePen(x+5*myPixel,y-6*myPixel);
	drawRec(myPixel,2*myPixel);
	MovePen(x+4*myPixel,y-4*myPixel);
	drawRec(myPixel,2*myPixel);
	MovePen(x+5*myPixel,y-2*myPixel);
	drawRec(myPixel,myPixel);
}

void drawPartLow(double x, double y, double myPixel){
	SetPenColor("middleGold");
	MovePen(x+3*myPixel,y);
	drawRec(myPixel,-2*myPixel);
	SetPenColor("white");
	MovePen(x+3*myPixel,y-3*myPixel);
	drawRec(myPixel,myPixel);
	SetPenColor("black");
	MovePen(x+2*myPixel,y);
	drawRec(myPixel,-5*myPixel);
	MovePen(x+myPixel,y-4*myPixel);
	drawRec(4*myPixel,myPixel);
	MovePen(x+4*myPixel,y-4*myPixel);
	drawRec(myPixel,4*myPixel);
	MovePen(x+3*myPixel,y-5*myPixel);
	drawRec(myPixel,myPixel);
	SetPenColor("brown");
	MovePen(x+2*myPixel,y);
	drawRec(3*myPixel,myPixel);
}

void drawHalfDimmRec(double x, double y, string color1, string color2, int height, double myPixel){
    SetPenColor(color1);
    MovePen(x,y);
    drawRec(14*myPixel,height*myPixel);
    SetPenColor(color2);
    MovePen(x+13*myPixel,y);
    drawRec(4*myPixel,height*myPixel);
}

void drawStore(){
	char s[25];
	string power[4] = {
		"力量增强",
		"得分提升",
		"价值增加",
		"抓钩增大" 
	};
	
	string text[4] = {
		"当你吃下大力丸，你拉钩子变得更加顺手了",
		"技艺高超的矿工总是可以找到更加值钱的矿物",
		"精明的老矿工可以把石头卖出一个好价钱",
		"工欲善其事，必先大其抓钩"
	};
	
	SetFont("微软雅黑");
	MovePen(0, 0);
	SetPenColor("Beige");
    drawRec(wWidth, wHeight - 0.31);
    MovePen(wWidth / 2 - 0.6, wHeight - 1);
    
    //商店标题 
    SetPenColor("Black");
    SetPointSize(40);
    DrawTextString("商店"); 
	MovePen(wWidth / 2 - 1.17, wHeight - 1.25);
	SetPointSize(15);
	DrawTextString("强大的矿工需要强大的能力");
	
	//吉祥物 
	drawHaiMian(wWidth, wHeight, 0.6 * wWidth, 0.15 * wHeight, 0.015 * wWidth);
	
	//剩余货币 
	MovePen(0.5, wHeight - 1.25);
	SetPointSize(20);
	sprintf(s, "当前金钱：%d", currentStatus.money);
	DrawTextString(s);
	
	//四个升级框 
	for (int i = 0; i < 4; i++){
		//升级能力名称 
		MovePen(0.5, wHeight - 2.8 - i * 1.1);
		DrawLine(5, 0);
		DrawLine(0, 1);
		DrawLine(-5, 0);
		DrawLine(0, -1);
		MovePen(0.6, wHeight - 2.4 - i * 1.1);
		SetPointSize(20);
		SetFont("仿宋");
		DrawTextString(power[i]);
		SetPointSize(20);
		//当前等级、简介、价格 
		MovePen(1.5, wHeight - 2.2 - i * 1.1);
		sprintf(s, "Lv.%d", currentStatus.grades[i]);
		DrawTextString(s);
		MovePen(2, wHeight - 2.2 - i * 1.1);
		SetPointSize(12);
		DrawTextString(text[i]);
		SetPointSize(20);
		MovePen(4.6, wHeight - 2.2 - i * 1.1);
		sprintf(s, "$%.0lf", pow(2, (currentStatus.grades[i] + 1)) * 1000);
		if (currentStatus.grades[i] == 5)
			sprintf(s, "N/A");
		DrawTextString(s);
		//可视化框 
		for (int j = 0; j < 5; j++){
			if (j < currentStatus.grades[i])
				StartFilledRegion(1);
			MovePen(1.5 + j * 0.6, wHeight - 2.5 - i * 1.1);
			DrawLine(0.5, 0);
			DrawLine(0, 0.2);
			DrawLine(-0.5, 0);
			DrawLine(0, -0.2);
			if (j < currentStatus.grades[i])
				EndFilledRegion();
		}
		//升级按钮 
		SetPointSize(20);
		MovePen(4.6, wHeight - 2.75 - i * 1.1);
		DrawLine(0.5, 0);
		DrawLine(0, 0.25);
		DrawLine(-0.5, 0);
		DrawLine(0, -0.25);
		MovePen(4.65, wHeight - 2.7 - i * 1.1);
		DrawTextString("升级");
	}
	
	//右上角按钮 
	SetPenColor("Blue");
	
	MovePen(wWidth - 2, wHeight - 1);
	DrawLine(1, 0);
	DrawLine(0, 0.4);
	DrawLine(-1, 0);
	DrawLine(0, -0.4);
	
	MovePen(wWidth - 1.9, wHeight - 0.9);
	DrawTextString("继续游戏");
	
	MovePen(wWidth - 2, wHeight - 1.5); 
	DrawLine(1, 0);
	DrawLine(0, 0.4);
	DrawLine(-1, 0);
	DrawLine(0, -0.4);
	MovePen(wWidth - 1.9, wHeight - 1.4);
	DrawTextString("保存游戏");
	SetPenColor("Black");
	
	SetFont("微软雅黑");
	SetPointSize(15);
}

void showRank(){
	for(int i = 0;i<5;i++) buttonArray[i].isDisabled = TRUE;
	char buffer[30];

	double fontSize = TextStringWidth("1");
	double fontHeight = GetFontHeight();
	SetPenColor("dimGold");
	
	MovePen(wWidth/2-2,wHeight/2+2);
	drawRec(4,-4);
	SetPenColor("black");
	MovePen(wWidth/2-2*fontSize,wHeight/2+2-fontHeight);
	DrawTextString("Rank");
	MovePen(wWidth/2-2,wHeight/2+2-2*fontHeight);
	DrawTextString(" username");
	MovePen(wWidth/2-2*fontSize,wHeight/2+2-2*fontHeight);
	DrawTextString("level");
	MovePen(wWidth/2+1,wHeight/2+2-2*fontHeight);
	DrawTextString("score ");
	loadRank();
	List move = userHead->next;
	int count = 0;
	while(move != NULL){
		//以下不直接使用一个sprintf再Draw并且Draw了一堆空格而不是使用%xd的原因是本地测试这样做会导致只能显示两个用户的数据（不知道为什么），同时调整第二个%d的输出位数的话会导致第三个数据（score）无法显示，可以测试一下 
		MovePen(wWidth/2-2,wHeight/2+2-(2*count+4)*fontHeight);
		DrawTextString(move->userName);
		MovePen(wWidth/2-2*fontSize,wHeight/2+2-(2*count+4)*fontHeight);
		sprintf(buffer,"%d",move->level);
		DrawTextString(buffer);
		MovePen(wWidth/2+1,wHeight/2+2-(2*count+4)*fontHeight);
		sprintf(buffer,"%d ",move->score);
		DrawTextString(buffer);
		count++;
		move = move->next;
	}
	movePenRelative(0,fontHeight);

		
	MovePen(wWidth/2-4*fontSize,wHeight/2-2);
	SetPenColor("shadowBlue");
	drawRec(8*fontSize,2*fontHeight);
	MovePen(wWidth/2-2*fontSize,wHeight/2-2+fontHeight);
	//MovePen(wWidth/2-2*fontSize,wHeight/2-2);
	
	SetPenColor("Beige");
	DrawTextString("关闭");
	 
	isRanking = 1;
} 

void eraseBlock(block tar){
	double length = (tar.size + 1) * PIXELSIZE;
	MovePen(tar.x, tar.y);
	SetEraseMode(1);
	movePenRelative(-4 * length, 4 * length);
	drawRec(10 * length, -9 * length);
	SetEraseMode(0);
}

void reDrawIniPage(){
	isRanking = 0;
	for(int i = 0;i<5;i++) buttonArray[i].isDisabled = FALSE;
	clearScreen();
	drawIniPage();
}
void clearScreen(){
	MovePen(0,0);
	string color = GetPenColor();
	SetPenColor("white");
	drawRec(wWidth,wHeight);
	SetPenColor(color);
}
void drawInputBox(){
	MovePen(0,0);
	SetPenColor("Beige");
	drawRec(wWidth,wHeight); 
	SetPenColor("shadowBlue");
	MovePen(GetWindowWidth()/2-2,GetWindowHeight()/2+1.5);
	DrawTextString("游戏结束！请输入您的大名（最多八位）");
	SetPenColor("grey");
	MovePen(GetWindowWidth()/2-3,GetWindowHeight()/2-1);
	
	drawRec(6,2);
}
void drawText(){
	printf("\ntextx:%lf\n",ptr->x);
	MovePen(ptr->x+0.1,ptr->y+0.1);
	DrawTextString(ptr->data);
}
void DrawCurSor(string str, int curPos, double startx, double starty){
	if (curPos < 0 || curPos > strlen(str)) return;
	printf("\n%lf\n",startx+TextStringWidth(SubString(str, 0, curPos-1)));
	MovePen(startx+TextStringWidth(SubString(str, 0, curPos-1))+0.1, starty+0.1);
	DrawTextString(CURSOR);
}

