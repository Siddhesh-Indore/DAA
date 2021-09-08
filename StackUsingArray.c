#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int Top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter the size of Stack ");
    scanf("%d",&st->size);
    st->Top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
    int i;
    for(i=st.Top;i>=0;i--)
    {
        printf("%d",st.S[i]);
        printf("\n");
    }
    
}

void push(struct Stack *st,int x)
{
    if(st->Top==st->size-1)
        printf("Stack Overflow\n");
    else
    {
        st->Top++;
        st->S[st->Top]=x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->Top==-1)
        printf("Stack Underflow");
    else
    {
        x=st->S[st->Top];
        st->Top--;
    }
    return x;
}

int peek(struct Stack st,int index)
{
    int x=-1;
    if(st.top-index+1<0)
        printf("Invalid Index\n");
    x=st.S[st.top-index+1];

    return x;
}
int IsEmpty(struct Stack st)
{
    if(st.Top==-1)
        return 1;
    else
        return 0;
}
int IsFull (struct Stack st)
{
    if(st.Top>st.size-1)
        return 1;
    else 
        return 0;
}
int StackTop(struct Stack st)
{
    if(!IsEmpty(st))
        return st.S[st.Top];
    return -1;
}
int main()
{
    struct Stack st;

    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    pop(&st);

    Display(st);
    return 0;
}
