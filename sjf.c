#include<stdio.h>
#include<stdlib.h>

void sortAccordingToBurstTime(int burst_time[], int n)
{
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(burst_time[j] > burst_time[j + 1]) 
            {
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
            }
        }
    }
}


void find_waiting_time(int processes[], int n, int burst_time[], int waiting_time[], int arrival_time[])
{
    waiting_time[0] = arrival_time[0];
    sortAccordingToBurstTime(burst_time,n);
    for(int i=1;i<n;i++)
    {
        waiting_time[i] = arrival_time[i-1]+burst_time[i-1]+waiting_time[i-1];
    }
}

void find_turnaround_time(int processes[], int n, int burst_time[], int waiting_time[], int arrival_time[], int turnaround_time[])
{
    sortAccordingToBurstTime(burst_time,n);
    for(int i=0;i<n;i++)
    {
        turnaround_time[i] = arrival_time[i]+burst_time[i]+waiting_time[i];
    }
}

void printTable(int processes[],int arrival_time[], int n, int burst_time[])
{
    int total_waiting_time = 0, total_turnaround_time = 0;
    int *waiting_time = (int *)malloc(n*sizeof(int));
    int *turnaround_time = (int *)malloc(n*sizeof(int));

    find_waiting_time(processes, n, burst_time, waiting_time, arrival_time);
    find_turnaround_time(processes, n, burst_time, waiting_time,arrival_time, turnaround_time);

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
    int processes[] = {1,2,3,4};
    int arrival_time[] = {1,8,5,9};
    int n = sizeof(processes)/sizeof(int);

    int burst_time[] = {20, 3, 5, 10};
    printTable(processes, arrival_time, n, burst_time);

    return 0;
}