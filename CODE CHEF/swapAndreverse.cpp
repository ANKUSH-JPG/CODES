#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

void find_out(int a[],int n)
{
    int greatest=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>greatest)
            greatest=a[i];
    }

    int ques[greatest+1],ans[greatest+1],b[n];

    int sub[greatest+1];
    for(int i=0;i<greatest+1;i++)
    {
        ques[i]=-1;
        ans[i]=-1;
    }
    priority_queue<int,vector<int>,greater<int> > p;
    for(int i=0;i<n;i++)
    {
        p.push(a[i]);
        ques[a[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        b[i]=p.top();
        p.pop();
        ans[b[i]]=i;
    }

    vector<int> s;stack<int> st;
    int check=0;
    for(int i=0;i<greatest+1;i++)
    {
        sub[i]=ans[i]-ques[i];
        if(sub[i]!=0)
        {
            s.push_back(i);
            if(sub[i]<0)
                st.push(-1*sub[i]);
            else
            {
                if(sub[i]==st.top())
                    st.pop();
                else
                    check=1;
            }

        }
    }

    int stack_one=0,reverse_one=0;
    if(s.size()==2)
        stack_one=1;
    else if(check==0)
        reverse_one=1;

    if(stack_one==1)
        cout<<"yes"<<endl<<"swap "<<ques[s[1]]+1<<" "<<ques[s[0]]+1;
    else if(reverse_one==1)
        cout<<"yes"<<endl<<"reverse "<<ques[s[s.size()-1]]+1<<" "<<ques[s[0]]+1;
    else
        cout<<"no";


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

    find_out(a,n);
    return 0;
}
