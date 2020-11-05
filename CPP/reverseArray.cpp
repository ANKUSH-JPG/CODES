#include<iostream>

using namespace std;

int main()
{

    int a[10]={10,20,30,40,50,60,70,80,90,100};
    int n=sizeof(a)/sizeof(int);

    for(int i=0;i<n/2;i++)
    {

        int temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
