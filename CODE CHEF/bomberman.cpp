#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> bomberMan(int n, vector<string> grid,int r ,int c) {

    vector<string> result;

    vector<vector<int> > first;
    vector<vector<int> > total;
    vector<vector<int> > blasted;

    if(n%2==0)
    {
        for(int i=0;i<r;i++)
        {
            string s;
            for(int j=0;j<c;j++)
            {
                s.push_back('O');
            }
            result.push_back(s);
        }

        return result;
    }


    for(int i=0;i<r;i++)
    {
        vector<int> temp,temp1;
        string s;
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]=='O')
                 temp.push_back(j);

            temp1.push_back(0);
            s.push_back('.');
        }
        first.push_back(temp);
        total.push_back(temp1);
        result.push_back(s);
    }


    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            // EVEN : PLANT THE BOMB

        }
        else
        {
            //ODD : BLAST
            blasted=total;

            //MOVE THROUGH FIRST
            for(int x=0;x<r;x++)
            {
                int length=first[x].size();

                for(int y=0;y<length;y++)
                {

                    blasted[x][first[x][y]]=1;

                    //top
                    if(x-1<0)
                    {}
                    else
                      blasted[x-1][first[x][y]]=1;

                    //bottom
                    if(x+1>r-1)
                    {}
                    else
                      blasted[x+1][first[x][y]]=1;


                    //left
                    if(first[x][y]-1<0)
                    {}
                    else
                      blasted[x][first[x][y]-1]=1;

                    //right
                    if(first[x][y]+1>c-1)
                    {}
                    else
                      blasted[x][first[x][y]+1]=1;

                }

            }


            first.clear();
            for(int x=0;x<r;x++)
            {
                vector<int> temp;
                for(int y=0;y<c;y++)
                {
                    if(blasted[x][y]==1)
                    {}
                    else
                    {
                        temp.push_back(y);
                    }
                }
                first.push_back(temp);
            }

        }


    }

    if(n%2!=0)
    {
        for(int i=0;i<r;i++)
        {
           int length=first[i].size();
           for(int j=0;j<length;j++)
           {
               result[i][first[i][j]]='O';
           }
        }
    }

    return result;
}

int main()
{
    int r,c,n;
    cin>>r>>c>>n;

    vector<string> v(r);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            char c;
            cin>>c;
            v[i].push_back(c);
        }
    }


    vector<string> result=bomberMan(n,v,r,c);

    int length=result.size();
    for(int i=0;i<length;i++)
    {
        cout<<result[i]<<endl;
    }



    return 0;
}
