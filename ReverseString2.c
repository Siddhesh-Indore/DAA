#include<stdio.h>

int main()
{
    char A[] = "Python";
    char t;
    int i;int j;
    for(j=0;A[j]!='\0';j++)
    {}
    j=j-1;
    for(i=0;i<j;j++,i--)
    {
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    } 
    A[j]='\0';
    printf("%s",A);
    return 0;
}
