#include<stdio.h>

void calculate(int n,int size,int start_position[size],int end_position[size],int change[size])
{
    int new_array[n];
    for(int i=0;i<n;i++)
    {
        new_array[i]=0;
    }

    for(int i=0;i<size;i++)
    {
        int start=(start_position[i])-1;
        int end=(end_position[i])-1;
        int credit=change[i];

        for(int j=start;j<=end;j++)
        {
            new_array[j]=new_array[j]+credit;
        }


    }

    int max=new_array[0];
    for(int i=1;i<n;i++)
    {
        if(new_array[i]>max)
        {
            max=new_array[i];
        }
        else
        continue;
    }

    printf("%d \n",max);


}

int main()
{

    int n,size;
    scanf("%d%d",&n,&size);

    int start_position[size];
    int end_position[size];
    int change[size];

    for(int i=0;i<size;i++)
    {
        int start,end,credit;
        scanf("%d%d%d",&start,&end,&credit);

        start_position[i]=start;
        end_position[i]=end;
        change[i]=credit;
    }

    calculate(n,size,start_position,end_position,change);

    return 0;
}
