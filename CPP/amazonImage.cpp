#include<iostream>
using namespace std;
void rotate_a(int a[][4],int n);

void rotate_a(int a[][4],int n)
{

   int i=0,check=n;

   while(check>=2)
   {


        for(int j=i;j<n-1-i;j++)
       {
           cout<<"*"<<endl;
           int count_n=0,temp;
           int p=i,q=j;
           while(count_n<4)
           {
               if(count_n==0)
               {
                   temp=a[q][n-1-p];
                   a[q][n-1-p]=a[p][q];
                   int x=p;
                   p=q;q=n-1-x;
               }
               else
               {
                   int t=a[q][n-1-p];
                   a[q][n-1-p]=temp;
                   temp=t;
                   int x=p;
                   p=q;q=n-1-x;
               }
               count_n++;
           }

       }

       check=check/2; i++;

   }

}

int main()
{

    int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    int n=4;
    rotate_a(a,n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
