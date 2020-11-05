#include<stdio.h>

int activityNotification(int d,int *expenditure,int expenditure_count)
{
    int * new_array=(int *)malloc(d * sizeof(int));
    int count=0,check=0;
    float median;

    for(int i=0;i<d-1;i++)
    {
        if(check==*(expenditure+d))
        {
            break;
        }
        else
        {
        int j;
        for(j=i;j<i+expenditure_count;j++)
        {
            for(int b=j+1;b<i+expenditure_count;b++)
           {
               if(*(expenditure+j)>*(expenditure+b))
               {
                   int temp;
                   temp=*(expenditure+j);
                   *(expenditure+j)=*(expenditure+b);
                   *(expenditure+b)=temp;
               }
               else
               {

               }
            }
        }
        check=*(expenditure+j);

            if(expenditure_count%2==0)
            {
                int mid1=(i+i+expenditure_count-1)/2;
                int mid2=mid1+1;

                median=(*(expenditure+mid1)+*(expenditure+mid2))/2;
            }
            else
            {

                int mid=(i+i+expenditure_count-1)/2;

                median=*(expenditure+mid);

            }
            }

            if(check>=(median*2))
            {
                count=count+1;
            }
            else
            {

            }
    }



    return count;
}

int main()

{

int d,expenditure_count;

scanf("%d%d",&d,&expenditure_count);

int * expenditure=(int *)malloc(d * sizeof(int));

for(int i=0;i<d;i++)
{
    int n;
    scanf("%d",&n);

    *(expenditure+i)=n;
}

int result=activityNotification(d,expenditure,expenditure_count);

printf("%d",result-1);
}
