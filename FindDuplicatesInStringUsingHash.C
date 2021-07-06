#include<stdio.h>

int main()
{
    char A[]="Finding";
    int H[26],i;
    for(i=0;i<26;i++)
    {
        H[i]=0;
    }

    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]+=1;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            printf(" \n %c is occuring %d times",i+97,H[i]);
        }
    }
    return 0;
}