#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,q;
     cin>>n>>q;

     priority_queue<int> result;

     int a[n]={0};

     for(int i=0;i<q;i++)
     {
         int p,q,x;
         cin>>p>>q>>x;

         for(int j=p-1;j<=q-1;j++)
         {
             a[j]=a[j]+x;
             result.push(a[j]);
         }
     }

     cout<<result.top();

    return 0;
}
