#include<stdio.h>
#include<stdlib.h>

void sortAccordingToPriority(int processes[], int arrival_time[], int priority[], int n)
{
    int i, j, temp_process, temp_arrival, temp_priority;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(priority[j] < priority[j + 1])
            {
                // Swap process IDs
                temp_process = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp_process;

                // Swap arrival times
                temp_arrival = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp_arrival;

                // Swap priorities
                temp_priority = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp_priority;
            }
        }
    }
}

void find_waiting_time(int processes[], int n, int burst_time[], int waiting_time[], int arrival_time[], int priority[])
{
    waiting_time[0] = 0;
    sortAccordingToPriority(processes, arrival_time, priority, n);
    
    for(int i = 1; i < n; i++)
    {
        waiting_time[i] = 0;
        for(int j = 0; j < i; j++)
        {
            waiting_time[i] += burst_time[j];
        }
        waiting_time[i] -= arrival_time[i];
        if (waiting_time[i] < 0)
            waiting_time[i] = 0;
    }
}

void find_turnaround_time(int processes[], int n, int burst_time[], int waiting_time[], int turnaround_time[])
{
    for(int i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
}

void printTable(int processes[], int arrival_time[], int n, int burst_time[], int priority[])
{
    int total_waiting_time = 0, total_turnaround_time = 0;
    int *waiting_time = (int *)malloc(n * sizeof(int));
    int *turnaround_time = (int *)malloc(n * sizeof(int));

    find_waiting_time(processes, n, burst_time, waiting_time, arrival_time, priority);
    find_turnaround_time(processes, n, burst_time, waiting_time, turnaround_time);

    printf("PID\tPri\tAT\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++)
    {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i], priority[i], arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    float s = (float)total_waiting_time / (float)n;
    float t = (float)total_turnaround_time / (float)n;
    printf("Average waiting time = %f\n", s);
    printf("Average turnaround time = %f", t);

    free(waiting_time);
    free(turnaround_time);
}

int main()
{
    int processes[] = {1, 2, 3, 4};
    int arrival_time[] = {1, 8, 5, 9};
    int priority[] = {4, 2, 3, 1};
    int n = sizeof(processes) / sizeof(int);

    int burst_time[] = {20, 3, 5, 10};
    printTable(processes, arrival_time, n, burst_time, priority);

    return 0;
}
