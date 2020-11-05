#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> a;

    int n=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
    int element;
    cin>>element;
     a.push_back(element);
    }

    return 0;
}
