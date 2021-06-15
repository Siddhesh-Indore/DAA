#include <stdio.h>

int fact(int n)
{
    if (n==0)
    {
        return 1;
    }
    else
        return fact(n-1)*n;
}
int C(int n,int r)
{
    int t0,t1,t2;
    t0=fact(n);
    t1=fact(r);
    t2=fact(n-r);
    return t0/(t1*t2);
}
int Com(int n,int r)
{
    if(r==0||n==r)
        return 1;
    else
        return Com(n-1,r-1)+Com(n-1,r);
}
int main()
{
	printf("%d",C(4,2));
    printf("%d",Com(4,2));
	return 0;
}
