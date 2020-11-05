#include<stdio.h>

int main()

{

int n;


scanf("%d",&n);
int * array_i=(int *)malloc(n * sizeof(int));

for(int i=0;i<n;i++)
{
    int a,b,c;
    int result=0;
    scanf("%d",&a);

    for(int j=0;j<1;j++)
    {
        c=a%10;
    }

    while(a!=0)
    {
        b=a%10;
        a=a/10;
    }
    result=b+c;

    *(array_i+i)=result;
}

for(int i=0;i<n;i++)
{
    printf("%d\n",*(array_i+i));
}
return 0;
}
