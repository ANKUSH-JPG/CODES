#include<iostream>
#include<vector>
using namespace std;

int main()
{

int no=0;
int size_def=6;
vector< vector<int> > new_vector(size_def);

// INSERTING THE ELEMENTS IN THE VECTOR........
for(int i=0;i<6;i++)
{
new_vector[i]=vector<int>(size_def);
for(int j=0;j<6;j++)
{
    cin>>no;
    new_vector.at(i).at(j)=no;
}
}

int biggest=0;

for(int i=0;i<size_def-2;i++)
{
    for(int j=0;j<size_def-2;j++)
    {
        int upper=new_vector[i][j]+new_vector[i][j+1]+new_vector[i][j+2];
        int middle=new_vector[i+1][j+1];
        int lower=new_vector[i+2][j]+new_vector[i+2][j+1]+new_vector[i+2][j+2];

        int result=upper+middle+lower;



        if(result>biggest)
        {
            biggest=result;
        }
        else
        {}
    }
}

cout<<biggest;
return 0;
}
