#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    char a[100];
    char b[100];
    char c[100];
    int f1=open("a.txt",O_RDONLY);
    int f2=open("b.txt",O_WRONLY);
    int f3=open("c.txt",O_RDWR);
    int n=read(f1,a,10);
    int m=read(f3,c,10);
    int ret=atoi(a)+atoi(c);
    b[0]=ret+'0';
    write(f2,b,1);
    write(f3,b,1);
    return 0;
}

