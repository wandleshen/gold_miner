#include "drawing.h"
#define PIXELSIZE 0.05
#define heightRatio 0.14
#define widthRatio 0.1
#define indent 0.15

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
	DefineColor("edgeStone", 112 / 256.0, 112 / 256.0, 112 / 256.0);
	DefineColor("darkStone", 117 / 256.0, 117 / 256.0, 117 / 256.0);
	DefineColor("middleStone", 128 / 256.0, 128 / 256.0, 128 / 256.0);
	DefineColor("lightStone", 133 / 256.0, 133 / 256.0, 133 / 256.0);
	DefineColor("dimStone", 144 / 256.0, 144 / 256.0, 144 / 256.0);
	DefineColor("edgeGold", 144 / 256.0, 130 / 256.0, 25 / 256.0);
	DefineColor("darkGold", 237 / 256.0, 220 / 256.0, 50 / 256.0);
	DefineColor("middleGold", 253 / 256.0, 241 / 256.0, 92 / 256.0);
	DefineColor("lightGold", 253 / 256.0, 244 / 256.0, 121 / 256.0);
	DefineColor("dimGold", 254 / 256.0, 250 / 256.0, 180 / 256.0);
	DefineColor("Diamond", 61 / 256.0, 89 / 256.0, 171 / 256.0);
	DefineColor("shadow",108 / 256.0, 97 / 256.0, 97 / 256.0);
	DefineColor("shadowBrown", 102 / 256.0, 51 / 256.0, 0 / 256.0);
	DefineColor("background", 204 / 256.0, 255 / 256.0, 255 / 256.0);
	DefineColor("eye", 0 / 256.0, 51 / 256.0, 51 / 256.0);
	DefineColor("shadowRed", 153 / 256.0, 0, 0);
	DefineColor("tongue", 255 / 256.0, 102 / 256.0, 102 / 256.0);
	DefineColor("tie", 255 / 256.0, 51 / 256.0, 51 / 256.0);
	DefineColor("pants", 204 / 256.0, 102 / 256.0, 0 / 256.0);
	DefineColor("shadowYellow", 204 / 256.0, 204 / 256.0, 0 / 256.0);
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
    string text[5] = {"退出游戏","游戏帮助","排行榜","继续游戏","开始游戏"};
    double wWidth = GetWindowWidth();
    double wHeight = GetWindowHeight();
    block *tempBlock = (block*)malloc(sizeof(block));
    tempBlock->size = (0.1+heightRatio)*wHeight;
    tempBlock->type = GOLD;
    tempBlock->x = (widthRatio+0.7)*wWidth;
    tempBlock->y = (0.1+heightRatio)*wHeight;
    SetPenColor("background");
    drawRec(wWidth,wHeight);
    for(int i = 0;i<5;i++){
        drawBlock(*tempBlock);
        SetPenColor("black");
        MovePen((widthRatio+0.5+indent)*wWidth,((1.7+i)*heightRatio)*wHeight);
        DrawTextString(text[i]);
        tempBlock->y += heightRatio*wHeight;
    }
	free(tempBlock);
	drawHaiMian();
}

/*画一个海绵宝宝（bushi）*/
void drawHaiMian(){
    double width = GetWindowWidth();
    double height = GetWindowHeight();
    double mostLeft = 0.15*width;
    double mostLow = 0.1*height;
    double myPixel = width*0.02;
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
void eraseBlock(block tar){
	double length = (tar.size + 1) * PIXELSIZE;
	MovePen(tar.x, tar.y);
	SetEraseMode(1);
	movePenRelative(-4 * length, 4 * length);
	drawRec(10 * length, -9 * length);
	SetEraseMode(0);
}