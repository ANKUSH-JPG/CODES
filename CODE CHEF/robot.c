#include<stdio.h>

int main()

{
    int t;

    scanf("%d",&t);

    int * array_i=(int *)malloc(t * sizeof(int));

    for(int i=0;i<t;i++)
    {
        int a,b;
        int c;

        scanf("%d%d",&a,&b);

        c=a+b;
        *(array_i+i)=c;
    }

    for(int i=0;i<t;i++)
    {
        printf("%d\n",*(array_i+i));
    }
    return 0;
}
