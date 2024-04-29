#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t p;
    p=fork();
    if(p==-1){
        printf("failed");
    }
    if(p==0){
        int p1=fork();
        if(p1==0){
            printf("p2: %d child of p1: %d\n",getpid(),getppid());
        }
        else{
            printf("p1: %d child of p: %d\n",getpid(),getppid());
        }
    }
    else{
        printf("p: %d parent of all\n",getpid());
    }
}