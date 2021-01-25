#include<iostream>
#include<string>
using namespace std;

int calculate_strength(int n,string password)
{
    int more=0;
    int check[4]={1,1,1,1};
    if(n>=6)
    {
        for(int i=0;i<n;i++)
        {
            if(check[0]==1)
            {
                // NUMBER CHECK
                if((password[i]-'0')>=0 && (password[i]-'0')<=9 )
                {
                    check[0]=0;
                    continue;
                }
            }
            if(check[1]==1)
            {
                //LOWER_CHECK
                if(password[i]>=97 && password[i]<=122)
                {
                    check[1]=0;
                    continue;
                }
            }
            if(check[2]==1)
            {
                //UPPER CHECK
                if(password[i]>=65 && password[i]<=90)
                {
                    check[2]=0;
                    continue;
                }
            }
            if(check[3]==1)
            {
                //SPECIAL SYMBOL CHECK  !@#$%^&*()-+
                if(password[i]=='!' || password[i]=='@' || password[i]=='$' || password[i]=='%' || password[i]=='^' || password[i]=='&' || password[i]=='*' || password[i]=='(' || password[i]==')' || password[i]=='-' || password[i]=='+' || password[i]=='#' )
                {
                    check[3]=0;
                    continue;
                }
            }
        }

        for(int i=0;i<4;i++)
            more=more+check[i];
    }
    else
    {
        more=6-n;
    }

    return more;
}


int main()
{
    int n;
    string password;
    cin>>n>>password;

    int result=calculate_strength(n,password);

    cout<<result;

    return 0;
}
