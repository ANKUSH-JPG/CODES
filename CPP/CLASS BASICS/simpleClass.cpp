#include<iostream>
#include<iostream>
#include<vector>
using namespace std;

class graph
{

private:

    int n;

    vector<vector< int > > v;

public:

    graph();
    void insert_into_graph(int x,int y);
    void show_graph();

};

graph::graph()
{
        cout<<"ENTER THE GRAPH SIZE: ";
        cin>>n;

        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(0);
            }

            v.push_back(temp);
        }
}

void graph::insert_into_graph(int x,int y)
{
    v[x][y]=1;
}

void graph::show_graph()
{
    for(int i=0;i<this->n;i++)
    {
        for(int j=0;j<this->n;j++)
           cout<<v[i][j]<<" ";

        cout<<endl;
    }
}

int main()
{
    graph *o1=new graph();
    o1->insert_into_graph(0,1);
    o1->insert_into_graph(0,2);
    o1->insert_into_graph(1,2);
    o1->insert_into_graph(2,0);
    o1->insert_into_graph(2,3);
    o1->insert_into_graph(3,3);

    o1->show_graph();

    return 0;
}
