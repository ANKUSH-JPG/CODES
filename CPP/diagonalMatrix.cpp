#include<iostream>

using namespace std;

struct diagonal
{
    int n;
    int *a;
};

void set_value(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int value;
            cin>>value;

            if(i==j)
                a[i]=value;
        }
    }
}

void display(int *a,int n)
{
    cout<<"*****************************************"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            if(i==j)
                cout<<a[i]<<" ";
            else
                cout<<"0"<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    struct diagonal *head=new diagonal;
    cout<<"SIZE :";
    cin>>head->n;
    head->a=new int[head->n];

    set_value(head->a,head->n);

    display(head->a,head->n);

    return 0;
}
