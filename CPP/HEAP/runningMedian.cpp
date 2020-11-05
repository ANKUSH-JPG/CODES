#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

double calculate(priority_queue<double> q)
{
    int s=q.size();
    int i=-1;
    double result1,result2;

    if(s%2)
    {
        int times=s/2;

        for(i;i<times-1;i++)
        {
            q.pop();
        }
        result2=q.top();

        return result2;
    }
    else
    {
        int times=(s/2)-1;

        for(i;i<times;i++)
        {
            result1=q.top();
            q.pop();
        }
        result2=q.top();

        return (result1+result2)/2;
    }

}

int main()
{
    int n;
    cin>>n;

    double a[n];
    priority_queue<double> q;
    vector<double> result;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        q.push(a[i]);

        double d=calculate(q);
        result.push_back(d);

    }

    int length=result.size();
    for(int i=0;i<length;i++)
    {
        printf("%0.1f \n",result[i]);
    }
    return 0;
}
