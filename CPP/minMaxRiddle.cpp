#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> result;

void find_output(int a[],int n)
{
    int window=1;
    while(window<=n)
    {
        priority_queue<int> maximum;
        int loop=n-window;
        for(int i=0;i<=loop;i++)
        {
           priority_queue<int,vector<int>,greater<int> > minimum;
           for(int j=0;j<window;j++)
           {
               minimum.push(a[i+j]);
           }
           maximum.push(minimum.top());
        }
        cout<<maximum.top()<<endl;

        window=window+1;
    }


}

int main()
{

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
       cin>>a[i];
    }

    find_output(a,n);
    return 0;
}
