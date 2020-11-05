#include<stdio.h>


int power(int m,int n)
{

    if(n==1)
        return m;
    else
    {
        int a=power(m,n-1)*m;
        return a;

    }

}

int main()

{


int m,n;

scanf("%d%d",&m,&n);

int result=power(m,n);

printf("%d",result);
}
