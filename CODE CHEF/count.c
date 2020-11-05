#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int powerSum(int X, int N) {

    int I=1;
    for(I;I<X;I++)
    {
        if(pow(I,N)<=X)
            continue;
        else
            break;

    }I--;
    int result=cal(X,N,I);


    return result;

}

int cal(int X,int N,int I)
{
    static int count=0;

    if(I<=0)
        return 0;
    else
    {
        cal(X,N,I-1);
        int difference=X-pow(I,N);

        if(difference==0)
        {
            count++;
        }
        if(difference!=0)
        {
            int value=cal(difference,N,I-1);
        }

        return count;
    }
    }


int main()
{

    int X,N;
    scanf("%d%d",&X,&N);

    int result=powerSum(X,N);

    printf("%d",result);
    return 0;
}
