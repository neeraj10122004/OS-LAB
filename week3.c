#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
    char a[100];
    int n=read(0,a,10);
    int num=atoi(a);
    num=num*num;
    char b[100];
    int i=0;
    while(num>0){
        b[i]=num%10+'0';
        num/=10;
        i++;
    }
    char t[100];
    for(int i=0;i<strlen(b);i++){
        t[strlen(b)-i-1]=b[i];
    }
    printf("%s\n",b);
    write(2,t,strlen(b));
    printf("\n");
    write(1,a,n);
    return 0;
}