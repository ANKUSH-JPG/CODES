#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<iterator>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<set <int,greater<int> > > v;
    vector<int> result;
    for(int i=0;i<n;i=i+1)
    {
        set<int,greater<int> > temp;
        temp.insert(i+1);
        v.push_back(temp);
    }

    for(int i=0;i<q;i++)
    {
        char c;
        cin>>c;

        if(c=='M')
        {
            int a,b;
            cin>>a>>b;

            int l=v.size();
            int x=-1,y=-1;
            for(int j=0;j<l;j++)
            {
                if(v[j].find(-1)==v[j].end())
                {
                     if(v[j].find(a)==v[j].end())
                     {}
                     else
                     {x=j;}

                     if(v[j].find(b)==v[j].end())
                     {}
                     else
                     {y=j;}
                }

                if(x!=-1 && y!=-1)
                {
                    set<int,greater<int> >::iterator itr;
                    set<int,greater<int> > temp;
                    for(itr=v[x].begin();itr!=v[x].end();itr++)
                    {
                        temp.insert(*itr);
                    }

                    for(itr=v[y].begin();itr!=v[y].end();itr++)
                    {
                        temp.insert(*itr);
                    }

                    set<int,greater<int> > s1,s2;
                    s1=v[x];
                    v[x]=v[l-1];
                    v[l-1]=s1;

                    s2=v[y];
                    v[y]=v[l-2];
                    v[l-2]=s2;

                    v.resize(l-2);

                    v.push_back(temp);
                    cout<<"*"<<v.size()<<"*"<<endl;
                    break;
                }

            }
        }
        else if(c=='Q')
        {
          int value;
          cin>>value;

          int length=v.size();
          for(int m=0;m<length;m++)
          {
              if(v[m].find(-1)==v[m].end())
              {
                  if(v[m].find(value)==v[m].end())
                  {}
                  else
                  {
                      result.push_back(v[m].size());
                      break;
                  }
              }
          }

        }

    }

    int length=result.size();
    for(int i=0;i<length;i++)
    {
        cout<<result[i]<<endl;
    }


    return 0;
}
