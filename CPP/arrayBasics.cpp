#include<iostream>

using namespace std;

int main()
{
   /* int *p[3];

    int s=sizeof(p)/sizeof(int);

    for(int i=0;i<s;i++)
    {
        p[i]=new int [3];
    }

     for(int i=0;i<s;i++)
    {
       for(int j=0;j<s;j++)
       {
           int no;
           cin>>no;

           p[i][j]=no;
       }
    }

    for(int i=0;i<s;i++)
    {
       for(int j=0;j<s;j++)
       {
           cout<<p[i][j]<<" ";
       }
       cout<<endl;
    }
*/

     int **a;

     a=new int *[3];

     int s=sizeof(a)/sizeof(int);
     //cout<<s;
     for(int i=0;i<3;i++)
    {
        a[i]=new int [3];
    }

     for(int i=0;i<3;i++)
    {
       for(int j=0;j<3;j++)
       {
           int no;
           cin>>no;

           a[i][j]=no;
       }
    }

    for(int i=0;i<3;i++)
    {
       for(int j=0;j<3;j++)
       {
           cout<<a[i][j]<<" ";
       }
       cout<<endl;
    }


    return 0;
}
