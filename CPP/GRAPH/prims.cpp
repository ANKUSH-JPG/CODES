#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int minMax(int a[],int n,int value)
{
    priority_queue<int> final;

   for(int i=0;i<=n-value;i++)
   {
       priority_queue<int> p;

       if(value==1)
        final.push(a[i]);
       else
       {
            for(int j=i;j<i+value;j++)
            {
                p.push(a[j]);
            }
            final.push(p.top());
       }
    }
    int result;
    while(!final.empty())
    {
        result=final.top();
        final.pop();
    }

    return result;
}
int main()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    vector<int> result;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<q;i++)
    {
        int value;
        cin>>value;

        result.push_back(minMax(a,n,value));

    }

    int length=result.size();
    for(int i=0;i<length;i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
