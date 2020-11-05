#include<iostream>

using namespace std;
void quickSort(double a[],int l,int h);
int fixedPostion(double a[],int i,int j,int p);
void function_swap(double a[],int i,int j);

void quickSort(double a[],int l,int h)
{
    int p=l;

    if(l<h)
    {
        int j=fixedPostion(a,l,h,p);

    quickSort(a,l,j);
    quickSort(a,j+1,h);

    }



}

int fixedPostion(double a[],int i,int j,int p)
{
    while(j>i)
    {
      cout<<"1"<<endl;
    while(a[i]<=a[p])
    {
        cout<<a[i]<<endl;
        cout<<"*"<<endl;
        i=i+1;

    }
    while(a[j]>a[p])
    {
        cout<<" *- "<<endl;
        j=j-1;
    }
    if(i<j)
    {
        cout<<"2"<<endl;
        function_swap(a,i,j);
    }

    }

    function_swap(a,p,j);

    return j;

}

void function_swap(double a[],int i,int j)
{
    double temp=a[i];

    a[i]=a[j];
    a[j]=temp;
}
int main()
{


    double a[8]={35,30,25,10,15,12,5,1000};

    int size_of_a=sizeof(a)/sizeof(a[0]);
    int l=0,h=size_of_a-1;
    quickSort(a,l,h);


    for(int i=0;i<size_of_a;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
