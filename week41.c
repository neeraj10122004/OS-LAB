#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int main(){
    pid_t t1;
    t1=fork();
    if(t1==-1){
        printf("faliure\n");
    }
    else if(t1==0){
        printf("child %d : %d\n",getpid(),getppid());
    }
    else{
        printf("parent %d : %d\n",getpid(),getppid());
    }
    return 0;
}