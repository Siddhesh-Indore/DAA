#include<stdio.h>

int main()
{
    char A[] = "madam";
    char B[6];
    int i;int j;
    for(i=0;A[i]!='\0';i++)
    {}
    i=i-1;
    for(j=0;i>=0;i--,j++)
    {
        B[j]=A[i];
    } 
    B[j]='\0';
    for(i=0,j=0;A[i]!='\0' && B[j]!='\0';i++,j++)
    {
        if(A[i]!=B[j])
            break;
    }
    if(A[i]==B[j])
        printf("Equal");
    else if(A[i]<B[j])
        printf("Smaller");
    else
        printf("Larger");

    return 0;
}
