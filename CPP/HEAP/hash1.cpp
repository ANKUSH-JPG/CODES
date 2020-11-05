#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int check(int a[],int s_a,int b[],int s_b)
{
    set<int> s;
    int check=0;

    for(int i=0;i<s_a;i++)
    {
        s.insert(a[i]);
    }

    for(int i=0;i<s_b;i++)
    {
        if(s.find(b[s_b])==s.begin())
            check=1;
        else
        {
            check=0;
            break;
        }
    }

    return check;

    }

int main()
{
    int a[]={16,12,25,39,6,122,5,68,75};
    int b[]={39,16,75};

    int s_a=sizeof(a)/sizeof(a[0]);
    int s_b=sizeof(b)/sizeof(b[0]);

    int result=check(a,s_a,b,s_b);

    if(result==1)
    {
        cout<<"B IS SUBSET OF A";
    }
    else
    {
        cout<<"B IS NOT A SUBSET OF A";
    }

    return 0;
}
