#include<stdio.h>

int main()

{

int round,winner,max_lead;

scanf("%d",&round);
int * p1=(int *)malloc(round*sizeof(int));
int * p2=(int *)malloc(round*sizeof(int));

int * w=(int *)malloc(round*sizeof(int));
int * l=(int *)malloc(round*sizeof(int));

for(int i=0;i<round;i++)
{
    int sp1,sp2;
    scanf("%d",&sp1);

    *(p1+i)=sp1;

    scanf("%d",&sp2);
    *(p2+i)=sp2;

}

for(int i=0;i<round;i++)
{
    if(*(p1+i)>*(p2+i))
    {
        int lead;
        *(w+i)=1;
        lead=(*(p1+i))-(*(p2+i));

        *(l+i)=lead;
    }
    else
    {
        int lead;
        *(w+i)=2;

        lead=(*(p2+i))-(*(p1+i));

        *(l+i)=lead;
    }
}

max_lead=*(l+0);
winner=*(w+0);
for(int i=1;i<round;i++)
{
    if(max_lead<*(l+i))
    {
        max_lead=*(l+i);
        winner=*(w+i);
    }
}

printf("%d %d",winner,max_lead);
return 0;
}
