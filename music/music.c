#include"music.h"

#define DEBUG

/*
ע��:
?	mcisendString������PlaySound����������
?		ǰ�߿��Զ��̲߳������֣�Ҳ����˵������Ϊ�ٴε��ö�ֹͣǰһ�����ֵĲ��ţ�����ͬʱ���Ŷ�����֣�ȱ����һ����ʼ���žͲ���������ֹͣ���ţ����ز���ǿ��ֹͣ����Ļ�����������
?		�����ǵ��̺߳�����ֻ�ܲ������һ�ε�������ʱ�򲥷ŵ����֣�Ҳ����˵�ڴε��ûḲ��֮ǰ���ŵ����֣��ô��ǿ���ѭ���������֣�Ҳ������ʱֹͣ���ֵĲ��š�
�����ҽ��������Ҫѭ������ĳһ�����֣���������Ҫ���ŵ�������ʱ������ֹͣ����ô����PlaySound���������翪ʼ��������֣���Ϸ��������֣��������̵겥�ŵ����֣�etc
�����Ҫ����ֻ����һ�Σ����ҿ������������ֲ��ŵ�ʱ��ͬʱ���ŵ����֣�����ץ����ʯ��������Ʒ�ȣ���ô����mcisendString������
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