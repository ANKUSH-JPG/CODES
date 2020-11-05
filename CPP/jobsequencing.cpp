#include<iostream>
#include<vector>
using namespace std;
void get_values(double a[],int n);
void quickSort(double a[],int l,int h,double b[]);
int fixedPostion(double a[],int i,int j,int p,double b[]);
void function_swap(double a[],int i,int j,double b[]);
void final_cal(double m[],double p[],double d[],int h);



void get_values(double a[],int n)
{
    for(int i=0;i<n;i++)
    {
       double p;cin>>p;

        a[i]=p;
    }
}

void quickSort(double a[],int l,int h,double b[])
{
    int p=l;

    if(l<h)
    {
        int j=fixedPostion(a,l,h,p,b);

    quickSort(a,l,j,b);
    quickSort(a,j+1,h,b);

    }



}

int fixedPostion(double a[],int i,int j,int p,double b[])
{
    while(j>i)
    {

    while(a[i]<=a[p])
    {
        i=i+1;

    }
    while(a[j]>a[p])
    {

        j=j-1;
    }
    if(i<j)
    {

        function_swap(a,i,j,b);
    }

    }

    function_swap(a,p,j,b);

    return j;

}

void function_swap(double a[],int i,int j,double b[])
{
    double temp=a[i];

    a[i]=a[j];
    a[j]=temp;

    double temp1=b[i];

    b[i]=b[j];
    b[j]=temp1;
}

int max_cal(double d[],int h)
{
    int result=d[0];

    for(int i=1;i<h;i++)
    {
        if(d[i]>result)
        {
            result=d[i];
        }
    }

    return result;
}

void final_cal(double m[],double p[],double d[],int h)
{
    for(h;h>=0;h--)
    {
        int place=d[h]-1;

        if(m[place]==0)
            m[place]=p[h];
        else
        {
            for(int i=0;i<place;i++)
            {
                if(m[i]==0)
                {
                   m[i]=p[h];
                   break;
                }
            }
        }
    }
}

int main()
{
  int n;
  cout<<"ENTER THE NO OF JOBS:";
  cin>>n;
  double profit[n];
  double deadline[n];
  cout<<"ENTER THE PROFIT ARRAY:"<<endl;
  get_values(profit,n);
  cout<<"ENTER THE DEADLINE ARRAY:"<<endl;
  get_values(deadline,n);

  int size_of_p=sizeof(profit)/sizeof(profit[0]);
  int l=0,h=size_of_p-1;
  quickSort(profit,l,h,deadline);


  int maximum=max_cal(deadline,h);
  double max_profit[maximum];

  for(int i=0;i<maximum;i++)
  {
      max_profit[i]=0;
  }

  final_cal(max_profit,profit,deadline,h);

  for(int i=0;i<maximum;i++)
  {
      cout<<max_profit[i]<<" ";
  }
  return 0;
  }
