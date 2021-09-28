#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int Rear;
    struct Node **Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->Rear=-1;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q,struct Node *x)
{
    if(q->Rear==q->size-1)
        printf("Queue is Full");
    else
    {
        q->Rear++;
        q->Q[q->Rear]=x;
    }
}
struct Node* dequeue(struct Queue *q) 
{
    struct Node* x=NULL;
    if(q->front==q->Rear)
        printf("Queue is Empty");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front==q.Rear;
}