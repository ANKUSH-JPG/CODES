#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int calculate_rectangle(int building[],int n)
{
    priority_queue<int,vector<int>,greater<int> > q;
    priority_queue<int> temp;
    int result=0;

    for(int i=0;i<n;i++)
    {
        q.push(building[i]);
        temp.push(building[i]);
    }

    int check[(temp.top())+1]={0};
    while(!q.empty())
    {
        int h=q.top();
        q.pop();

        if(check[h]==0)
        {
            check[h]=1;
            int c=0,i=0;
            priority_queue<int> v;
            while(i<n)
            {
                for(i;i<n;i++)
                {
                    if(building[i]>=h)
                    {
                        c=c+1;
                    }
                    else
                    {
                        v.push(c);
                        c=0;
                    }
                }
                 v.push(c);
                 if((v.top())*h>result)
                    result=(v.top())*h;

            }

        }
    }

    return result;
}

int main()
{
    int n;
    cin>>n;

    int building[n];

    for(int i=0;i<n;i++)
    {
        cin>>building[i];
    }

    int result=calculate_rectangle(building,n);
    cout<<result;

    return 0;
}
