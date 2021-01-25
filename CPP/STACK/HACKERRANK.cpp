#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the twoStacks function below.
 */
int twoStacks(int x, vector<int> a, vector<int> b) {

    stack<int> s1,s2;

    for(int i=(a.size())-1;i>=0;i--)
    {
        s1.push(a[i]);
    }

    for(int i=(b.size())-1;i>=0;i--)
    {
        s2.push(b[i]);
    }

    int total=0,count=0;

    while(total<=x)
    {
        if(s1.empty())
        {
            total=total+s2.top();
                if(total<=x)
                {
                    count=count+1;
                    s2.pop();
                }
                else
                  break;
        }
        else if(s2.empty())
        {
            total=total+s1.top();
                if(total<=x)
                {
                    count=count+1;
                    s1.pop();
                }
                else
                  break;
        }
        else
        {
         if(s1.top()!=s2.top())
        {
            if(s1.top()>s2.top())
            {
                total=total+s2.top();
                if(total<=x)
                {
                    count=count+1;
                    s2.pop();
                }
                else
                  break;

            }
            else
            {
                total=total+s1.top();
                if(total<=x)
                {
                    count=count+1;
                    s1.pop();
                }
                else
                  break;
            }
        }
        else
        {
            total=total+s1.top();
                if(total<=x)
                {
                    count=count+1;
                    s1.pop();
                }
                else
                  break;
        }
        }

    }

       return count;

}

int main()
{
    int n;
    cin>>n;
    vector<int> r;

    for(int i=0;i<n;i++)
    {
        vector<int> v1;
        vector<int> v2;
        int a,b,x;
        cin>>a>>b>>x;

        for(int p=0;p<a;p++)
        {
            int value;
            cin>>value;
            v1.push_back(value);
        }

        for(int q=0;q<b;q++)
        {
            int value;
            cin>>value;
            v2.push_back(value);
        }

        r.push_back(twoStacks(x,v1,v2));

    }

    int l=r.size();

    for(int i=0;i<l;i++)
    {
        cout<<r[i]<<endl;
    }
    return 0;
}

