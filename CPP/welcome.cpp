#include<iostream>
#include<string>
using namespace std;

int main()
{

    string s="WELCOME---";
    int n=s.size();

    int check=1;
    while(check==1)
    {
        char temp=s[0];
        for(int i=1;i<n;i++)
        {
            s[i-1]=s[i];
        }
        s[n-1]=temp;

        cout<<s<<endl;
        cin>>check;
    }

    return 0;
}
