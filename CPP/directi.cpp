#include<iostream>
#include<vector>
using namespace std;


void enter_element(int a[],int n,int s_a[])
{
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s_a[i]=a[i];
    }
}

void sort_array(int n,int s_a[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s_a[i]<s_a[j])
            {
                int temp=s_a[i];
                s_a[i]=s_a[j];
                s_a[j]=temp;
            }
        }
    }
}

vector<int> max_value(int a[],int s_a[],int n)
{
    vector<int> max_a;
    for(int i=n-1;i>1;i--)
    {
        if(a[i]==s_a[n-1] || a[i]==s_a[n-2])
            continue;
        else
        {

            int x=0;
            for(x;x<n;x++)
            {
                if(a[i]==s_a[x])
                    break;
            }x=x+1;

            for(int j=i-1;j>0;j--)
            {
                int y;
                for(y=x;y<n;y++)
                {
                    if(a[j]==s_a[y])
                        break;
                }y=y+1;

                for(int k=j-1;k>=0;k--)
                {
                    int check=0;
                    for(int p=y;p<n;p++)
                    {
                        if(a[k]==s_a[p])
                            max_a.push_back(a[i]+a[j]+a[k]);
                    }
                }
            }
        }


        return max_a;
    }



}
int main()
{

    int n;
    cin>>n;

    int a[n];
    int s_a[n];



    enter_element(a,n,s_a);
    sort_array(n,s_a);

    vector<int> max_a=max_value(a,s_a,n);

    int length=max_a.size();

    for(int i=0;i<length;i++)
    {
        cout<<max_a[i]<<" ";
    }

    return 0;
}
