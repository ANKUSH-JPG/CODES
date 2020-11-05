#include<iostream>

using namespace std;

float taylor(int x,int n)
{
    static float p=1;
    static float q=1;

    if(n==0)
        return 1;
    else
    {
        float previous=taylor(x,n-1);
        p=p*x;
        q=q*n;

        return (previous+(p/q));
    }

}
int main()
{
    int x,n;
    cin>>x>>n;

    float result=taylor(x,n);

    cout<<result;

    return 0;
}
