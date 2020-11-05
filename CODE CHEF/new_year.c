#include<stdio.h>


void calculate(int size,int new_array[size])
{
    int temp[size];
    int bribe[size];
    for(int i=0;i<size;i++)
    {
        temp[i]=i+1;
        bribe[i]=0;
    }


    for(int i=0;i<size;i++)
    {
        int count=0;
        int element=temp[i];
        int location;

        for(int j=0;j<size;j++)
        {
            if(new_array[j]==element)
            {
                location=j;
                break;
            }
        }

        int check=0;
        while(location!=i)
        {
            if(i<location)
            {
                bribe[i]=0;
                check=1;
                break;
            }
            else if(i>location)
            {
                count++;
                bribe[i]=count;
                int def=new_array[location];
                new_array[location]=new_array[location+1];
                new_array[location+1]=def;
                location++;
                check=1;

            }

        }

        if(i==location)
        {
            if(check==0)
            {
                bribe[i]=0;
            }
        }
    }

    int sum=0;
    int check_bribe=0;
    for(int i=0;i<size;i++)
    {
        if(bribe[i]<=2)
        {
            sum=sum+bribe[i];
        }
        else if(bribe[i]>2)
        {
            check_bribe=1;
            break;
        }
    }

    if(check_bribe==1)
    {
        printf("Too chaotic \n");
    }
    else
    {
        printf("%d\n",sum);
    }

}

int main()

{

    int times;
    scanf("%d",&times);

    for(int i=0;i<times;i++)
    {
        int size;
        scanf("%d",&size);

        int new_array[size];

        for(int j=0;j<size;j++)
        {
            int no;
            scanf("%d",&no);

            new_array[j]=no;
        }

        calculate(size,new_array);


    }

    return 0;

}
