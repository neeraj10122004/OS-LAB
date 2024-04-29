#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* fun(void* arg){
    int n=*((int*)arg);
    for(int i=0;i<n;i++){
        printf("%d\n",i);
        sleep(1);
    }
}

int main(){
    int n=5;
    pthread_t t1;
    pthread_create(&t1,NULL,fun,(void*)(&n));
    pthread_join(t1,NULL);
    for(int i=20;i<25;i++){
        printf("%d\n",i);
        sleep(1);
    }
    
    return 0;
}