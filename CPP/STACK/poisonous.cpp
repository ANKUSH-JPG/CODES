#include<iostream>
#include<vector>
using namespace std;

vector<int> V;
int days=0;

int die()
{
    int check=0;
    for(int i=1;i<V.size();i++)
    {
        if(V[i-1]<V[i])
            check=1;
    }

    if(check==0)
        return 0;
    else
    {
        vector<int> temp;
        temp.push_back(V[0]);
        for(int i=1;i<V.size();i++)
        {
            if(V[i-1]>=V[i])
                temp.push_back(V[i]);
        }

        V=temp;

        days=1+die();
        return days;
    }
}

int main()
{
    int n,value;;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>value;
        V.push_back(value);
    }

    days=die();

    cout<<days;

    return 0;
}
