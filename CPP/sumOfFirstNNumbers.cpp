#include<iostream>
using namespace std;

int sum(int n)
{
    static int result=0;

    if(n==1)
        return 1;
    else
    {
        result=n+sum(n-1);

        return result;
    }
}

int main()
{

    int n;
    cin>>n;

    int result=sum(n);

    cout<<result;


    return 0;
}
