#include<iostream>
#include<queue>
using namespace std;

struct asset
{
  int *node;
  queue<int> q;
  int **graph;
}a;


void BFS(int s)
{
   while(!a.q.empty())
   {
       int element=a.q.front();
       a.q.pop();

       if(a.node[element]==1)
        continue;
       else
       {
         cout<<element<<" ";
         a.node[element]=1;

         for(int i=0;i<s;i++)
         {
             if(a.graph[element][i]==1)
             {
                 if(a.node[i]!=1)
                    a.q.push(i);
             }
         }
       }
    }
}

int main()
{

    int n,start_node;
    cout<<"ENTER THE NUMBER OF NODES:"<<endl;

    cin>>n;
    a.graph=new int*[n+1];
    a.node=new int[n+1];

    for(int i=1;i<n+1;i++)
    {
        a.node[i]=0;
        a.graph[i]=new int[n+1];
        for(int j=1;j<n+1;j++)
        {
            cin>>a.graph[i][j];
        }
    }

    cout<<"START NODE:";
    cin>>start_node;

    a.q.push(start_node);

    BFS(n+1);
    return 0;
}
