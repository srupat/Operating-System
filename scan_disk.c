#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, total_seek_time = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *request_queue = (int *)malloc(sizeof(int) * n);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &request_queue[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Seek Sequence: %d", head);

    int direction;
    printf("\nEnter the direction of head movement (0 for left, 1 for right): ");
    scanf("%d", &direction);

    if (direction == 0)
    {
        for (int i = head; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (request_queue[j] == i)
                {
                    total_seek_time += abs(head - request_queue[j]);
                    head = request_queue[j];
                    printf(" -> %d", head);
                }
            }
        }
        total_seek_time += head;
        head = 0;
        printf(" -> 0");
        for (int i = 0; i < n; i++)
        {
            if (request_queue[i] > 0)
            {
                total_seek_time += abs(head - request_queue[i]);
                head = request_queue[i];
                printf(" -> %d", head);
            }
        }
    }
    else if (direction == 1)
    {
        for (int i = head; i <= 199; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (request_queue[j] == i)
                {
                    total_seek_time += abs(head - request_queue[j]);
                    head = request_queue[j];
                    printf(" -> %d", head);
                }
            }
        }
        total_seek_time += 199 - head;
        head = 199;
        printf(" -> 199");
        for (int i = 0; i < n; i++)
        {
            if (request_queue[i] < 199)
            {
                total_seek_time += abs(head - request_queue[i]);
                head = request_queue[i];
                printf(" -> %d", head);
            }
        }
    }

    printf("\nTotal Seek Time: %d\n", total_seek_time);

    return 0;
}
