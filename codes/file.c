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

//����ǰ��Ϸ״̬�洢��saveGame.txt��
void saveGame(){
    FILE *fp;
    if ((fp =fopen("../saveGame.txt","wb"))==NULL){
        MessageBox(NULL,"�����½��ļ�","����",0);
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


//��saveGame.txt�ж�ȡ��ǰ��Ϸ״̬
void loadGame(){
    FILE *fp;
    if((fp = fopen("../saveGame.txt","rb")) == NULL){
        MessageBox(NULL,"��Ϸ�浵�޷���ȡ�������ļ��Ƿ���ڻ�����","����",0);
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

//ɾ������������һ���ڵ㣬�����ָ�������ǵ����ڶ����û�ָ��
void removeLast(List head){
    if(head == NULL || head->next == NULL) return;//���ڵ������������ָ�������ǵ����ڶ����û�������ʹ���������߼��ж�
    List pre = head, beh = head->next;
    while(beh->next != NULL){
        pre = beh;
        beh = beh->next;
    }
    pre->next = NULL;
    free(beh);
}


//�����ǰ�û��ķ����Ȼ�ȡ�����û��б��е��κ�һ���˵ķ������ߣ���ô�����û�д���ļ��У����򷵻�
void insertUser(User curr){
    //����֮ǰ����������(���ݸ���Ĭ����5)
    loadRank();
    List move = userHead;
    int flag = 0;
    while(move->next != NULL){
        //ѡ��ıȽϴ�С�ķ�ʽ��ͨ��score�Ƚ�
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
    strcpy(newUser->userName,"test"); //�����test�ں�����Ҫ���޸ĳ�һ����ȡ�û�������û����ĺ���
    newUser->next = move->next;
    move->next = newUser;
    removeLast(move);
}
//д�����а�������ݽṹ���ļ�Ĭ�ϴ洢5����ҵ�����
void saveRank(){
    FILE *fp;
    //�����Ϸû�н�����ֱ�ӷ���
    if(isGameOver == 0){
        return;
    }
    insertUser(currentStatus);
    //��Ҫ���ⲿ��ȡ������û�������ǰָ��Ϊtest
    if((fp = fopen("../userRank.txt","wb")) == NULL){
        MessageBox(NULL,"�޷��½����а��ļ�","����",0);
        return;
    }
    List move = userHead->next;
    while(move != NULL){
        fwrite(&move->level,4,1,fp);
        fwrite(&move->score,4,1,fp);
        fwrite(move->userName,10,1,fp);
        move = move->next;
    }
    //��������
    List pre=userHead, beh=userHead->next;
    while(beh != NULL){
        free(pre);
        pre = beh;
        beh = beh->next;
    }
    fclose(fp);
}

void loadRank(){
    //�ͷ�֮ǰ��ָ��ռ�
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
        MessageBox(NULL,"�޷���ȡ���а��ļ�,�����ļ��Ƿ����","����",0);
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

