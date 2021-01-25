#include<iostream>
#include<string>

using namespace std;

void superReducedString(string s)
{
    string str=s;
    int length=str.size();

    int check=0;
    for(int i=0;i<length-1;i++)
    {
        if(str[i]==str[i+1])
        {
            str.erase(str.begin() + i);

            str.erase(str.begin() + i);
            i=-1;
            length=str.size();
            cout<<length<<endl;
            if(length==0)
            {
                check=1;
                break;
            }
        }
    }

    if(check==1)
       cout<<"Empty String";
    else
      cout<<str;

}

int main()
{
    string s;
    cin>>s;

    superReducedString(s);

    return 0;
}
