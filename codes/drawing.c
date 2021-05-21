#include "drawing.h"
#define PIXELSIZE 0.05

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

void eraseBlock(block tar){
	double length = (tar.size + 1) * PIXELSIZE;
	MovePen(tar.x, tar.y);
	SetEraseMode(1);
	movePenRelative(-4 * length, 4 * length);
	drawRec(10 * length, -9 * length);
	SetEraseMode(0);
}

