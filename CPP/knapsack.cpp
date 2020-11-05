#include<iostream>

using namespace std;
void quickSort(float a[],int l,int h);
int fixedPostion(float a[],int i,int j,int p);
void function_swap(float a[],int i,int j);
int calculate(float profit_per_weight[],float temp[],float profit[],float weight[],int n,float bag_max);

void quickSort(float a[],int l,int h)
{
    int p=l;

    if(l<h)
    {
    int j=fixedPostion(a,l,h,p);

    quickSort(a,l,j);
    quickSort(a,j+1,h);

    }



}

int fixedPostion(float a[],int i,int j,int p)
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
        function_swap(a,i,j);
    }

    }

    function_swap(a,p,j);

    return j;

}

void function_swap(float a[],int i,int j)
{
    float temp=a[i];

    a[i]=a[j];
    a[j]=temp;
}

int calculate(float profit_per_weight[],float temp[],float profit[],float weight[],int n,float bag_max)
{
    cout<<" 1"<<endl;
   float profit_array[n];

   for(int i=0;i<n;i++)
   {
       profit_array[i]=0;
   }

   for(int i=n-1;i>=0;i--)
   {
       float element=temp[i];

       for(int j=0;j<n;j++)
       {
           if(element==profit_per_weight[j])
           {

               if(bag_max!=0)
               {
                   if(weight[j]<=bag_max)
                   {
                       profit_array[j]=1;
                       bag_max=bag_max-weight[j];
                   }
                   else if(weight[j]>bag_max)
                   {
                       profit_array[j]=bag_max/weight[j];
                       bag_max=0;
                   }
               }

           }

       }
   }

   int result=0;
   for(int i=0;i<n;i++)
   {
       result=result+(profit[i]*profit_array[i]);
   }

    return result;
}


int main()

{


    int n;float bag_max;

    cin>>n>>bag_max;

    float profit[n];
    float weight[n];
    for(int i=0;i<n;i++)
    {
        cin>>profit[i];
    }

     for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }

    float profit_per_weight[n];
    float temp[n];
     for(int i=0;i<n;i++)
    {
        profit_per_weight[i]=profit[i]/weight[i];
        temp[i]=profit[i]/weight[i];
        cout<<profit_per_weight[i]<<" ";
    }

    cout<<endl;
    temp[n]=1000;
    int l=0,h=n;
    quickSort(temp,l,h);

    for(int i=0;i<=n;i++)
    {
        cout<<temp[i]<<" ";
    }

   int result=calculate(profit_per_weight,temp,profit,weight,n,bag_max);

   cout<<"THE FINAL PROFIT IS :"<<result;
    return 0;
}
