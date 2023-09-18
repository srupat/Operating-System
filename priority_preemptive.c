#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void find_waiting_time(int processes[], int n, int burst_time[], int waiting_time[], int arrival_time[]) {
    int *remaining_time = (int *)malloc(n * sizeof(int));
    bool *completed = (bool *)malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
        completed[i] = false;
    }

    int complete = 0, current_time = 0;

    while (complete != n) {
        int shortest = -1;
        int min = 9999;

        for (int j = 0; j < n; j++) {
            if (arrival_time[j] <= current_time && !completed[j] && remaining_time[j] < min) {
                min = remaining_time[j];
                shortest = j;
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }

        remaining_time[shortest]--;

        if (remaining_time[shortest] == 0) {
            complete++;
            completed[shortest] = true;
            int finish_time = current_time + 1;
            waiting_time[shortest] = finish_time - burst_time[shortest] - arrival_time[shortest];

            if (waiting_time[shortest] < 0) {
                waiting_time[shortest] = 0;
            }
        }

        current_time++;
    }

    free(remaining_time);
    free(completed);
}

void find_turnaround_time(int processes[], int n, int burst_time[], int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
}

void printTable(int processes[], int arrival_time[], int n, int burst_time[]) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    int *waiting_time = (int *)malloc(n * sizeof(int));
    int *turnaround_time = (int *)malloc(n * sizeof(int));

    find_waiting_time(processes, n, burst_time, waiting_time, arrival_time);
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
    int processes[] = {1, 2, 3, 4};
    int arrival_time[] = {1, 8, 5, 9};
    int n = sizeof(processes) / sizeof(int);
    int burst_time[] = {20, 3, 5, 10};

    printTable(processes, arrival_time, n, burst_time);

    return 0;
}
