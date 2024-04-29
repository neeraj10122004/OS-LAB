#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

int shared=1;
sem_t s;

void* fun1(void* arg){
    int x;
    sem_wait(&s);
    x=shared;
    printf("read from fun1 shared : %d\n",x);
    x++;
    sleep(1);
    shared=x;
    printf("updated shared from fun1 : %d\n",shared);
    sem_post(&s);
    
}
void* fun2(void* arg){
    int y;
    sem_wait(&s);
    y=shared;
    printf("read from fun2 shared : %d\n",y);
    y--;
    sleep(1);
    shared=y;
    printf("updated shared from fun2 : %d\n",shared);
    sem_post(&s);
    
}

int main(){
    sem_init(&s,0,1);
    pthread_t p1,p2;
    pthread_create(&p1,NULL,fun1,NULL);
    pthread_create(&p2,NULL,fun2,NULL);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    printf("\nfinal value of shared %d\n",shared);
    return 0;
}