#include<iostream>
using namespace std;
void calculate(int array_a[],int a,int length_a);
int count_no(int a[],int b[],int n);

void calculate(int array_a[],int a,int length_a)
{
    for(int i=0;i<length_a;i++)
    {
        array_a[i]=0;
    }

    int i=0;
    while(a>1)
    {
        int remainder=a%2;
        array_a[i]=remainder;
        i++;
        a=a/2;
    }
    array_a[i]=a;
}

int count_no(int a[],int b[],int n)
{
    int result=0;
   for(int i=0;i<n;i++)
   {
       if(a[i]!=b[i])
       {
           result++;
       }
   }

   return result;
}

int main()
{
    int a,b;
    cin>>a>>b;


    int array_a[8];
    int array_b[8];
    int length_a=sizeof(array_a)/sizeof(array_a[0]);
    calculate(array_a,a,length_a);


    for(int i=0;i<length_a;i++)
    {
        cout<<array_a[i]<<" ";
    }
    cout<<endl;
    int length_b=sizeof(array_b)/sizeof(array_b[0]);
    calculate(array_b,b,length_b);

    for(int i=0;i<length_b;i++)
    {
        cout<<array_b[i]<<" ";
    }
    cout<<endl;
    int result=count_no(array_a,array_b,length_a);
    cout<<result;
    return 0;
}
