#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t wordm;
struct mq_attr word_att;
char word[25];
int msg_prio;
 int main()
 {
    word_att.mq_flags = 0;
    word_att.mq_maxmsg= 25;
    word_att.mq_msgsize = 0;
    word_att.mq_curmsgs= 25;

     wordm=mq_open("/wordm",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &word_att);
        mq_receive(wordm,word,6,&msg_prio);
     printf("\n word :%s",word);
     int length=strlen(word);
     printf("\nLength:%d",length);
     mq_close(wordm);
     return 0;
     

 }