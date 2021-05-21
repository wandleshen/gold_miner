#include"music.h"

#define DEBUG

/*
ע�⣺
  mcisendString������PlayMusic������
    ǰ�߿��Զ��̲߳������֣�Ҳ����˵������Ϊ�ٴε��ö�ֹͣǰһ�����ֵĲ��ţ�����ͬʱ���Ŷ�����֣�ȱ����һ�����žͲ�������ֹͣ�����ز���ǿ��ֹͣ�Ļ�������������
    ����Ϊ���̺߳�����ֻ�ܲ������һ�ε�������ʱ�򲥷ŵ����֣����Ǻô��ǿ���ѭ���������֣�Ҳ������ʱֹͣ���ֵĲ��š�
  ���Խ����������Ҫ����ѭ��������,�����ǿ�����ʱֹͣ�����֣���ôʹ��playsound(���翪ʼ�������֣���Ϸ�������֣��������̵����֣�����������һ���û������¼�����ֹͣ���ŵ����)��
  �����ֻ����һ�Σ�Ϊ�˱���ǰһ�β��ŵ����ֱ����ǣ�����mcisendString����������ץ�����ӣ�ʯͷ����ʯ��������ʹ��ը��֮��ģ���
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