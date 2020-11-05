#include<stdio.h>
#include<stdlib.h>

int main()
{
    int string_size;
    char string[10];
    scanf("%d",&string_size);

    char ** string_array=(char **) malloc(string_size * sizeof(char *));

    for(int i=0;i<string_size;i++)
    {
        scanf("%s",&string);

        int length=strlen(string);
        string_array[i]=(char *) malloc( length * sizeof(char));

        for(int j=0;j<length;j++)
        {
            string_array[i][j]=string[j];
        }
    }


    return 0;
}
