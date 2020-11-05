#include<iostream>

using namespace std;
void min_heap(int r,int a[]);
void swap_element(int x,int y,int a[]);

struct q
{
    int s;
    int f=0;
    int r=-1;
    int *a;
};
int current;

void enqueue(int a[],int &s,int &f,int &r)
{
    if(r==s-1)
        cout<<"OVERFLOW"<<endl;
    else
    {
        r=r+1;
        cout<<"ENTER ELEMENT:";
        cin>>a[r];
    }
}

void dequeue(int a[],int &s,int &f,int &r)
{
    if(f==r)
        cout<<"EMPTY"<<endl;
    else
    {
        current=r;
        min_heap(r,a);

        cout<<a[f]<<" ";
        swap_element(f,r,a);
        r=r-1;
    }
}

void min_heap(int r,int a[])
{
    if(current==-1)
    {

    }
    else
    {
        if(current*2+1<=r)
        {
        if(current*2+2<=r)
        {
            // LEFT+RIGHT
            if(a[current*2+2]>a[current*2+1])
            {
                if(a[current]>a[current*2+1])
                {
                   swap_element(current,current*2+1,a);
                   current=current-1;
                   min_heap(r,a);
                }
                else
                {
                    current=current-1;
                    min_heap(r,a);
                }
            }
            else
            {
                if(a[current]>a[current*2+2])
                {
                    swap_element(current,current*2+2,a);
                    current=current-1;
                    min_heap(r,a);
                }
                else
                {
                    current=current-1;
                    min_heap(r,a);
                }
            }
        }
        else
        {
            //LEFT

            if(a[current]>a[current*2+1])
            {
                swap_element(current,current*2+1,a);
                current=current-1;
                min_heap(r,a);
            }
            else
            {
                current=current-1;
                min_heap(r,a);
            }
        }
    }
    else
    {
        current=current-1;
        min_heap(r,a);
    }
  }
}

void swap_element(int x,int y,int a[])
{
    int temp=a[x];
    a[x]=a[y];
    a[y]=temp;
}

int main()
{
    struct q q1;
    cout<<"ENTER SIZE:";
    cin>>q1.s;

    q1.a=new int[q1.s];

    while(1)
    {
        int choice;
        cout<<"1. INSERT  2. DELETE  3. EXIT"<<endl;
        cin>>choice;

        if(choice==1)
        {
            enqueue(q1.a,q1.s,q1.f,q1.r);
        }
        else if(choice==2)
        {
            dequeue(q1.a,q1.s,q1.f,q1.r);
        }
        else
        {
            break;
        }
    }

    return 0;
}
