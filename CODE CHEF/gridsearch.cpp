#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string s1="my name is ankush saini ankush saini";
    string s2="ankush";

    int found=s1.find(s2);
    while(found<=s1.size())
    {
         cout<<found<<" ";
         found=s1.find(s2,found+1);
    }
    cout<<"NOT FOUND";

    return 0;
}
