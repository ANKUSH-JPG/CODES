#include<iostream>
#include<bits/stdc++.h>
using namespace std;

priority_queue<int> p;

void calculate(int a[])
{
    int x,b,add;
    cin>>x>>b>>add;

    for(int i=x-1;i<=b-1;i++)
    {
         a[i]=a[i]+add;
         p.push(a[i]);
    }
}

int main()
{
   int n,q;
    cin>>n>>q;
    int a[n]={0};

   for(int i=0;i<q;i++)
    {
        calculate(a);
    }

    cout<<p.top();

    return 0;
}
