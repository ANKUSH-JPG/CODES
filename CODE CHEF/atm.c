#include<stdio.h>

int main()

{
int w;
float acc_balance;

scanf("%d %f",&w,&acc_balance);

if(w%5==0)
{
if(acc_balance>w)
{
    acc_balance=acc_balance-w-0.5;
    printf("%0.2f",acc_balance);
}
else
{
    printf("%0.2f",acc_balance);
}
}
else
{
    printf("%0.2f",acc_balance);
}

return 0;
}
