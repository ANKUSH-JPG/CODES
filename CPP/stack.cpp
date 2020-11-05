#include<iostream>

using namespace std;

void push(int &top,int a[],int s)
{

   if(top==s-1)
   {
       cout<<"STACK OVERFLOW"<<endl;
   }
   else
   {
      int no;
      cout<<"ENTER NO:";
      cin>>no;
      top=top+1;
      a[top]=no;
   }
}

void pop(int &top,int a[],int s)
{
    if(top==-1)
        cout<<"STACK UNDERFLOW"<<endl;
    else
    {
        a[top]=0;
        top=top-1;
    }
}

int main()
{
    int s=0;
    int top=-1;
    cout<<"ENTER STACK SIZE:";
    cin>>s;

    int a[s];

    while(1)
    {
        int choice=0;
        cout<<"CHOOSE OPERATION: 1.PUSH  2.POP  3.PEEK  4.STACK TOP  5.IS EMPTY  6.IS FULL  7.EXIT"<<endl;
        cin>>choice;

        if(choice==1)
        {
             push(top,a,s);
        }
        else if(choice==2)
        {
            pop(top,a,s);
        }
        else
        {
            break;
        }
    }

    return 0;
}
