#include <stdio.h>
#include<stdlib.h>

int main()
{

char name[50];

printf(" enter name: ");

scanf("%[^\n]%*c",name);

printf("%s",name);
  return 0;
}
