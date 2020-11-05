#include<iostream>
#include<vector>

using namespace std;


vector<int> insert_cookies(vector<int> cookies)
{
    int s_c=cookies.size();

    while(s_c/2)
    {
        if(cookies[(s_c/2)-1]>cookies[s_c-1])
        {
            int temp=cookies[s_c-1];
            cookies[s_c-1]=cookies[(s_c/2)-1];
            cookies[(s_c/2)-1]=temp;

            s_c=s_c/2;
        }
        else
        {
            break;
        }
    }

    return cookies;
}

vector<int> delete_cookies(vector<int> cookies,int &c)
{
    int c_s=cookies.size();

    if(c_s!=0)
    {
        c=cookies[0];

    cookies[0]=cookies[c_s-1];
    cookies.pop_back();

    int current=0;

    while(2*current+1<c_s)
    {
        if(2*current+2<c_s)
        {
            //right
            if(cookies[2*current+1]<cookies[2*current+2])
            {
                if(cookies[current]>cookies[2*current+1])
                {
                    int temp=cookies[current];
                    cookies[current]=cookies[2*current+1];
                    cookies[2*current+1]=temp;
                    current=2*current+1;
                }
                else
                    break;
            }
            else
            {
                if(cookies[current]>cookies[2*current+2])
                {
                    int temp=cookies[current];
                    cookies[current]=cookies[2*current+2];
                    cookies[2*current+2]=temp;
                    current=2*current+2;
                }
                else
                    break;
            }
        }
        else
        {
            if(cookies[current]>cookies[2*current+1])
                {
                    int temp=cookies[current];
                    cookies[current]=cookies[2*current+1];
                    cookies[2*current+1]=temp;
                    current=2*current+1;
                }
                else
                    break;
        }
    }

    return cookies;
    }
    else
    {
        c=0;
        return cookies;
    }

}
int main()
{
    int n,k;
    vector<int> cookies;
    cin>>n;
    cin>>k;

    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;

        cookies.push_back(value);
        cookies=insert_cookies(cookies);
    }

    int sweet=0;
    int c1=0,c2=0,times=0;
    while(1)
    {

        cookies=delete_cookies(cookies,c1);

        if(c1!=0)
        {
            if(c1<k)
            {
            times=times+1;
            cookies=delete_cookies(cookies,c2);
            if(c2!=0)
            {
               sweet=1*c1+2*c2;
               cookies.push_back(sweet);
               cookies=insert_cookies(cookies);
            }
            else
            {
                times=-1;
                break;
            }

            }
            else
                break;
        }
        else
        {
            times=-1;
            break;
        }

    }

    cout<<times;

    return 0;
}
