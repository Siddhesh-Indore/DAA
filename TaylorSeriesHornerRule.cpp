#include <stdio.h>

double e(double x,double n)
{
    static double s=1;
    if (n==0)
        return s;
    s=1+s*x/n;
    return e(x,n-1);
}

int main()
{
    double r;
    r=e(1,10);
	printf("%f",r);
	return 0;
}
