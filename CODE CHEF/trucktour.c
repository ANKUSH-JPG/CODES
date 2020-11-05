#include<stdio.h>

int find(int n,int * capacity_petrol,int * next_petrol_pump)
{
   int result;

    for(int i=0;i<n;i++)
    {
        if(*(capacity_petrol+i)>*(next_petrol_pump+i))
            {
                int left_petrol=*(capacity_petrol+i)-(*(next_petrol_pump+i));
                int check,k;

                for(int j=i+1;j<n;j++)
                {
                    if((left_petrol+*(capacity_petrol+j))>*(next_petrol_pump+j))
                    {
                        left_petrol=(left_petrol+*(capacity_petrol+j))-(*(next_petrol_pump+j));
                        check=1;
                        continue;
                    }
                    else
                    {
                        check=0;
                        break;
                    }
                }

                if(check==1)
                {
                    for(k=0;k<i;k++)
                    {
                        if((left_petrol+*(capacity_petrol+k))>*(next_petrol_pump+k))
                        {
                            left_petrol=(left_petrol+*(capacity_petrol+k))-(*(next_petrol_pump+k));
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                if(k==i)
                {
                    return i;
                }

            }
        else
            continue;
    }
}

int main()

{



    int n;
    scanf("%d",&n);

    int * capacity_petrol=(int *)malloc(n*sizeof(int));
    int * next_petrol_pump=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        int petrol,petrol_pump;
        scanf("%d%d",&petrol,&petrol_pump);

        *(capacity_petrol+i)=petrol;
        *(next_petrol_pump+i)=petrol_pump;
    }

    int result=find(n,capacity_petrol,next_petrol_pump);

    printf("%d",result);

    return 0;
}
