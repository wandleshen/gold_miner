#include "file.h"
//#define DEBUG

List userHead = NULL;
List userTail = NULL;



#ifdef DEBUG
void print(){
    printf("%d %d %d\n",currentStatus.level,currentStatus.score,currentStatus.money);
    for(int i = 0;i<4;i++){
        printf("%d\n",currentStatus.grades[i]);
    }
}
#endif

//将当前游戏状态存储到saveGame.txt中
void saveGame(){
    FILE *fp;
    if ((fp =fopen("../saveGame.txt","wb"))==NULL){
        MessageBox(NULL,"不能新建文件","错误",0);
        return;
    }
    print();
    fwrite(&currentStatus.level,4,1,fp);
    fwrite(&currentStatus.score,4,1,fp);
    fwrite(&currentStatus.money,4,1,fp);
    for(int i = 0; i < 4; i++){
        fwrite(&currentStatus.grades[i],4,1,fp);
    }
    fclose(fp);
}


//从saveGame.txt中读取当前游戏状态
void loadGame(){
    FILE *fp;
    if((fp = fopen("../saveGame.txt","rb")) == NULL){
        MessageBox(NULL,"游戏存档无法读取，请检查文件是否存在或者损坏","错误",0);
        return;
    }
    fread(&currentStatus.level,4,1,fp);
    fread(&currentStatus.score,4,1,fp);
    fread(&currentStatus.money,4,1,fp);
    for(int i = 0; i< 4 ;i++){
        fread(&currentStatus.grades[i],4,1,fp);
    }
    print();
    fclose(fp);
}

//删除掉链表的最后一个节点，传入的指针至少是倒数第二个用户指针
void removeLast(List head){
    if(head == NULL || head->next == NULL) return;//由于调用这个函数的指针至少是倒数第二个用户，所以使用这样的逻辑判断
    List pre = head, beh = head->next;
    while(beh->next != NULL){
        pre = beh;
        beh = beh->next;
    }
    pre->next = NULL;
    free(beh);
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
    strcpy(newUser->userName,"test"); //这里的test在后期需要被修改成一个获取用户输入的用户名的函数
    newUser->next = move->next;
    move->next = newUser;
    removeLast(move);
}
//写入排行榜玩家数据结构，文件默认存储5个玩家的数据
void saveRank(){
    FILE *fp;
    //如果游戏没有结束，直接返回
    if(isGameOver == 0){
        return;
    }
    insertUser(currentStatus);
    //需要从外部获取输入的用户名，当前指定为test
    if((fp = fopen("../userRank.txt","wb")) == NULL){
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
    //释放之前的指针空间
    char *temp = malloc(sizeof(11));
    while(userHead){
        List temp = userHead->next;
        free(userHead);
        userHead = temp;
        if(temp != NULL){
            temp = temp->next;
        }
    }
    userHead = userTail = (List)malloc(sizeof(struct userRank));
    FILE* fp;
    if((fp = fopen("../userRank.txt","rb")) == NULL){
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

