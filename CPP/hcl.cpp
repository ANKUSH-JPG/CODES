#include<iostream>

using namespace std;
void passingTime(int a[][2],int i,int result[]);

void passingTime(int a[][2],int i,int result[])
{
    int p=a[i][0];
    int q=a[i][1];


    if(p!=0 && q!=0)
    {
        if(p==q)
        {
            result[0]=result[0]+1;
        }
        else
        {
            if(p>q)
            {
               int c=p-q;
               a[i][0]=c;
               result[0]=result[0]+1;
               passingTime(a,i,result);
            }
            else
            {
                int c=q-p;
                a[i][1]=c;
                result[0]=result[0]+1;
               passingTime(a,i,result);
            }
        }
    }
    else if(p==0 || q==0)
    {

    }


}


int main()

{

    int n;
    cin>>n;

    int a[n][2];
    int b[2];
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        b[0]=a[i][0];b[1]=a[i][1];


    }

    for(int i=0;i<n;i++)
    {
       int result[1]={0};
        passingTime(a,i,result);

        cout<<result[0]<<endl;
    }



    return 0;
}
