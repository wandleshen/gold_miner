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
  if(isMusicPlaying == 0) return;
  char path[100] = "play ";
  strcat(path,sourceFilePath);
  mciSendString(path,NULL,0,NULL);
}
void loopPlayMusic(char *sourceFilePath){
  if(isMusicPlaying == 0) return;
  PlaySound(sourceFilePath,0,SND_ASYNC | SND_LOOP);
}

void stopBGM(){
  PlaySound(NULL,0,0);
}

void welcomeMusic(){
  PlaySound("media_src\\music\\welcomemusic",0,SND_ASYNC | SND_LOOP);
}

void levelChangeMusic(){
  if(isMusicPlaying == 0) return;
  mciSendString(TEXT("play \"media_src\\music\\levelChange.wav\" "),NULL,0,NULL);
}
 
void addScoreMusic(){
  if(isMusicPlaying == 0) return;
  mciSendString(TEXT("play \"meida_src\\music\\addScore.wav\" "),NULL,0,NULL);
}

void diamondMusic(){
  if(isMusicPlaying == 0) return;
  mciSendString(TEXT("play \"media_src\\music\\diamond.wav\" "),NULL,0,NULL);
}


void goldMusic(){
  if(isMusicPlaying == 0) return;
  mciSendString(TEXT("play \"media_src\\music\\gold.wav\" "),NULL,0,NULL);
}
void rockMusic(){
	if(isMusicPlaying == 0) return;
	mciSendString(TEXT("play \"media_src\\music\\rock.wav\" "),NULL,0,NULL);
}


void purchaseMusic(){
	if(isMusicPlaying == 0) return;
	mciSendString(TEXT("play \"media_src\\music\\buy.wav\" "),NULL,0,NULL);
}

void digMusic(){
  	if(isMusicPlaying == 0) return;
	mciSendString(TEXT("play \"media_src\\music\\dig.wav\" "),NULL,0,NULL);
}
