#include<iostream>
#include<vector>
using namespace std;

struct array_class
{
   int *a;
   int *b;
   int l_a;
   int l_b;
};

void insert_values(int l_a,int l_b,int *a,int *b)
{
    cout<<"INSERT VALUES IN A :";
    for(int i=0;i<l_a;i++)
    {
        cin>>a[i];
    }
    cout<<"INSERT VALUES IN B :";
    for(int i=0;i<l_b;i++)
    {
        cin>>b[i];
    }
}

void sort_array(int *a,int l,int h)
{
    int p=l;
    int i=l;
    int j=h;

    while(i<=j)
    {
        while(a[i]<=a[p])
            i=i+1;

        while(a[j]>a[p])
            j=j-1;

        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    if(l<h)
    {
    int temp=a[p];
    a[p]=a[j];
    a[j]=temp;

    sort_array(a,l,j);
    sort_array(a,j+1,h);
    }

}

vector<int> sum(int *a,int *b,int l_a,int l_b)
{
    vector<int> s;
    int i=0,j=0;
    while(i<l_a && j<l_b)
    {
        if(a[i]<b[j])
        {
            s.push_back(a[i]);
            i=i+1;
        }
        else if(a[i]>b[j])
        {
            s.push_back(b[j]);
            j=j+1;
        }
        else
        {
            s.push_back(a[i]);
            i=i+1;
            j=j+1;
        }
    }
    if(i<l_a)
    {
        for(i;i<l_a;i++)
        {
            s.push_back(a[i]);
        }
    }
    if(j<l_b)
    {
        for(j;j<l_b;j++)
        {
            s.push_back(b[j]);
        }
    }

    return s;
}

vector<int> difference(int *a,int *b,int l_a,int l_b)
{
    vector<int> d;
    int i=0,j=0;
    while(i<l_a && j<l_b)
    {
        if(a[i]<b[j])
        {
            i=i+1;
        }
        else if(a[i]>b[j])
        {
            j=j+1;
        }
        else
        {
            d.push_back(a[i]);
            i=i+1;
            j=j+1;
        }
    }

    return d;
}

int main()
{
    struct array_class a1;
    cin>>a1.l_a>>a1.l_b;

    a1.a=new int[a1.l_a];
    a1.b=new int[a1.l_b];

    insert_values(a1.l_a,a1.l_b,a1.a,a1.b);

    sort_array(a1.a,0,(a1.l_a)-1);
    sort_array(a1.b,0,(a1.l_b)-1);

//  PRINT DATA
   /*for(int i=0;i<a1.l_a;i++)
    {
        cout<<a1.a[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<a1.l_b;i++)
    {
        cout<<a1.b[i]<<" ";
    }*/

   vector<int> s=sum(a1.a,a1.b,a1.l_a,a1.l_b);

   vector<int> d=difference(a1.a,a1.b,a1.l_a,a1.l_b);

    int length=s.size();
    cout<<endl<<"SUM : ";
    for(int i=0;i<length;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;

    int d_l=d.size();
    cout<<endl<<"DIFFERENCE : ";
    for(int i=0;i<d_l;i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}
