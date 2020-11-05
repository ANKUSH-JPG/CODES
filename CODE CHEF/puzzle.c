#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** crosswordPuzzle(int crossword_count, char** crossword, char* words, int* result_count) {

int count_empty_space[10];
int count_alphabet[10];

for(int i=0;i<10;i++)
{
    count_alphabet[i]=0;
}
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

    int j=0,element=0;
    int length=strlen(words);
    for(int i=0;i<10;i++)
    {
        element++;
        int count=0;
        while(j<length)
        {
            if(words[j]==';')
            {
                j++;
                break;
            }

            else
            {
                j++;
                count++;
            }


        }
        count_alphabet[i]=count;
    }

   for(int i=0;i<10;i++)
   {
       printf("%d \n",count_alphabet[i]);
   }
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** crossword = malloc(10 * sizeof(char*));

    for (int i = 0; i < 10; i++) {
        char* crossword_item = readline();

        *(crossword + i) = crossword_item;
    }

    int crossword_count = 10;

    char* words = readline();

    int result_count;
    char** result = crosswordPuzzle(crossword_count, crossword, words, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

