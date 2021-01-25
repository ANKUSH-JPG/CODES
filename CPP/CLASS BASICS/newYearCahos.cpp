#include<iostream>
#include<vector>
using namespace std;

void newYearChaos(vector<int> final_s,int n)
{
    vector<int> original_s;
    int original[n+1];
    int present[n+1];

    int count=0;
    int check=0;
    for(int i=0;i<n;i++)
    {
        original_s.push_back(i+1);
        original[original_s[i]]=i;
        present[final_s[i]]=i;
    }

    for(int i=0;i<n;i++)
    {
        cout<<original_s[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n+1;i++)
    {
        cout<<original[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n+1;i++)
    {
        cout<<present[i]<<" ";
    }
    cout<<endl;

    for(int i=n;i>=2;i--)
    {
        if(original[i]==present[i])
           continue;
        else
        {
           if(original[i]-present[i]>2)
           {check=1;break;}
           else
           {

               count=count+(original[i]-present[i]);
               cout<<"*"<<original[i]<<" "<<present[i]<<" "<<count<<"*"<<endl;

               int x=i;
               for(int j=original[i];j>present[i];j--)
               {
                   int y=original[x];
                   int k=original[x-1];
                   swap(original_s[y],original_s[k]);
                   x=x-1;
               }

               for(int j=original[i];j>=present[i];j--)
               {
                   original[original_s[j]]=j;
               }
           }
        }
    }

    if(check==1)
      cout<<"Too chaotic"<<endl;
    else
      cout<<count<<endl;
}

int main()
{
    int q;
    cin>>q;

    for(int i=0;i<q;i++)
    {
        vector<int> v;
        int n;
        cin>>n;

        for(int j=0;j<n;j++)
        {
            int no;
            cin>>no;

            v.push_back(no);
        }

        newYearChaos(v,n);
    }

    return 0;
}
