#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int Rear;
    int *Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->Rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,int x)
{
    if((q->Rear+1)%q->size==q->front)
        printf("Queue is Full");
    else
    {
        q->Rear=(q->Rear+1)%q->size;
        q->Q[q->Rear]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->Rear)
        printf("Queue is Empty");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;

    }while(i!=(q.Rear+1)%q.size);

    printf("\n");
    
}
int main()
{
    struct Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,30);
    enqueue(&q,30);

    Display(q);
    return 0;


}
