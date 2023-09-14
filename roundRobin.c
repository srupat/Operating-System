#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void find_waiting_time(int processes[], int n, int burst_time[], int waiting_time[], int arrival_time[], int quantum) 
{
    int *remaining_time=(int*)malloc(sizeof(int));
    for(int i=0;i<n;i++)
    {
        remaining_time[i] = burst_time[i];
    }    
    int t=0;

    while(1)
    {
        int done = 1;
        for(int i=0;i<n;i++)
        {
            if(remaining_time[i]>0)
            {
                done = 0;
                if(remaining_time[i]>quantum)
                {
                    t+=quantum;
                    remaining_time[i]-=quantum;
                }
                else{
                    t+=remaining_time[i];
                    waiting_time[i]=t-burst_time[i];
                    remaining_time[i]=0;
                }
            }
        }
        if(done==1) break;
    }
}

void find_turnaround_time(int processes[], int n, int burst_time[], int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
}

void printTable(int processes[], int arrival_time[], int n, int burst_time[],int quantum) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    int *waiting_time = (int *)malloc(n * sizeof(int));
    int *turnaround_time = (int *)malloc(n * sizeof(int));

    find_waiting_time(processes, n, burst_time, waiting_time, arrival_time, quantum);
    find_turnaround_time(processes, n, burst_time, waiting_time, turnaround_time);

    printf("PID\tAT\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];

        printf("%d\t", i + 1);
        printf("%d\t", arrival_time[i]);
        printf("%d\t", burst_time[i]);
        printf("%d\t", waiting_time[i]);
        printf("%d\n", turnaround_time[i]);
    }

    float s = (float)total_waiting_time / (float)n;
    float t = (float)total_turnaround_time / (float)n;
    printf("Average waiting time = %f\n", s);
    printf("Average turnaround time = %f", t);
}

int main() {
    int quantum;
    printf("enter the quantum time period\n");
    scanf("%d",&quantum);

    int processes[] = {1, 2, 3, 4};
    int arrival_time[] = {1, 8, 5, 9};
    int n = sizeof(processes) / sizeof(int);
    int burst_time[] = {20, 3, 5, 10};

    printTable(processes, arrival_time, n, burst_time, quantum);

    return 0;
}
