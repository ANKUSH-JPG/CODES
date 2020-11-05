#include<iostream>

using namespace std;

int main()
{
    int x=43,y=61;
    int no,choice;
    cout<<"ENTER A NO : ";
    cin>>no;

    cout<<"1. ENCRYPT  2. DECRYPT"<<endl;
    cin>>choice;

    int n=x*y;
    int totient=(x-1)*(y-1);

    return 0;
}
