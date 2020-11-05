#include<iostream>

using namespace std;
int BS(int a[],int n,int key);
int calculate(int a[],int n,int key,int l,int h,int mid);

int BS(int a[],int n,int key)
{
    int l=0,h=n-1,mid=0;

    int result=calculate(a,n,key,l,h,mid);

    return result;
}

int calculate(int a[],int n,int key,int l,int h,int mid)
{
    if(l>h)
    {
        return 1000;
    }
    else{

        mid=(l+h)/2;

    if(key>a[mid])
    {
        return calculate(a,n,key,mid+1,h,mid);
    }
    else if(key==a[mid])
    {
        return mid;
    }
    else
    {
        return calculate(a,n,key,l,mid-1,mid);
    }
    }


}
int main()

{

   int a[10]={3,6,8,12,15,24,25,30,36,89};

   int key=5;
   int n=BS(a,10,key);

   cout<<"FOUND AT INDEX:"<<n;
   return 0;
}
