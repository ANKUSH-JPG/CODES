#include<iostream>
#include<bits/stdc++.h>
using namespace std;

priority_queue<long int,vector<int>,greater<int> > p;

int main()
{
    int n;
    cin>>n;


    vector<int> result;

    for(int i=0;i<n;i++)
    {
        int operation;
        cin>>operation;
        if(operation==1)
        {
            long int value;
            cin>>value;

            p.push(value);
        }
        else if(operation==2)
        {
            long int value;
            cin>>value;

            priority_queue<long int,vector<int>,greater<int> > temp;
            cout<<p.empty();
            while(!p.empty())
            {cout<<"*"<<" ";
                if(p.top()!=value)
                {
                    temp.push(p.top());
                    p.pop();
                }
                else
                {
                    p.pop();
                }
            }
            cout<<temp.empty();
            while(!temp.empty())
            {
                p.push(temp.top());
                temp.pop();
            }
            cout<<p.empty();
        }
        else {
         //result.push_back(p.top());
         cout<<p.top()<<endl;
         p.pop();
        }
    }

    int length=result.size();

    for(int i=0;i<length;i++)
    {
        cout<<result[i]<<endl;
    }

    return 0;
}
