#include <cmath>
#include<bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<char> result;
stack<string> s;
string str;

void calculate_str()
{
    int t;
    cin>>t;

    if(t==1)
    {
        int length=str.size();
        if(length==0)
        {
            s.push(str);
            cin>>str;
        }
        else
        {
            s.push(str);
            string temp;
            cin>>temp;
            str=str+temp;
        }
    }
    else if(t==2)
    {
          s.push(str);

          int p;
          cin>>p;

          int length=str.size();
          int new_length=length-p;
          str.resize(new_length);

    }
    else if(t==3)
    {
        int position;
        cin>>position;
        result.push_back(str[position-1]);
    }
    else
    {

        str=s.top();
        s.pop();
    }
}
int main() {

    int n;
    cin>>n;



    for(int i=0;i<n;i++)
    {
        calculate_str();
    }

    int length=result.size();
    for(int i=0;i<length;i++)
    {
        cout<<result[i]<<endl;
    }

    return 0;
}

