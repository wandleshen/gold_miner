#include "file.h"

List userHead = NULL;
List userTail = NULL;
string username;

void initFile(){
    FILE* fp;
	fp = fopen("Game.save","wb");
	int a = 100;
	for(int i = 0;i<2;i++)
		fwrite(&a,4,1,fp);
	a = 0;
	for(int i = 0;i<5;i++){
		fwrite(&a,4,1,fp);
	}
	fwrite(&a,4,0,fp);
	fclose(fp);
}

//将当前游戏状态存储到saveGame.txt中
void saveGame(){
    FILE *fp;
    if ((fp =fopen("Game.save","wb"))==NULL){
        MessageBox(NULL,"不能新建文件","错误",0);
        return;
    }
    //print();
    fwrite(&currentStatus.level,4,1,fp);
    fwrite(&currentStatus.score,4,1,fp);
    fwrite(&currentStatus.money,4,1,fp);
    for(int i = 0; i < 4; i++){
        fwrite(&currentStatus.grades[i],4,1,fp);
    }
    fwrite(&currentStatus.isDoublePlayer,4,1,fp);
    fclose(fp);
}


//从saveGame.txt中读取当前游戏状态
void loadGame(){
    FILE *fp;
    if((fp = fopen("Game.save","rb")) == NULL){
        MessageBox(NULL,"游戏存档无法读取，请检查文件是否存在或者损坏","错误",0);
        return;
    }
    fread(&currentStatus.level,4,1,fp);
    fread(&currentStatus.score,4,1,fp);
    fread(&currentStatus.money,4,1,fp);
    for(int i = 0; i< 4 ;i++){
        fread(&currentStatus.grades[i],4,1,fp);
    }
    fread(&currentStatus.isDoublePlayer,4,1,fp);
    //print();
    fclose(fp);
}



//如果当前用户的分数比获取到的用户列表中的任何一个人的分数更高，那么将该用户写入文件中，否则返回
void insertUser(User curr){
    //读入之前的所有数据(数据个数默认是5)
    loadRank();
    List move = userHead;
    int flag = 0;
    while(move->next != NULL){
        //选择的比较大小的方式是通过score比较
        if(move->next->score < curr.score){
            flag = 1;
            break;
        }
        move = move->next;
    }
    if(flag == 0) return;
    List newUser = (List)malloc(sizeof(struct userRank));
    newUser->level = curr.level;
    newUser->score = curr.score;
    strcpy(newUser->userName,username); 
    newUser->next = move->next;
    move->next = newUser;
}
//写入排行榜玩家数据结构，文件默认存储5个玩家的数据
void saveRank(){
    FILE *fp;
    //如果游戏没有结束，直接返回
    if(isGame != 0){
        return;
    }
    insertUser(currentStatus);
    
    if((fp = fopen("Rank.user","wb")) == NULL){
        MessageBox(NULL,"无法新建排行榜文件","错误",0);
        return;
    }
    List move = userHead->next;
    while(move != NULL){
        fwrite(&move->level,4,1,fp);
        fwrite(&move->score,4,1,fp);
        fwrite(move->userName,10,1,fp);
        move = move->next;
    }
    //销毁链表
    List pre=userHead, beh=userHead->next;
    while(beh != NULL){
        free(pre);
        pre = beh;
        beh = beh->next;
    }
    fclose(fp);
}

void loadRank(){
    userHead = userTail = (List)malloc(sizeof(struct userRank));
    FILE* fp;
    if((fp = fopen("Rank.user","rb")) == NULL){
        MessageBox(NULL,"无法读取排行榜文件,请检查文件是否存在","错误",0);
        return;
    }
    for(int i = 0; i < MAX_USER_SAVED; i++){
        List newUser =  (List) malloc(sizeof(struct userRank));
        fread(&newUser->level,4,1,fp);
        fread(&newUser->score,4,1,fp);
        fread(newUser->userName,10,1,fp);
        newUser->next = NULL;
        userTail->next = newUser;
        userTail = newUser;
    }
    fclose(fp);
}

