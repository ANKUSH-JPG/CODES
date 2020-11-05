#include<iostream>
using namespace std;

void MergeSort(int a[],int size_of_a,int l,int h);
void TwoWayMerge(int c[],int a[],int b[],int size_c,int size_a,int size_b,int i,int j,int k);

void MergeSort(int a[],int size_of_a,int l,int h)
{
    int mid=(l+h)/2;
    cout<<mid<<endl;
    if(l<h)
    {

        int l_array[mid+1];
        int r_array[size_of_a-(mid+1)];

        for(int i=0;i<=mid;i++)
        {
            l_array[i]=a[i];
        }
        for(int i=mid+1;i<size_of_a;i++)
        {
            r_array[i]=a[i];
        }


        MergeSort(l_array,mid+1,l,mid);

        MergeSort(r_array,size_of_a-(mid+1),l,size_of_a-(mid+2));

        int i=0,j=0,k=0;
        TwoWayMerge(a,l_array,r_array,size_of_a,mid+1,size_of_a-(mid+1),i,j,k);

    }
    else{cout<<"*"<<endl;


    }

}

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

    int a[7]={38,27,43,3,9,82,10};
    int size_of_a=sizeof(a)/sizeof(a[0]);
    int l=0;
    int h=size_of_a-1;
    MergeSort(a,size_of_a,l,h);


    for(int i=0;i<size_of_a;i++)
    {

        cout<<a[i]<<" ";

    }

    return 0;
}
