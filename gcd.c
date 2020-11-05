#include<stdio.h>
#include<time.h>


int* prime(int);

int main()

{

int a,b;
int choice;

while(1)
{


printf("1. EUCLID ALGORITHM \n2.CONCEUTIVE INTEGER \n3.MIDDLE SCHOOL PROCEDURE\n4.SUCCESSIVE SUBTRACTION \n5.EXIT \n");
scanf("%d",&choice);

clock_t t,t1;

if(choice!=5)
{
printf("ENTER THE TWO NO'S : \n");

scanf("%d%d",&a,&b);}


switch(choice)
{
case 1:
    t = clock();
    euclid(a,b);
    t = clock() - t;
    float time_taken = ((float)t)/CLOCKS_PER_SEC;

    printf("EUCLID ALGORITHM TOOK %f SECONDS TO EXECUTE \n", time_taken);
    printf("------------------------------------------------------------ \n");
    break;

case 2:
    t1 = clock();
    consecutiveinteger(a,b);
    t1 = clock() - t1;
    float time_taken1 = ((float)t1)/CLOCKS_PER_SEC;

    printf("CONSECUTIVE ALGORITHM TOOK %f SECONDS TO EXECUTE \n", time_taken1);
    printf("--------------------------------------------------------- \n");
    break;

case 3:
t = clock();
        middleschool(a,b);
        t = clock() - t;
        double time_taken3 = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("\n It took %f seconds to execute \n", time_taken3);
        break;
break;

case 4:
t = clock();
        successivesubt(a,b);
        t = clock() - t;
        double time_taken4 = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("\n It took %f seconds to execute \n", time_taken4);
        break;

break;

default:
    break;

}

if(choice==5)
{break;}

}
return 0;
}


void euclid(int m,int n)
{

int r;
while(1)
{
r=m%n;
m=n;
n=r;

if(n==0)
{break;}
}
printf("--------------------------------------------------------- \n");
printf("THE GCD OF THE NO'S IS:%d \n",m);

}


void consecutiveinteger(int m,int n)
{

int t,result,mod;
if(m<=n)
t=m;
else
t=n;

result=t;
while(1)
{

if(t==n)
{
mod=m%result;

if(mod==0)
{
    printf("--------------------------------------------------------- \n");
    printf("THE GCD OF THE NO'S IS:%d \n",result);

break;}
else
result=result-1;
}

if(t==m)
{
mod=n%result;

if(mod==0)
{
    printf("--------------------------------------------------------- \n");
    printf("THE RESULT OF THE NO'S IS:%d \n",result);

break;}
else
result=result-1;
}
}

}


void successivesubt(int m,int n)
{
    int size = comparesize(m,n);
    do
    {
        if(m>n)
            m=m-n;
        else if(n>m)
            n=n-m;
        if(n < 0 || m < 0)
        {
            printf("1 is GCD");
            exit(0);
        }

    } while (n != m);

    printf("\n GCD is %d", m);

}

void middleschool(int m, int n)
{
    int primenumber = 1;

    int* primefactn = prime(n);

    for(int i = 0; primefactn[i] != '\0'; i++)
      printf("primefactn[%d] = %d", i, primefactn[i] );

    printf("\n");

    int* primefactm = prime(m);

    for(int i = 0; primefactn[i] != '\0'; i++)
      printf("primefactn[%d] = %d", i, primefactn[i] );

    printf("\n");

    for(int k=0; primefactn[k]!='\0';k++)
        {
            for(int j=0; primefactm[j]!='\0'; j++)
             {
                 if(primefactm[j] == primefactn[k])
                    {
                        primenumber = primefactm[j]*primefactm[j];
                        primefactm[j]=-1;
                        primefactn[k]=-1;
                        break;
                    }
             }
         }

      printf("   GCD: %d", primenumber);

}


int* prime(int m)
{
    static int arr[40] = {0};
    int k=0;
    while(m%2 == 0)
    {
        arr[k] = 2;
        k++;
        m = m/2;
    }

    for(int i =3; i <= sqrt(m); i = i+2)
    {
        while((m % i) == 0)
        {
            arr[k] = i;
            k++;
            m = m/i;
        }
    }

    if(m > 2)
    {
        arr[0] = 1;
        arr[1] = m;
    }

    return arr;
}


int comparesize(int m,int n)
{
    if(m<n)
    return 0;

    else if(m>n)
    return 1;

    else
    {
        printf("%d is GCD", m);
        exit(0);
    }

}
