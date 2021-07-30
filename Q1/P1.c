#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t wordm;
struct mq_attr word_att;

int main()
{
    word_att.mq_flags = 0;
    word_att.mq_maxmsg= 25;
    word_att.mq_msgsize = 0;
    word_att.mq_curmsgs= 25;
    int fd;
     fd=open("~/usr/share/dict/words",O_RDONLY, S_IRUSR | S_IWUSR );

     if (-1 == fd)
     {
         perror("Error opening file");
         exit();
     }
     else
     {
         if(fd==109)
        {
        wordm=mq_open("/wordm",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &word_att);
        mq_send(wordm,&fd,6,0);

        mq_close(wordm);
       }
    }
     close(fd);

}
