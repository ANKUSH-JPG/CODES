#include<stdio.h>
#include<time.h>


int main()

{
    int size;
    float time_spent=0.0;
    float time_spentu=0.0;
    float time_spentm=0.0;

    int choice;

    printf("ENTER THE SIZE OF THE ARRAY :");
    scanf("%d",&size);

    int  * array=(int *)malloc(size * sizeof(int));

    clock_t start = clock();

    add_element(size,array);

    clock_t end = clock();

    time_spent=((float)(end-start)/ CLOCKS_PER_SEC);

    display(size,array);
    printf("THE TIME TAKEN BY THE ARRAY IS : %f \n",time_spent);

    printf("\n");
    printf("-------------------------------------------------------------------------------------- \n");
    printf("WHAT IS YOUR CHOICE: \n");
    printf("1. ARRAY UNIQUENESS                  2. MAXIMUM ELEMENT OF THE ARRAY \n\n");

    scanf("%d",&choice);

    if(choice==1)
    {
        clock_t start = clock();
        array_uniqueness(size,array);
        clock_t end = clock();
        time_spentu=((float)(end-start)/ CLOCKS_PER_SEC);

        printf("THE TIME TAKEN BY THE ARRAY TO CHECK UNIQUENESS IS : %f \n",time_spentu);
    }
    else if(choice==2)
    {
        clock_t start = clock();

        maximum_element(size,array);

        clock_t end = clock();
        time_spentm=((float)(end-start)/ CLOCKS_PER_SEC);

        printf("THE TIME TAKEN BY THE ARRAY TO CHECK MAXIMUM ELEMENT IS : %f \n",time_spentm);
    }


return 0;
}

void add_element(int size,int * array)
{
    for(int i=0;i<size;i++)
    {
     *(array+i)=rand()%100000;
    }
}

void display(int size,int * array)
{
    for(int i=0;i<size;i++)
    {
        printf("%d \n",*(array+i));
    }
}

void array_uniqueness(int size,int * array)
{
    int finish=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(*(array+i)==*(array+j))
            {
                printf("**************** THE ARRAY IS NOT FOUND UNIQUE ***************** \n\n");
                finish=1;
                break;
            }
        }
        if(finish==1)
            break;
    }
}

void maximum_element(int size,int * array)
{
    int max_element;

    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(*(array+i)<*(array+j))
            {
                max_element=*(array+j);
            }
            else
            {
                max_element=*(array+i);
            }
            }
        }

        printf(" ********************* THE MAXIMUM ELEMENT FOUND IS : %d ******************* \n",max_element);
    }

