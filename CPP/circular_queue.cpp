#include<iostream>

using namespace std;


struct q
{
    int s;
    int f=0;
    int r=0;
    int *a;
};

void insert_q(int a[],int &r,int &s,int &f)
{
    if(r==s-1 && (r+1)%s==f)
        cout<<"OVERFLOW"<<endl;
    else
    {
        int n;
        cout<<"ENTER NO:";
        cin>>n;

        r=(r+1)%s;
        a[r]=n;

    }

}

int delete_q(int a[],int &r,int &f,int &s)
{
    if(f==r)
      return 0;
    else
    {
      f=(f+1)%s;
      int result=a[f];
      a[f]=0;

      return result;
    }

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
        cout<<"1. INSERT  2. DELETE  3. DISPLAY  4. QUIT"<<endl;
        cin>>choice;

        if(choice==1)
        {
             insert_q(q1.a,q1.r,q1.s,q1.f);
        }
        else if(choice==2)
        {
             int result=delete_q(q1.a,q1.r,q1.f,q1.s);

             if(result==0)
                cout<<"EMPTY"<<endl;
             else
                cout<<"DELETED NUMBER:"<<result<<endl;
        }
        else if(choice==3)
        {

        }
        else
        {
            break;
        }
    }


    return 0;
}

