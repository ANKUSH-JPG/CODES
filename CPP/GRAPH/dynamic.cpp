#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > v;

int DynamicArray(int &lastanswer,int option,int n,int l[])
{
    int x,y;
    cin>>x>>y;
    if(option==1)
    {
        v[(x^lastanswer)%n].push_back(y);
        l[(x^lastanswer)%n]=l[(x^lastanswer)%n]+1;
        return lastanswer;
    }
    else
    {

        int length=l[(x^lastanswer)%n];
        lastanswer=v[(x^lastanswer)%n][y%length];
        return lastanswer;
    }
}

int main()
{
    int n,q,lastanswer=0;
    cin>>n>>q;

    vector<int> result;
    int l[n]={0};
    for(int i=0;i<n;i++)
    {
        vector<int> a;

        v.push_back(a);
    }

    for(int i=0;i<q;i++)
    {
        int option;

        cin>>option;

        if(option==1)
        {
            int r=DynamicArray(lastanswer,option,n,l);
        }
        else
        {
            result.push_back(DynamicArray(lastanswer,option,n,l));

        }
    }

    int length=result.size();

    for(int i=0;i<length;i++)
        cout<<result[i]<<endl;


    return 0;
}
