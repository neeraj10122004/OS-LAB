#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,q;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    printf("enter the quantum\n");
    scanf("%d",&q);
    int arrival_time[n];
    int burst_time[n];
    int remain_burst[n];
    int wait_time[n];
    int turn_time[n];
    int complet_time[n];
    printf("enter the arrival and burst times\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&arrival_time[i],&burst_time[i]);
        remain_burst[i]=burst_time[i];
    }
    float avg_turn_time=0;
    float avg_wait_time=0;
    int t=0;
    while(1){
        int done=1;
        for(int i=0;i<n;i++){
            if(remain_burst[i]>0){
                done=0;
                if(remain_burst[i]>q){
                    t+=q;
                    remain_burst[i]-=q;
                }
                else{
                    t+=remain_burst[i];
                    remain_burst[i]=0;
                    complet_time[i]=t;
                    turn_time[i]=complet_time[i]-arrival_time[i];
                    wait_time[i]=complet_time[i]-arrival_time[i]-burst_time[i];
                    avg_turn_time+=turn_time[i];
                    avg_wait_time+=wait_time[i];
                    printf("\n%-8d %-8d %-8d %-8d %-8d %-8d\n",i+1,arrival_time[i],burst_time[i],complet_time[i],turn_time[i],wait_time[i]);
                }
            }
        }
        if(done==1){
            break;
        }

    }
    avg_turn_time/=n;
    avg_wait_time/=n;
    printf("\navg wait time : %f\n",avg_wait_time);
    printf("\navg turn time : %f\n",avg_turn_time);
    return 0;
}
