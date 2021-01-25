#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

priority_queue<int> result;

int max_value(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        priority_queue<int,vector<int>,greater<int> > p_q;
        p_q.push(A[i]);
        for(int j=i+1;j<n;j++)
        {
            priority_queue<int,vector<int>,greater<int> > temp;
            p_q.push(A[j]);
            temp=p_q;

            int m1=temp.top();temp.pop();
            int m2=temp.top();temp.pop();

            int g=((m1&m2)^(m1|m2))&(m1^m2);
            result.push(g);


        }
    }


    return result.top();
}

int main()
{
    int n;
    cin>>n;

    int A[n];
    priority_queue<int> c;

    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        A[i]=value;

        c.push(value);
    }

    int m=c.top();
    int r=max_value(A,n);

    cout<<r;


    return 0;
}
