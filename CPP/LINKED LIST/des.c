#include<stdio.h>
#include<stdlib.h>
#define KEY 64
#define INPUT 96


void key_generator(int s_k1[],int k1[])
{
    int count=0;
    int p=0;
    for(int i=0;i<KEY;i++)
    {count=count+1;

       if(count==8)
       {
           count=0;
           continue;
       }
       else
       {
           s_k1[p]=k1[i];
           p=p+1;
       }

    }
}

void ip(int input[],int LPT[],int RPT[])
{
    int position=INPUT/4;
    int move=position;
    for(int i=0;i<position/2;i++)
    {
        swap(input,i,move-i);
    }

    int first=move;
    move=move+position;
    for(int i=0;i<position/2;i++)
    {
        swap(input,first,move-i);
        first=first+1;
    }

    first=move;
    move=move+position;
    for(int i=0;i<position/2;i++)
    {
        swap(input,first,move-i);
        first=first+1;
    }
    first=move;
    move=move+position;
    for(int i=0;i<position/2;i++)
    {
        swap(input,first,move-i);
        first=first+1;
    }

    // BREAKING INTO LPT AND RPT
    int count=0;
    for(int i=0;i<INPUT;i++)
    {
        if(i<48)
         LPT[i]=input[i];

        else
        {
          RPT[count]=input[i];
          count=count+1;
        }
    }


}

void swap(int input[],int i,int j)
{
    int temp=input[i];
    input[i]=input[j];
    input[j]=temp;
}

void xor_operation(int LPT[],int RPT[],int k[])
{
    int temp[48];
    for(int i=0;i<48;i++)
    {
       temp[i]=RPT[i];
    }
    // PASSING TO FUNCTION THAT WILL PROCESS RPT WITH KEY.
    for(int i=0;i<48;i++)
    {
        if(RPT[i]!=k[i])
         RPT[i]=1;
        else
         RPT[i]=0;
    }

    // NOW XOR WITH LPT(GENERATION OF RPT)
    for(int i=0;i<48;i++)
    {
        if(RPT[i]!=LPT[i])
         RPT[i]=1;
        else
         RPT[i]=0;
    }

    // GENERATION OF LPT
    for(int i=0;i<48;i++)
    {
       LPT[i]=temp[i];
    }

}

int main()
{
    printf("************************* DES ENCRYPTION ********************** \n");

    printf("GENERATING KEY K1 AND K2 \n");

    int k1[KEY],k2[KEY];
    int count=0;

    printf("\n Key k1 64 bit:\n");
    for(int i=0;i<KEY;i++)
    {
        k1[i]=rand()%2;
        k2[i]=rand()%2;
    }

    for(int i=0;i<KEY;i++)
    {

       if(count%8==0)
        printf("\n%d ",k1[i]);

       else
        printf("%d ",k1[i]);

       count=count+1;
    }

    printf("\n\n Key k2 64 bit:\n");
    for(int i=0;i<KEY;i++)
    {

       if(count%8==0)
        printf("\n%d ",k2[i]);

       else
        printf("%d ",k2[i]);

       count=count+1;
    }

    int s_k1[56]={0};
    int s_k2[56]={0};

    key_generator(s_k1,k1);

    printf("\n\nKey k1 56 bit:\n");
    for(int i=0;i<56;i++)
    {
       printf("%d ",s_k1[i]);
    }

    key_generator(s_k2,k2);

    printf("\n\n Key k2 56 bit:\n");
    for(int i=0;i<56;i++)
    {
       printf("%d ",s_k2[i]);
    }

    // TEXT INPUT
    int input[INPUT];
    int LPT[48];
    int RPT[48];
    printf("\n\n96 bit Text input:\n");
    for(int i=0;i<INPUT;i++)
    {
        input[i]=rand()%2;
    }

    for(int i=0;i<INPUT;i++)
    {
        printf("%d ",input[i]);
    }

    ip(input,LPT,RPT);
    printf("\n\n96 bit permutated Text:\n");
    for(int i=0;i<INPUT;i++)
    {
        printf("%d ",input[i]);
    }

    printf("\n\nLPT:\n");
    for(int i=0;i<48;i++)
    {
        printf("%d ",LPT[i]);
    }

    printf("\n\nRPT:\n");
    for(int i=0;i<48;i++)
    {
        printf("%d ",RPT[i]);
    }

    //PERFORMAING XOR OPERATION FOR ROUND 1

    printf("\n-------------- ROUND 1:------------------\n");

    xor_operation(LPT,RPT,s_k1);

    printf("new LPT:");
    for(int i=0;i<48;i++)
    {
        printf("%d ",LPT[i]);
    }printf("\n");

    printf("new RPT:");
    for(int i=0;i<48;i++)
    {
        printf("%d ",RPT[i]);
    }printf("\n");


    printf("\n-------------- ROUND 2:------------------\n");

    xor_operation(LPT,RPT,s_k2);

    printf("new LPT:");
    for(int i=0;i<48;i++)
    {
        printf("%d ",LPT[i]);
    }printf("\n");

    printf("new RPT:");
    for(int i=0;i<48;i++)
    {
        printf("%d ",RPT[i]);
    }printf("\n");



    return 0;
}
