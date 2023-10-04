#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int * arr;
};

int isFullq(struct queue * q)
{
    if(q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmptyq(struct queue * q)
{
    if(q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue * q,int val)
{
    if(isFullq(q))
    {
        printf("This queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue * q)
{
    int a=-1;
    if(isEmptyq(q))
    {
        printf("Cannot dequeue, queue is empty\n");
    }
    else{
        q->f ++;
        a = q->arr[q->f];
    }
    return a;
}

int check_queue(struct queue * q, int x)
{
    for(int i=0;i<q->size;i++)
    {
        if(q->arr[i] == x) return 1;        
    }
    return 0;
}
int main()
{
    char str[20];
    int slots;
    printf("Enter the page reference string\n");
    scanf("%s",str);
    printf("Enter the number of slots\n");
    scanf("%d",&slots);
    
    struct queue q;
    q.size = slots;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));

    int i = 0;
    int page_fault = 0;
    while(str[i]!='\0')
    {
        printf("current page being processed : %c\n",str[i]); 
        // if element is not present but queue is not full only enqueue dont dequeue
        // if element is not present but queue is full, first dequeue and then enqueue
        // if element is present and queue is full, do nothing
        // if element is present and queue is not full, do nothing       
        if(check_queue(&q, str[i])) printf("hit\n");
        else
        {
            if(!isFullq) enqueue(&q, str[i]);
            else
            {
                dequeue(&q);
                enqueue(&q, str[i]);
            }
            printf("Miss. current page fault : %d\n", ++page_fault);
        }
        i+=1;
    }
    

    return 0;
}
