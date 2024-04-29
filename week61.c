#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t p1;
    p1=fork();
    if(p1==0){
        sleep(3);
        printf("p1 child %d\n",getpid());
    }
    else{
        pid_t p2;
        p2=fork();
        if(p2==0){
            printf("p2 child %d\n",getpid());
        }
        else{
            waitpid(p2,NULL,0);
            printf("parent %d",getpid());
        }
    }
    return 0;
}