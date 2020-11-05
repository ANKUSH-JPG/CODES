#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

char* passwordCracker(int passwords_count, char** passwords, char* loginAttempt) {


    int result=calculate(passwords_count,passwords,loginAttempt);

    if(result==1)
    {

        return '1';
    }
    else
    {
        return '0';
    }
}

int calculate(int passwords_count, char** passwords, char* loginAttempt)
{

    if(passwords_count==0)
    {
        return 0;

    }
    else
    {


    int value=calculate(passwords_count-1,passwords,loginAttempt);

        if(value==1)
        {
          return 1;
        }
        else
        {
            int length=strlen(*(passwords+passwords_count-1));
    char pass_check[length];

    for(int i=0;i<length;i++)
    {
        pass_check[i]=*(*(passwords+passwords_count-1)+i);

    }
            int check=0;
            for(int j=0;j<length;j++)
            {
                if(pass_check[j]==loginAttempt[j])
                {
                    check=1;
                    continue;
                }
                else
                {
                    check=0;
                    break;
                }
            }

            if(check=1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }


    }
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        char** passwords_temp = split_string(rtrim(readline()));

        char** passwords = malloc(n * sizeof(char*));

        for (int i = 0; i < n; i++) {
            char* passwords_item = *(passwords_temp + i);

            *(passwords + i) = passwords_item;
        }

        char* loginAttempt = readline();

        char* result = passwordCracker(n, passwords, loginAttempt);

        if(result=='1')
        {
            char new_array[3]="YES";
            printf("%s \n",new_array);
        }
        else
        {
            char new_array[14]="WRONG PASSWORD";
            printf("%s \n",new_array);
        }
    }

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

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

