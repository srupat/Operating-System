#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, head, total_seek_time = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *request_queue = (int*)malloc(sizeof(int)*n);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request_queue[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    int *visited = (int*)malloc(sizeof(int));
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Seek Sequence: %d", head);

    for (int i = 0; i < n; i++) {
        int min_seek = INT_MAX;
        int min_index = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int seek = abs(head - request_queue[j]);
                if (seek < min_seek) {
                    min_seek = seek;
                    min_index = j;
                }
            }
        }

        visited[min_index] = 1;
        total_seek_time += min_seek;
        head = request_queue[min_index];

        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time: %d\n", total_seek_time);

    return 0;
}
