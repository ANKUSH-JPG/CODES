#include<iostream>
#include<string>
#include<vector>
using namespace std;

int calculateTwo(int n,string s)
{
    int max_length=0;
    int alphabet[26]={0};

    vector<char> main_array;

    for(int i=0;i<n;i++)
    {
        alphabet[s[i]-97]=1;
    }

    for(int i=0;i<26;i++)
    {
        if(alphabet[i]==1)
            main_array.push_back(97+i);
    }

    int length=main_array.size();

    for(int i=0;i<length-1;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            string temp;

            for(int x=0;x<n;x++)
            {
                if(s[x]==main_array[i] || s[x]==main_array[j])
                    temp.push_back(s[x]);
            }


            int length_temp=temp.size(),c=1,check=0;

            for(int x=0;x<length_temp-1;x++)
            {
                if(temp[x]==temp[x+1])
                {
                    check=1;
                    break;
                }

                c=c+1;
            }

            if(check==0)
            {
                if(max_length<c)
                    max_length=c;
            }
        }
    }


    return max_length;
}

int main()
{
    int n;
    string s;

    cin>>n>>s;

    int result=calculateTwo(n,s);


    cout<<result;
    return 0;
}
