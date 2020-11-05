#include<iostream>

using namespace std;
void Max_Heap_Sort(int a[],int size_of_a);
void swap_function(int a[],int mid,int x);
void resolve(int a[],int position,int size_of_a);


void Max_Heap_Sort(int a[],int size_of_a)
{

    if(size_of_a<1)
    {

    }
    else{
        int mid=size_of_a/2;
        int next=(mid*2);

        if(size_of_a==next)
        {

            if(a[mid-1]<a[next-1])
            {
                swap_function(a,mid-1,next-1);

            }
             size_of_a=size_of_a-1;
             Max_Heap_Sort(a,size_of_a);
        }
        else{

            if(a[size_of_a-1]>a[next-1])
            {
                if(a[size_of_a-1]>a[mid-1])
                {
                    swap_function(a,mid-1,size_of_a-1);
                    resolve(a,size_of_a,10);
                }

                size_of_a=size_of_a-2;
                Max_Heap_Sort(a,size_of_a);
            }
            else if(a[size_of_a-1]<a[next-1])
            {
                if(a[next-1]>a[mid-1])
                {
                    swap_function(a,mid-1,next-1);
                    resolve(a,next,10);
                }

                size_of_a=size_of_a-2;
                Max_Heap_Sort(a,size_of_a);
            }
        }
    }
}

void swap_function(int a[],int mid,int x)
{

    int temp=a[mid];
    if(temp!=0)
    {
    a[mid]=a[x];
    a[x]=temp;
    }

}

void resolve(int a[],int position,int size_of_a)
{
    int left=position*2;
    int right=left+1;

    cout<<left<<" "<<right<<endl;

    if(left<=size_of_a && right<=size_of_a)
    {
    cout<<"s"<<endl;
        if(a[left-1]>a[right-1])
        {
            if(a[position-1]<a[left-1])
            {
                swap_function(a,position-1,left-1);
                resolve(a,left,size_of_a);
            }
        }
        if(a[left-1]<a[right-1])
        {
            if(a[position-1]<a[right-1])
            {
                swap_function(a,position-1,right-1);
                resolve(a,right,size_of_a);
            }
        }

    }
    else if(left<=size_of_a)
    {
        cout<<"*"<<endl;
        if(a[position-1]<a[left-1])
            {
                swap_function(a,position-1,left-1);
            }
    }
}

int main()
{
    int a[10]={4, 10, 3, 5, 1,89,100,2,6,9};

    int size_of_a=sizeof(a)/sizeof(int);

    // CREATING MAX HEAP SORT
    Max_Heap_Sort(a,size_of_a);


    for(int i=0;i<size_of_a;i++)
    {

        cout<<a[i]<<" ";
    }
    return 0;
}
