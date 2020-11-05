#include<iostream>

using namespace std;
void TwoWayMerge(int c[],int a[],int b[],int size_c,int size_a,int size_b,int i,int j,int k);

void TwoWayMerge(int c[],int a[],int b[],int size_c,int size_a,int size_b,int i,int j,int k)
{
   if(i==(size_a) && j<size_b)
   {

       for(int x=j;x<size_b;x++)
       {
           c[k]=b[x];
           k=k+1;
       }
   }
   else if(i<size_a && j==(size_b))
   {

       for(int x=i;x<size_a;x++)
       {
           c[k]=b[x];
           k=k+1;
       }
   }
   else if(i<size_a && j<size_b)
   {
       if(a[i]<b[j])
       {

           c[k]=a[i];
           i=i+1;
           k=k+1;

        TwoWayMerge(c,a,b,size_c,size_a,size_b,i,j,k);
       }
       else if(a[i]>b[j])
       {

           c[k]=b[j];
           j=j+1;
           k=k+1;

        TwoWayMerge(c,a,b,size_c,size_a,size_b,i,j,k);
       }


   }


}
int main()

{

    int a[5]={2,4,7,8,9};
    int size_a=sizeof(a)/sizeof(a[0]);
    int b[3]={1,3,10};
    int size_b=sizeof(b)/sizeof(b[0]);
    int c[8];
    int size_c=sizeof(c)/sizeof(c[0]);

    int i=0,j=0,k=0;

    TwoWayMerge(c,a,b,size_c,size_a,size_b,i,j,k);


    for(int i=0;i<size_c;i++)
    {
        cout<<c[i]<<" ";
    }

    return 0;
}
