#include<stdio.h>

int main()
{
    char A[]="How are   u";
    int i; int wcount=1;
    for(i=0;A[i]!='\0';i++)
    {
        if(A[i]==' ' && A[i-1]!=' ')
            wcount++;
    }
    printf("There are %d words",wcount);
    return 0;
}
