#include<iostream>
#include<set>
#include<vector>
#include<iterator>
using namespace std;

int main()
{
    set<int,greater<int> > s;

    s.insert(1);
    s.insert(2);
    s.insert(0);
    s.insert(1);

    set<int, greater<int> >::iterator itr;
    for(itr=s.begin();itr!=s.end();++itr)
    {
        cout<<*itr<<endl;
    }

    if(s.find(3)==s.end())
        cout<<"NOT FOUND";
    else
        cout<<"FOUND";

    cout<<"*****************************************"<<endl;

    vector<set<int,greater<int> > > v;


}
