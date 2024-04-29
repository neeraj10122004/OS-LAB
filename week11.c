#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//FCFS DISK SCHEDULING
int main(){
    int cur,n;
    printf("enter the initial position of head\n");
    scanf("%d",&cur);
    printf("enter the number of reads\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int head_mov=0;
    printf("%d->%d",cur,arr[0]);
    head_mov=abs(cur-arr[0]);
    cur=arr[0];
    for(int i=1;i<n;i++){
        printf("->%d",arr[i]);
        head_mov+=abs(cur-arr[i]);
        cur=arr[i];
    }
    printf("\ntotal head movement : %d\n",head_mov);
    return 0;

}