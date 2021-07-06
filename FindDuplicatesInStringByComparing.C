#include<stdio.h>

int main()
{
char A[]= "Finding";
int i,j;


for(i=0;A[i]!='\0';i++)
  {
    int count=1;
    if(A[i]!=-1)
    {
      for(j=i+1;A[j]!='\0';j++)
      {
        if(A[i]==A[j])
        {
          count++;
          A[j]=-1;
        }
      }
      if(count>1)
      {
        printf(" \n %c is occuring %d times",A[i],count);
    
      }
    }
  }
  return 0;
}


