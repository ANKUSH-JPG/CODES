#include<iostream>
#include<vector>
using namespace std;


void find_out(vector<vector<int> > a,int r,int c,int n)
{
    int m=min(r,c)/2,r1=r+1,c1=c+1;

    vector<int> magnitude;
    for(int i=0;i<m;i++)
    {
        int count1=0;
        int j=i,k=i;
        r1=r1-1;
        c1=c1-1;
        //DOWN
        for(j=i+1;j<r1;j++)
            count1++;
        j=j-1;

        //RIGHT
        for(k=i+1;k<c1;k++)
            count1++;
        k=k-1;

        //TOP
        for(j=j-1;j>=i;j--)
            count1++;
        j=j+1;

        //LEFT
        for(k=k-1;k>=i;k--)
            count1++;
        k=k+1;

        magnitude.push_back(count1);

    }

    vector<vector<int> > a2=a;
    r1=r+1;
    c1=c+1;

    for(int i=0;i<m;i++)
    {

        int rem=n%magnitude[i];

        if(rem==0)
        {}
        else
        {
            int j=i,k=i;
            r1=r1-1;
            c1=c1-1;

            //DOWN
            for(j=j+1;j<r1;j++)
            {

                int position=j+rem;
                if(position>r1-1)
                {

                    position=position-(r1-1);
                    if(position>c1-1)
                    {
                        position=position-(c1-1);
                        if(position>r1-1)
                        {
                            position=position-(r1-1);
                            if(position>c1-1)
                            {}
                            else
                                a2[i][(c1-1)-position]=a[j][k];
                        }
                        else
                            a2[(r1-1)-position][c1-1]=a[j][k];
                    }
                    else
                    {
                        a2[r1-1][position+i]=a[j][k];
                        cout<<"*"<<r1-1<<" "<<position<<"* "<<a2[r1-1][position]<<" ";
                    }

                }
                else
                {
                    a2[position][i]=a[j][k];
                    cout<<"*"<<position<<" "<<i<<"* "<<a2[position][i]<<" ";
                }

            }j=j-1;


        }

    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a2[i][j]<<" ";
        }cout<<endl;
    }
}
int main()
{

    int r,c,n;
    cin>>r>>c>>n;

    vector<vector<int> > v;

    for(int i=0;i<r;i++)
    {
        vector<int> temp;
        for(int j=0;j<c;j++)
        {
            int no;
            cin>>no;

            temp.push_back(no);
        }
        v.push_back(temp);
    }

    find_out(v,r,c,n);

    return 0;
}
