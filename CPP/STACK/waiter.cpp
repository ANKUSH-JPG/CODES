#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int find_prime();

stack<int> A;
vector<int> result;
int last_prime=1;

void calculate_result(int q)
{
    for(int i=0;i<q;i++)
    {
        //CREATING PRIME NO
        int p=find_prime();
        stack<int> B;
        stack<int> temp;
        while(!A.empty())
        {
            int e=A.top();
            A.pop();

            if(e%p==0)
            {
                B.push(e);
            }
            else
            {
                temp.push(e);
            }
        }
        A=temp;

        while(!B.empty())
        {
            result.push_back(B.top());
            B.pop();
        }
    }
}

int find_prime()
{
    while(1)
    {
        last_prime=last_prime+1;
        int i=2;
        int check=0;
        if(last_prime>i)
        {
            while(last_prime>i)
            {
            if(last_prime%i==0)
            {
                check=1;
                break;
            }
            i=i+1;
            }
            if(check==0)
                break;
        }
        else
            break;
    }


    return last_prime;
}
int main()
{
    int n,q;
    cin>>n;

    cin>>q;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;

        A.push(value);
    }

    calculate_result(q);

    int length=result.size();

    for(int i=0;i<length;i++)
    {
        cout<<result[i]<<endl;
    }

    while(!A.empty())
    {
        cout<<A.top()<<endl;
        A.pop();
    }
    return 0;
}
