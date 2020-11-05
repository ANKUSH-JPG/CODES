#include<stdio.h>

void do_rotation(int n,int rotation,int * new_array)
{
    int * temp=(int *)malloc(n*sizeof(int));
    int final;
    for(int i=0;i<n;i++)
    {
        temp[i]=new_array[i];

    }

    for(int i=n-1;i>=0;i--)
    {
        final=i-rotation;
        int address;

        if(final>=0)
        {
            temp[final]=new_array[i];
        }
        else if(final<0)
        {
            address=n-1+final;
            temp[address]=new_array[i];
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d",temp[i]);
    }

}

int main()

{


    int n,rotation;

    scanf("%d%d",&n,&rotation);

    int * new_array=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        int no;
        scanf("%d",&no);

        new_array[i]=no;
    }

    do_rotation(n,rotation,new_array);
    return 0;
}
