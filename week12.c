#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

//SSTF DICK SCHEDULING
int main(){
    int cur,n;
    printf("enter the current position\n");
    scanf("%d",&cur);
    printf("enter the number of seeks\n");
    scanf("%d",&n);
    int arr[n];
    int mov=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){

        int min_dist[n];
        for(int j=0;j<n;j++){
            min_dist[j]=INT_MAX;
            if(arr[j]!=-1){
                min_dist[j]=abs(cur-arr[j]);
            }
        }
        int min=INT_MAX;
        int min_index=-1;
        for(int j=0;j<n;j++){
            if(min_dist[j]<min){
                min=min_dist[j];
                min_index=j;
            }
        }
        mov+=min;
        if(i==-1){
            break;
        }
        printf("%d -> %d\n",cur,arr[min_index]);
        cur=arr[min_index];
        arr[min_index]=-1;
    }
    printf("\nmin movement %d \n",mov);
    return 0;
}