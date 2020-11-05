#include<stdio.h>

int* calculate(int *pointer,int product,int n);

void function(int *pointer,int product,int n)
{
    int start=1;
    int* array=calculate(pointer,product,n,start);


    for(int i=0;i<3;i++)
    {
        printf("%d",*(array+i));
    }
}

int* calculate(int *pointer,int product,int n,int start)
{

static int check=0;
static int not_found[1]={-1};
static int found_elements[product];
static int elements_array[product][product];
static int product_array[3][3];

for(int i=0;i<product;i++)
{
    elements_array[i][0]=1;
}

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        product

    }
}

}

int main()
{

    int product;
    scanf("%d",&product);
    int n;
    scanf("%d",&n);

    int nos[n];
    int *pointer=nos;
    for(int i=0;i<n;i++)
    {
        int digit;
        scanf("%d",&digit);

        nos[i]=digit;
    }

    function(pointer,product,n);

    return 0;
}
