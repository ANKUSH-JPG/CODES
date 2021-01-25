#include <bits/stdc++.h>
#include<cmath>
#include<queue>
using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {

       int result=0;

       int m=c.size();

       int a[n];

       priority_queue<int,vector<int>,greater<int> > q;
       for(int i=0;i<n;i++)
       {
           a[i]=100008;

       }

       for(int i=0;i<m;i++)
       {
           q.push(c[i]);
       }

       for(int i=0;i<m;i++)
       {
           c[i]=q.top();
           q.pop();


       }



       for(int i=0;i<n;i++)
       {

           for(int j=0;j<m;j++)
           {
               if((abs(i-c[j]))>=a[i])
                  break;
               else
               {
                  a[i]=abs(i-c[j]);

               }
           }

       }

    for(int i=0;i<n;i++)
    {
        if(a[i]>result)
          result=a[i];
    }

   return result;
}

int main()
{
    int n,q;
    cin>>n>>q;

    vector<int> v;
    for(int i=0;i<q;i++)
    {
        int no;
        cin>>no;

        v.push_back(no);
    }

    int result=flatlandSpaceStations(n,v);

    cout<<result;

    return 0;
}

