#include<iostream>
#define M 3
#define N 4
using namespace std;

void spiral_move(int a[M][N],int m,int n);

void spiral_move(int a[M][N],int m,int n)
{

      int i=0,j=0,total=m*n,count_n=0;

      int temp_i=i,temp_j=j;

      while(count_n!=total)
      {
          int check=0;
          int stop_i=i+1,stop_j=j;
          for(j;j<n;j++)
          {
              if(count_n==total)
              {
                break;
              }
              else
            {
                count_n++;
                cout<<a[i][j]<<" ";
            }
          }j=j-1;

          for(i=i+1;i<m;i++)
          {
              if(count_n==total)
              {
                break;
              }
              else
            {
                count_n++;
                cout<<a[i][j]<<" ";
            }
          }i=i-1;

          for(j=j-1;j>=temp_j;j--)
          {
              if(count_n==total)
              {
                break;
              }
              else
            {
                count_n++;
                cout<<a[i][j]<<" ";
            }
          }j=j+1;

          for(i=i-1;i>=stop_i;i--)
          {
              if(count_n==total)
              {
                break;
              }
              else
              {
                    if(i==stop_i && j==stop_j)
                    {
                       count_n++;
                       cout<<a[i][j]<<" ";
                       i=temp_i+1;
                       j=temp_j+1;
                       m=m-1;
                       n=n-1;
                       break;
                    }
                    else
                    {
                        count_n++;
                        cout<<a[i][j]<<" ";
                    }
              }
          }

      }

}

int main()
{

    int a[M][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};


    spiral_move(a,M,N);

    return 0;
}
