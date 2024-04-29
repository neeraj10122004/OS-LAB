#include<stdio.h>
#include<stdlib.h>

//FCFS
int main(){
    int n;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    int arrival_time[n];
    int burst_time[n];
    int completion_time[n];
    int turn_time[n];
    int wait_time[n];
    printf("enter arrival time and burst time of each process\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&arrival_time[i],&burst_time[i]);
    }
    completion_time[0]=arrival_time[0]+burst_time[0];
    for(int i=1;i<n;i++){
        if(arrival_time[i]>=completion_time[i-1]){
            completion_time[i]=arrival_time[i]+burst_time[i];
        }
        else{
            completion_time[i]=completion_time[i-1]+burst_time[i];
        }
    }
    float avg_turn_time=0;
    float avg_wait_time=0;
    for(int i=0;i<n;i++){
        turn_time[i]=completion_time[i]-arrival_time[i];
        wait_time[i]=completion_time[i]-burst_time[i]-arrival_time[i];
        avg_turn_time+=turn_time[i];
        avg_wait_time+=wait_time[i];
    }
    avg_wait_time/=n;
    avg_turn_time/=n;
    for(int i=0;i<n;i++){
        printf("%-8d %-8d %-8d %-8d %-8d %-8d\n",i+1,arrival_time[i],burst_time[i],completion_time[i],turn_time[i],wait_time[i]);
    }
    printf("avg turn time : %f\n",avg_turn_time);
    printf("avg wait time : %f\n",avg_wait_time);
    return 0;
}