﻿//fcfs code with same arrival time i.e 0 ms
#include<stdio.h>
int main(){
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("Enter total number of processes (maximum 20)\n");
    scanf("%d",&n);
    printf("Enter burst times\n");
    for(i=0;i<n;++i){
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);    
    }
    wt[0]=0;
    for(i=1;i<n;++i){
        wt[i]=0;
        for(j=0;j<i;++j){
            wt[i]+=bt[j];
        }
    }
    printf("Processes Burst Time  Waiting Time  Turnaround Time\n");
    for(i=0;i<n;++i){
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("P[%d]: %d sec, %d sec, %d sec\n",i+1,bt[i],wt[i],tat[i]);
    }
    avwt/=i;
    avtat/=i;
    printf("Average waiting time is %d sec\n",avwt);
    printf("Average turnaround time is %d sec",avtat);
    
    return 0;
}
