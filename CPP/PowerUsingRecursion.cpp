#include<iostream>

using namespace std;


int power(int m,int n)
{
    if(n==1)
        return m;
    else
        return (m*power(m,n-1));
}
int main()
{

    int m,n;
    cin>>m>>n;

    int result=power(m,n);

    cout<<result;
    return 0;
}
