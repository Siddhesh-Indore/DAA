#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;
    int i;

    first=(struct Node*)malloc(sizeof(struct Node));
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
} 

int Length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void Insert(struct Node *p,int index,int x)
{
    struct Node *t;

    if(index<0 || index>Length(first))
        return;
    if(index==0)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
}
int Delete(struct Node *p,int index)
{
    int x=-1;
    if(index<1 || index>Length(first))
        return-1;
    if(index==1)
    {
        p=first;
        first=first->next;
        x=p->data;
        free (p);
        if(first)
            first->prev=NULL;
    }
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
            p=p->next;
        x=p->data;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        free(p);
    }
    return x;
}
void Reverse(struct Node *p)
{
    struct Node *temp;

    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
            
    }
}
 int main()
 {
    int A[]={10,20,30,40,50};
    create(A,5);

    printf("Length is %d \n",Length(first));
    // Insert(first,0,80);
    // printf("Deleted Element is %d \n",Delete(first,1));
    Reverse(first);

    Display(first);

    return 0;
    
 }