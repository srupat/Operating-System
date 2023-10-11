#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isFullq(struct queue *q) 
{
    return (q->r == q->size - 1);
}

int isEmptyq(struct queue *q) 
{
    return (q->r == q->f);
}

void enqueue(struct queue *q, int val) 
{
    if (isFullq(q)) 
    {
        printf("This queue is full\n");
    } 
    else 
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q) 
{
    int a = -1;
    if (isEmptyq(q)) 
    {
        printf("Cannot dequeue, queue is empty\n");
    } 
    else 
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int check_queue(struct queue *q, int x) 
{
    for (int i = 0; i < q->size; i++) 
    {
        if (q->arr[i] == x)
            return 1;
    }
    return 0;
}

int predict_future(struct queue *q, char *str, int current_index) 
{
    int max_distance = -1;
    int page_to_replace = -1;

    for (int i = 0; i < q->size; i++) {
        int distance = 0;
        int j = current_index + 1;

        while (str[j] != '\0') {
            if (q->arr[i] == str[j]) {
                break;
            }
            distance++;
            j++;
        }

        if (distance > max_distance) {
            max_distance = distance;
            page_to_replace = i;
        }
    }

    return page_to_replace;
}

int main() {
    char str[20];
    int slots;
    printf("Enter the page reference string\n");
    scanf("%s", str);
    printf("Enter the number of slots\n");
    scanf("%d", &slots);

    struct queue q;
    q.size = slots;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int i = 0;
    int page_fault = 0;
    while (str[i] != '\0') 
    {
        printf("current page being processed : %c\n", str[i]);
        if (check_queue(&q, str[i])) 
        {
            printf("hit\n");
        } 
        else 
        {
            if (!isFullq(&q)) 
            {
                enqueue(&q, str[i]);
            } 
            else 
            {
                int page_to_replace = predict_future(&q, str, i);
                q.arr[page_to_replace] = str[i];
            }
            printf("Miss. current page fault : %d\n", ++page_fault);
        }
        i += 1;
    }

    free(q.arr);

    return 0;
}
