#include<stdio.h>
#include<stdlib.h>

void find_waiting_time(int processes[], int n, int burst_time[], int waiting_time[])
{
    waiting_time[0] = 0;

    for(int i=1;i<n;i++)
    {
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
    }
}

void find_turnaround_time(int processes[], int n, int burst_time[], int waiting_time[], int turnaround_time[])
{
    for(int i=0;i<n;i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
}

void printTable(int processes[],int arrival_time[], int n, int burst_time[])
{
    int total_waiting_time = 0, total_turnaround_time = 0;
    int *waiting_time = (int *)malloc(n*sizeof(int));
    int *turnaround_time = (int *)malloc(n*sizeof(int));

    find_waiting_time(processes, n, burst_time, waiting_time);
    find_turnaround_time(processes, n, burst_time, waiting_time, turnaround_time);

    printf("PID\tAT\tBT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
        total_waiting_time = total_waiting_time + waiting_time[i];
        total_turnaround_time = total_turnaround_time+turnaround_time[i];

        printf("%d\t",i+1);
		printf("%d\t",arrival_time[i]);
        printf("%d\t",burst_time[i]);
        printf("%d\t",waiting_time[i]);
        printf("%d\n",turnaround_time[i]);
    }    
        float s= (float)total_waiting_time/(float)n;
        float t = (float)total_turnaround_time/(float)n;
        printf("Average waiting time = %f\n",s);
        printf("Average turnaround time = %f",t);
}

int main()
{
    int processes[] = {1,2,3};
	int arrival_time[] = {0,2,3};
    int n = sizeof(processes)/sizeof(processes[0]);

    int burst_time[] = {24,3, 3};
    printTable(processes,arrival_time,n,burst_time);
    return 0;
}