#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* fun(void* arg){
    for(int i=1;i<=5;i++){
        printf("%d\n",i);
        sleep(1);
    }
}

int main(){
    pthread_t p1;
    pthread_create(&p1,NULL,fun,NULL);
    for(int i=21;i<=25;i++){
        printf("%d\n",i);
        sleep(1);
    }
    pthread_join(p1,NULL);
    
    return 0;
}