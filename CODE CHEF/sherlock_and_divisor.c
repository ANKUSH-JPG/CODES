#include<stdio.h>


void divisor(int no,int * new_array)
{
    for(int i=0;i<no;i++)
    {
        int element=*(new_array+i);
        int count=0;

        for(int j=1;j<=element;j++)
        {
            if(element%j==0)
            {
                if(j%2==0)
                    count++;
                else
                    continue;
            }
            else
                continue;

        }
        printf("%d\n",count);
    }
}

int main()

{
    int no;
    scanf("%d",&no);

    int * new_array=(int *)malloc(no * sizeof(int));

    for(int i=0;i<no;i++)
    {
        int element;

        scanf("%d",&element);
        *(new_array+i)=element;
    }

    divisor(no,new_array);

    return 0;
}
