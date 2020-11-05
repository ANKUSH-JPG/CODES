#include<iostream>
#include<string>
using namespace std;


void add_stack(int &top,char c,char s[])
{
    top=top+1;
    s[top]=c;
}

int pop(int &top,char c,char s[])
{
    if(s[top]=='[' && c==']')
    {
        s[top]='0';
        top=top-1;

        return 1;
    }
    else if(s[top]=='{' && c=='}')
    {
        s[top]='0';
        top=top-1;

        return 1;
    }
    else if(s[top]=='(' && c==')')
    {
        s[top]='0';
        top=top-1;

        return 1;
    }

    return 0;

}

int main()
{
    string str;
    cout<<"ENTER THE EXPRESSION:";
    cin>>str;

    int top=-1,i=0,result=1;
    int length=str.size();

    char s[length];

    for(i;i<length;i++)
    {
        if(str[i]=='[' || str[i]=='(' || str[i]=='{')
        {
                //ADD TO STACK
                add_stack(top,str[i],s);

        }
        else if(str[i]==']' || str[i]==')' || str[i]=='}')
        {
                result=pop(top,str[i],s);

                if(result==0)
                    break;
                if(i!=length-1 && top==-1)
                {

                    result=0;
                    break;
                }
        }
        else
        {
            continue;
        }

        if(i==length-1 && top!=-1)
        {
            result=0;
        }

    }

       if(result==0)
       {
           cout<<"INVALID";
       }
       else
       {
           cout<<"VALID";
       }


    return 0;
}
