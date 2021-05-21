#include"music.h"

#define DEBUG

/*
注意：
  mcisendString函数和PlayMusic的区别：
    前者可以多线程播放音乐，也就是说不会因为再次调用而停止前一次音乐的播放，可以同时播放多个音乐，缺点是一旦播放就不能主动停止（本地测试强行停止的话程序会崩溃）。
    后者为单线程函数，只能播放最后一次调用它的时候播放的音乐，但是好处是可以循环播放音乐，也可以随时停止音乐的播放。
  所以建议是如果需要播放循环的音乐,或者是可以随时停止的音乐，那么使用playsound(比如开始界面音乐，游戏界面音乐，或者是商店音乐，或者是那种一旦用户触发事件即刻停止播放的情况)。
  如果是只播放一次，为了避免前一次播放的音乐被覆盖，调用mcisendString函数（比如抓到金子，石头，钻石，或者是使用炸弹之类的）。
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
  PlaySound("..\\media_src\\music\\welcomemusic",0,SND_ASYNC | SND_LOOP);
}

void levelChangeMusic(){
  mciSendString(TEXT("play \"..\\media_src\\music\\levelChange.wav\" "),NULL,0,NULL);
}
 
void addScoreMusic(){
  mciSendString(TEXT("play \"..\\media_src\\music\\addScore.wav\" "),NULL,0,NULL);
}

void diamondMusic(){
  mciSendString(TEXT("play \"..\\media_src\\music\\diamond.wav\" "),NULL,0,NULL);
}


void goldMusic(){
  mciSendString(TEXT("play \"..\\media_src\\music\\gold.wav\" "),NULL,0,NULL);
}


void bombMusic(){
  mciSendString(TEXT("play \"..\\media_src\\music\\bomb.wav\" "),NULL,0,NULL);
}




#ifdef DEBUG 
int main(){
  //loopPlayMusic(".\\musicSrc\\bomb.wav");
  levelChangeMusic();
  getchar();
}

#endif