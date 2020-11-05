#include<stdio.h>

int main()
{
    int n,k;

    int count=0;

    scanf("%d %d",&n,&k);

    int * d_array=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        int no;
        scanf("%d",&no);

        *(d_array+i)=no;
    }


    for(int i=0;i<n;i++)
    {
        if(*(d_array+i)%k==0)
        {
            count=count+1;
        }
    }

    printf("%d",count);

    return 0;
}
