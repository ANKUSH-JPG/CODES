#include<stdio.h>

void minimumswap(int arr_count, int arr[arr_count])
{
    int times=0;

    int temp[arr_count];
    int count[arr_count];
    for(int i=0;i<arr_count;i++)
    {
        temp[i]=i+1;
    }

    for(int i=0;i<arr_count;i++)
    {

        int element=arr[i];


        for(int j=0;j<arr_count;j++)
        {
            if(temp[j]==element)
            {

                count[i]=j-i;
            }
        }
    }

   while(1)
   {
       int min=count[0];int min_add;
       int max=count[0];int max_add;
       for(int i=1;i<arr_count;i++)
       {
           if(count[i]>max)
           {
               max=count[i];
               max_add=i;
            }

       }
       for(int i=1;i<arr_count;i++)
       {
           if(count[i]<min)
            {
                min=count[i];
                min_add=i;
            }

       }


       if(min==0 && max==0)
        break;

       if(min!=0 && max!=0)
       {
           times++;
           int difference=max_add-min_add;

           if(difference<0)
            difference=(-1)*difference;

           if(max_add>min_add)
           {
               int temp1;
               temp1=count[min_add];
               count[min_add]=count[max_add];
               count[max_add]=temp1;
                count[max_add]=count[max_add]-difference;
                count[min_add]=count[min_add]+difference;

           }
           if(min_add>max_add)
           {
               int temp1;
               temp1=count[max_add];
               count[max_add]=count[min_add];
               count[min_add]=temp1;
                count[max_add]=count[max_add]+difference;
                count[min_add]=count[min_add]-difference;

           }
       }


   }

   printf("%d",times);

}



int main()

{

    int arr_count;
    scanf("%d",&arr_count);

    int arr[arr_count];

    for(int i=0;i<arr_count;i++)
    {

        int no;
        scanf("%d",&no);

        arr[i]=no;
    }

    minimumswap(arr_count,arr);

    return 0;
}
