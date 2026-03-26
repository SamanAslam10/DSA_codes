#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q , int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}
int IsEmpty(struct Queue *q)
{
    if(q->front == q-> rear )
    {
        return 1;
    }
    return 0;
}
int IsFull(struct Queue *q)
{
    if(q->rear == q->size -1)
    {
        return 1;
    }
    return 0;
}
void EnQueue(struct Queue *q , int data)
{
    if(q->rear == q->size -1)
    {
        printf("%s" , "Queue is full");
        return;
    }
    else
    {
        q->rear += 1;
    }
    q->Q[q->rear] = data;
}
int DeQueue(struct Queue *q)
{
    int x = -1;
    if(q->front == q-> rear )
    {
        printf("%s" , "Queue is empty!");
    }
    else
    {
        q->front += 1;
        x = q->Q[q->front];
    }
    return x;
}
int First(struct Queue *q)
{
    return q->Q[q->front + 1];
}
int Last(struct Queue *q)
{
    return q->Q[q->rear];
}
void Display(struct Queue *q)
{
    for(int i = q->front + 1 ; i <= q->rear ; i ++)
    {
        printf("%d" , q->Q[i]);
        printf("\n");
    }
}
int main()
{
    struct Queue q;
 
    Create(&q,6);
    EnQueue(&q,10);
    EnQueue(&q,20);
    EnQueue(&q,30);
    EnQueue(&q,40);

    Display(&q);

    DeQueue(&q);
    Display(&q);
    return 0;
}