#include<stdio.h>
#include<stdlib.h>

void solve_puzzle(char crossword[10][10],char word[10][10],int * temp_array)
{
    int count_empty_space[10];


    for(int i=0;i<10;i++)
    {
        int count=0;
        for(int j=0;j<10;j++)
        {
            if(crossword[i][j]=='-')
            {
                count++;

            }
            else
            {
                continue;
            }

        }
        count_empty_space[i]=count;
    }

    for(int i=0;i<10;i++)
    {
        printf("%d \n",count_empty_space[i]);
    }
}

int main()

{

    char crossword[10][10];
    char word[10][10];
    int temp_length;


    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            int symbol;
            scanf("%c",&symbol);

            crossword[i][j]=symbol;
        }
    }

    int no_of_words;
    scanf("%d",&no_of_words);

    int * temp_array=(int *)malloc(no_of_words * sizeof(int));

    for(int i=0;i<no_of_words;i++)
    {
        int count=0;
        char temp[10];
        scanf("%s",&temp);

        temp_length=strlen(temp);
        *(temp_array+i)=temp_length;
        do
        {
            word[i][count]=temp[count];
           count++;
        }while(count<temp_length);
}

    solve_puzzle(crossword,word,temp_array);

return 0;
}
