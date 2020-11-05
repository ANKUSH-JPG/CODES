#include<stdio.h>
#include<time.h>


void add_element(int size,int * array)
{
    for(int i=0;i<size;i++)
    {
     *(array+i)=rand()%1000;
    }
}

void bubble_sort(int size,int * array)
{
    for(int i=1;i<size;i++)
	{
		for(int j=0;j<size-i;j++)
		{

			if(array[j+1]<array[j])
			{
			    int temp;
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}

void insertion_sort(int size,int *array)
{
    for(int i=1;i<size;i++){
      int temp=array[i];
      int j=i-1;
      while((temp<array[j])&&(j>=0)){
         array[j+1]=array[j];
         j=j-1;
      }
      array[j+1]=temp;
   }
}

void selection_sort(int size,int * array)
{
    int c,position,swap,d;
        for ( c = 0 ; c < ( size - 1 ) ; c++ )
   {
      position = c;

      for ( d = c + 1 ; d <size ; d++ )
      {
         if ( array[position] > array[d] )
            position = d;
      }
      if ( position != c )
      {
         swap = array[c];
         array[c] = array[position];
         array[position] = swap;
      }
   }
}


void display(int size,int * array)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",*(array+i));
    }
}

int main()

{
    int size;
    float time_spent=0.0;
    float time_spenti=0.0;
    float time_spents=0.0;

    int choice;
    clock_t start;
    clock_t end;

    printf("ENTER THE SIZE OF THE ARRAY :");
    scanf("%d",&size);
    printf("\n");
    int  * array=(int *)malloc(size * sizeof(int));



    add_element(size,array);




    printf("SELECT THE SORTING TECHNIQUE :\n 1.BUBBLE SORT \n 2. INSERTION SORT \n 3.SELECTION SORT \n ");
    scanf("%d",&choice);

    switch(choice)

    {
    case 1:
        start = clock();
        bubble_sort(size,array);
        end = clock();
        time_spent=((float)(end-start)/ CLOCKS_PER_SEC);
        printf("THE TIME TAKEN IS :%f\n",time_spent);
        break;
    case 2:
        start = clock();
        insertion_sort(size,array);
        end = clock();
        time_spenti=((float)(end-start)/ CLOCKS_PER_SEC);
        printf("THE TIME TAKEN IS :%f\n",time_spenti);
        break;
    case 3:
        start = clock();

        selection_sort(size,array);
        end = clock();
        time_spents=((float)(end-start)/ CLOCKS_PER_SEC);
        printf("THE TIME TAKEN IS :%f\n",time_spents);
        break;


    }

    display(size,array);



}
