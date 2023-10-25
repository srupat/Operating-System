#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total_seek_time = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int* request_queue = (int*)malloc(sizeof(int)*n);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request_queue[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    int current_head = head;

    printf("Seek Sequence: %d", current_head);

    for (int i = 0; i < n; i++) {
        total_seek_time += abs(current_head - request_queue[i]);
        current_head = request_queue[i];
        printf(" -> %d", current_head);
    }

    printf("\nTotal Seek Time: %d\n", total_seek_time);

    return 0;
}
