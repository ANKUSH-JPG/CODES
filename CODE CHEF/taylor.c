#include<stdio.h>


double e(int x,int n)
{
    static double p=1;
    static double q=1;

    if(n==0)
    {
        return 1;
    }
    else
    {
        double value=e(x,n-1);
        p=p*x;
        q=q*n;

        return value+p/q;
    }

}

int main()

{

int x,n;

scanf("%d%d",&x,&n);

double result=e(x,n);

printf("%lf",result);
return 0;
}
