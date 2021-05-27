#include"music.h"

#define DEBUG

/*
注意:
?	mcisendString函数和PlaySound函数的区别
?		前者可以多线程播放音乐，也就是说不会因为再次调用而停止前一次音乐的播放，可以同时播放多个音乐，缺点是一旦开始播放就不可以主动停止播放（本地测试强行停止程序的话程序会崩溃）
?		后者是单线程函数，只能播放最后一次调用他的时候播放的音乐，也就是说在次调用会覆盖之前播放的音乐，好处是可以循环播放音乐，也可以随时停止音乐的播放。
所以我建议如果需要循环播放某一个音乐，或者是需要播放的音乐随时都可以停止，那么调用PlaySound函数（比如开始界面的音乐，游戏界面的音乐，或者是商店播放的音乐，etc
如果需要的是只播放一次，并且可以在其他音乐播放的时候同时播放的音乐，比如抓到钻石，购买物品等，那么调用mcisendString函数。
*/
void playMusic(char *sourceFilePath){
  char path[100] = "play ";
  strcat(path,sourceFilePath);
  mciSendString(path,NULL,0,NULL);
}
void loopPlayMusic(char *sourceFilePath){
  PlaySound(sourceFilePath,0,SND_ASYNC | SND_LOOP);
}

void stopBGM(){
  PlaySound(NULL,0,0);
}

void welcomeMusic(){
  PlaySound("media_src\\music\\welcomemusic",0,SND_ASYNC | SND_LOOP);
}

void levelChangeMusic(){
  mciSendString(TEXT("play \"media_src\\music\\levelChange.wav\" "),NULL,0,NULL);
}
 
void addScoreMusic(){
  mciSendString(TEXT("play \"meida_src\\music\\addScore.wav\" "),NULL,0,NULL);
}

void diamondMusic(){
  mciSendString(TEXT("play \"media_src\\music\\diamond.wav\" "),NULL,0,NULL);
}


void goldMusic(){
  mciSendString(TEXT("play \"media_src\\music\\gold.wav\" "),NULL,0,NULL);
}
void rockMusic(){
	mciSendString(TEXT("play \"media_src\\music\\rock.wav\" "),NULL,0,NULL);
}


void purchaseMusic(){
	mciSendString(TEXT("play \"media_src\\music\\buy.wav\" "),NULL,0,NULL);
}

void digMusic(){
	mciSendString(TEXT("play \"media_src\\music\\dig.wav\" "),NULL,0,NULL);
}




