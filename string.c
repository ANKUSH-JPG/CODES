#include<stdio.h>
#include<stdlib.h>

int main()
{

    int no_of_strings;
    char string_array[50];
    scanf("%d",&no_of_strings);

   char ** new_array=(char **)malloc(no_of_strings * sizeof(char *));
   int * new_array_length=(int *)malloc(no_of_strings * sizeof(int));

    for(int i=0;i<no_of_strings;i++)
    {

        scanf("%s",&string_array);


        int length=strlen(string_array);
        *(new_array_length+i)=length;
        new_array[i]=(char *)malloc(length * sizeof(char));

        for(int j=0;j<length;j++)
        {
            new_array[i][j]=string_array[j];
        }
    }

    l_increasing(new_array,new_array_length,no_of_strings);

    return 0;
    }



void l_increasing(char ** new_array,int * new_array_length,int no_of_strings)
{
    char * fake=(char *)malloc(no_of_strings * sizeof(char));
    char random;
    for(int i=0;i<no_of_strings;i++)
    {
        *(fake+i)=new_array[i][0];
    }

    for(int i=0;i<no_of_strings-1;i++)
    {
        for(int j=i+1;j<no_of_strings;j++)
        {
            if(*(fake+i)>*(fake+j))
            {
                random=*(fake+i);
                *(fake+i)=*(fake+j);
                *(fake+j)=random;
            }
        }
    }

    printf(" THIS IS THE INCREASING ORDER : \n");
    for(int i=0;i<no_of_strings;i++)
    {
        for(int j=0;j<no_of_strings;j++)
        {
            if(*(fake+i)==new_array[j][0])
            {
                int value=*(new_array_length+j);
                for(int k=0;k<value;k++)
                {
                    printf("%c",new_array[j][k]);
                }
            }
        }
        printf("\n");
    }
}
