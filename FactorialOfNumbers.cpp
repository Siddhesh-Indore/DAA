#include <stdio.h>
int fact(int n)
{
    if (n==0)
        return 1;
    return fact(n-1)*n;
}

int Ifact(int n)
{
    int f=1;
    int i;
    for(i=1;i<=n;i++)
        f=f*i;
    return f;
}
int main()
{
    int p;
    int q;
    p=fact(15);
    q=Ifact(6);
	printf("%d %d",p,q);
	return 0;
}
