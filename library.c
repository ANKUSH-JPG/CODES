#include<stdio.h>

int main()
{

    int shelf,queries;
    int check=0;

    scanf("%d",&shelf);
    scanf("%d",&queries);

    int ** new_array=(int **)malloc(shelf * sizeof(int *));

    int * count=(int *)malloc(shelf * sizeof(int));

    for(int i=0;i<shelf;i++)
    {
        new_array[i]=(int *)malloc(1000 * sizeof(int));
        *(count+i)=0;
    }

    while(check<queries)
    {
        int first;
        scanf("%d",&first);

        if(first==1)
        {//INSERT Y PAGES TO THE X SHELF
            int x,y,z;
            scanf("%d%d",&x,&y);

            z=*(count+x);
            new_array[x][z]=y;
            *(count+x)=(*(count+x))+1;
        }

        else if(first==2)
        {//PRINT THE PAGES IN THE X SHELF AT Y BOOK
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d \n",new_array[x][y]);

        }

        else if(first==3)
        {//TOTAL NO OF BOOKS AT THE PARTICULAR SHELF
            int x;
            scanf("%d",&x);
            printf("%d \n",*(count+x));

        }
        check++;
    }

    return 0;
}
