#include<stdio.h>

int main()

{

int n;

scanf("%d",&n);

int * array=(int *)malloc(n*sizeof(int));
for(int i=0;i<n;i++)
{
    int no;
    scanf("%d",&no);

    *(array+i)=no;
}

for(int i=0;i<n;i++)
{
    if(*(array+i)<10)
    {
        printf("What an obedient servant you are! \n");
    }
    else
    {
        printf("-1");
    }
}

}
