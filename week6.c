#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t p;
    p=fork();
    if(p==0){
        printf("child %d \n",getpid());
        sleep(3);
        printf("child terminated %d %d\n",getpid(),getppid());
    }
    else{
        printf("parent %d\n",getpid());
    }
    return 0;
}