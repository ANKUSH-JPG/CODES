#include<iostream>

using namespace std;

class lowerTriangular
{
    int n;
    int *a;

public:
    lowerTriangular(int s)
    {
        n=s;
        a=new int[n*(n+1)/2];
    }

    void set_value();
    void output();
};

void lowerTriangular::set_value()
{
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
               int no;
               cin>>no;

               if(i>=j)
                a[((i*(i-1))/2)+(j-1)]=no;
           }
       }
}

void lowerTriangular::output()
{
    cout<<"*************************************"<<endl;
     for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
              if(i>=j)
                cout<<a[((i*(i-1))/2)+(j-1)]<<" ";
              else
                cout<<"0"<<" ";

           }
           cout<<endl;
      }
}

int main()
{
    cout<<"SIZE:";
    int n;
    cin>>n;
    lowerTriangular *head=new lowerTriangular(n);

    head->set_value();

    head->output();


    return 0;
}
