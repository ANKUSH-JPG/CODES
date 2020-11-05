#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int vector_x,query_x;
    cin>>vector_x>>query_x;

    vector< vector<int> > problem(vector_x);
    vector< vector<int> > query(query_x);

    for(int i=0;i<vector_x;i++)
    {
        int length;
        cin>>length;
        problem[i]=vector<int>(length);

        for(int j=0;j<length;j++)
        {
            int value;
            cin>>value;

            problem[i][j]=value;
        }

    }

    for(int i=0;i<query_x;i++)
    {
        query[i]=vector<int>(2);
        int x_value;
        cin>>x_value;
        query[i][0]=x_value;

        int key;
        cin>>key;

        query[i][1]=key;
    }


    // FOR THE OUTPUT PURPOSE:

    for(int i=0;i<query_x;i++)
    {
        int x_value=query[i][0];
        int key=query[i][1];

        cout<<problem[x_value][key]<<endl;
    }

    return 0;
}
