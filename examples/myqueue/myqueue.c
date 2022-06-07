#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <events.h>
#include <stdlib.h>
#include <string.h>
Event HID_eve={.type =9};
Queue thisQueue;


int myhandler(Event *event)
{
    if(event->type ==10)
        printf("it is OK for %d\n",event->type);
    else if(event->type == 9)
        printf("bingo\n");
    else
        printf(" the def type  %d\n",event->type);

    return 0;
}


void *ctrl1(void *arg)
{
    int ret;
    printf("ctrl1 is press start\n");
    while(1){
        sleep(3);
        printf("preccess \n");
        ret =process_event(&thisQueue,myhandler);
        if(ret ==-1)
            printf(" %s %d> empty queue\n",__TIME__,__LINE__);
        else 
            printf("****************************************\n");
    }
}

void *ctrl2(void *arg)
{
    srand((unsigned)time(0));
  
    printf("the ctrl2 ID = %d\n",pthread_self());

    while(1){
        

        HID_eve.type=(rand() % 12 + 1);

        printf("the HID_eve.type=%d\n",HID_eve.type);
        
         receive_event(&thisQueue, &HID_eve);
        sleep(3);

    }
}



int main()
{
   
    queue_init(&thisQueue,free);
    pthread_t send_tid,redetid;

    printf(" the main pid start \n");
    pthread_create(&send_tid,NULL,ctrl2,NULL);

    pthread_detach(send_tid);

    pthread_create(&redetid,NULL,ctrl1,NULL);

    pthread_join(redetid,NULL);


    return 0;

}