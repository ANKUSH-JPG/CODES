#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<char> reverse_string(string a,int n);


struct string_array
{
    string a;
    string b;
    int x;
    int y;
};

vector<char> reverse_string(string a,int n)
{
    vector<char> r_s;
    for(int i=n-1;i>=0;i--)
    {
        r_s.push_back(a[i]);
    }

    return r_s;
}

int check_pallindrom(string a,vector<char> r_s,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]!=r_s[i])
            return 0;
    }
    return 1;
}
int main()
{
    struct string_array *head=new string_array;

    cin>>head->a>>head->b;
    head->x=(head->a).size();
    head->y=(head->b).size();

    vector<char> r_s=reverse_string(head->a,head->x);
    int n=r_s.size();
    cout<<endl<<"REVERSE STRING :";
    for(int i=0;i<n;i++)
    {
        cout<<r_s[i];
    }cout<<endl<<endl;

    int result=check_pallindrom(head->a,r_s,head->x);
    if(result==1)
        cout<<"PALLINDROM";
    else
        cout<<"NOT PALLINDROM";

    return 0;
}
