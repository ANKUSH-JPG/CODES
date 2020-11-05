#include<iostream>

using namespace std;



void multistage_graph(int a[12][12],int n,int cost[],int d[])
{

   for(int i=n-1;i>=0;i--)
  {
     int check=0;int j=0;

     for(j;j<n;j++)
     {
         if(a[i][j]!=0)
         {
             check=1;break;
         }
     }

     if(check==0)
     {
         cost[i]=0;d[i]=n;
     }
     if(check==1)
     {
         int c=0;
         for(int k=j;k<n;k++)
     }

    }

}

int main()
{
    int n;
    cin>>n;

    int a[12][12]={{0,9,7,1,2,0,0,0,0,0,0,0},{0,0,0,0,0,4,2,1,0,0,0,0},{0,0,0,0,0,2,7,0,0,0,0,0},{0,0,0,0,0,0,0,11,0,0,0,0},{0,0,0,0,0,0,11,8,0,0,0,0}
                ,{0,0,0,0,0,0,0,0,6,5,0,0},{0,0,0,0,0,0,0,0,4,3,0,0},{0,0,0,0,0,0,0,0,0,5,6,0},{0,0,0,0,0,0,0,0,0,0,0,4},{0,0,0,0,0,0,0,0,0,0,0,2}
                ,{0,0,0,0,0,0,0,0,0,0,0,5},{0,0,0,0,0,0,0,0,0,0,0,0}};


    int cost[n];
    int d[n];
    multistage_graph(a,n,cost,d);


    return 0;
}
