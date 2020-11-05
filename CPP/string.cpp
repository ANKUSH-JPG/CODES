#include<iostream>
#include<vector>
#include<string>

using namespace std;
void generate_function(int n,vector<string> *s1,vector<string> *s2);

void generate_function(int n,vector<string> *s1,vector<string> *s2)
{

    for(int i=0;i<n;i++)
    {
        string s1_text,s2_text;
        cin>>s1_text>>s2_text;
        (*s1).push_back(s1_text);
        (*s2).push_back(s2_text);
    }

}

int main()
{
    int n=0;
    cin>>n;

    vector<string> s1;
    vector<string> s2;

    generate_function(n,&s1,&s2);


    for(int i=0;i<n;i++)
    {
        int check=0;
        int length_s1=s1[i].size();
        int length_s2=s2[i].size();

        for(int x=0;x<length_s2;x++)
        {
            for(int y=0;y<length_s1;y++)
            {
                if(s2[i][x]==s1[i][y])
                {
                    check=1;
                    break;
                }
            }

            if(check==1)
            {
               break;
            }
        }

            if(check==1)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }

        }

    return 0;
}
