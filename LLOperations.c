#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

struct Node 
{
    int data;
    struct Node *next;
}*first=NULL;

void create (int A[],int n)
{
    int i;
    struct Node *t, *last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;  
    }

}
void Dispaly(struct Node *p)
{
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    
}

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        RDisplay(p->next);
    }
}
int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
int Rcount(struct Node *p)
{
    if(p!=0)
    {
        return Rcount(p->next)+1;
    }
    else
        return 0;
}
int sum(struct Node *p)
{
    int s=0;
    while (p)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int Rsum(struct Node *p)
{
    if(p!=0)
    {
        return Rsum(p->next)+p->data;
    }
    else 
        return 0;
}
int max(struct Node *p)
{
    int m=INT_MIN;
    while (p)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}
int Rmax(struct Node *p)
{
    int x=0;
    if(p==0)
    {
        return INT_MIN;
    }
    x=Rmax(p->next);
    if(x>p->data)
        return x;
    else 
        return p->data;
}
struct Node * LSearch(struct Node *p,int key)
{
    struct Node *q;
    while(p)
    {
        if(key==p->data)
        {
            q->next =p->next;
            p->next=first;
            first=p;
            return p;

        }
        q=p;
        p=p->next;
    }
    return NULL;
}
struct Node * RSearch(struct Node *p,int key)
{
     if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);
}
void Insert (struct Node *p,int x,int index)
{
    struct Node *t;
    int i;
    if(index < 0 || index > count(p))
        return;
   t=(struct Node*)malloc(sizeof(struct Node));
   t->data=x;

   if(index == 0)
   {
       t->next =first;
       first = t;
   }
   else 
   {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next = p->next;
        p->next=t;
   }
}
int main ()
{
    // struct Node *temp;
    // int A[]={3,5,7,10,15,8,12,20};

    // create (A,3);
    Insert(first,10,0);
    Insert(first,20,1);
    Insert(first,40,2);
    Insert(first,78,3);
    Insert(first,18,0);
    Dispaly(first);
   
    // printf("\nLength of List is %d",Rcount(first));
    // printf("\nSum is %d",Rsum(first));
    // printf("\nMax is %d",Rmax(first));
    // temp=LSearch(first,12);
    // if(temp)
    // {
    //     printf("\nKey is found %d\n",temp->data);
    // }
    // else 
    //     printf("\nKey Not Found\n");
    
    return 0;
    
}