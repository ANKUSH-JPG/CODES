#include<iostream>
#include<vector>
using namespace std;
void init(int n,int candy[],int unit[],int p[]);
void swap_p(int p[],int i,int j);
void sort_array(int n,int candy[],int unit[],int p[]);
vector<int> days_count(int n,int k,int candy[],int unit[],int p[]);

void init(int n,int candy[],int unit[],int p[])
{
    for(int i=0;i<n;i++)
    {
        int u;
        candy[i]=i+1;
        cin>>u;
        unit[i]=u;
    }

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        p[i]=a;
    }

}

void swap_p(int p[],int i,int j)
{
    int temp=p[i];
    p[i]=p[j];
    p[j]=temp;
}

void sort_array(int n,int candy[],int unit[],int p[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i]<p[j])
            {
                 swap_p(p,i,j);
                 swap_p(candy,i,j);
                 swap_p(unit,i,j);
            }

        }
    }
}

vector<int> days_count(int n,int k,int candy[],int unit[],int p[])
{
    vector<int> days;

    for(int i=0;i<n;i++)
    {
        while(unit[i]>0)
        {
            days.push_back(candy[i]);
            unit[i]=unit[i]-k;
        }
    }

    return days;

}

void solve_query(vector<int> days,int q)
{
    for(int i=0;i<q;i++)
    {
        int x,y;
        cout<<"ENTER X & Y:";
        cin>>x>>y;

        if(days[y-1]==x)
            cout<<"YES"<<endl<<endl;
        else
            cout<<"NO"<<endl<<endl;

    }
}

int main()
{

    int n,k,queries;
    cin>>n>>k;

    int candy[n];
    int unit[n];
    int p[n];

    init(n,candy,unit,p);

    sort_array(n,candy,unit,p);

    vector<int> days=days_count(n,k,candy,unit,p);
    int length=days.size();

    cout<<"ENTER NO OF QUERIES:";
    cin>>queries;

    solve_query(days,queries);
    return 0;
}
