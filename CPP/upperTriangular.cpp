#include<iostream>

using namespace std;

struct top
{
    int n;
    int *a;
};

void set_value(int *a,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int no;
            cin>>no;
            if(i<=j)
                a[j-i]=no;
            else
                a[n+i-j-1]=no;
        }
    }
}

void display(int *a,int n)
{
   /* for(int i=0;i<(2*n-1);i++)
    {
        cout<<a[i]<<" ";
    } */
    cout<<"****************************************"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=j)
                cout<<a[j-i]<<" ";
            else
                cout<<a[n+i-j-1]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
  top *head=new top;
  cout<<"SIZE:";
  cin>>head->n;

  head->a=new int[(2*head->n)-1];

  set_value(head->a,head->n);

  display(head->a,head->n);

    return 0;
}
