#include<iostream>

using namespace std;


class diagonal
{
private:
    int n;
    int *a;

public:
    diagonal(int s)
    {
        n=s;
        a=new int[n];
    }

    void set_value();
    void display();
};

void diagonal::set_value()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int no;
            cin>>no;
            if(i==j)
                a[i]=no;
        }
    }
}

void diagonal::display()
{
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
    cout<<"SIZE:";
    int s;
    cin>>s;
    diagonal *head=new diagonal(s);

    head->set_value();

    cout<<"**********************************"<<endl;

    head->display();

    return 0;
}
