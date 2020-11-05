#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    string character;

    int no_of_times;
    cin>>no_of_times;

    for(int i=0;i<no_of_times;i++)
    {
        cin>>character;

        int length=character.length();
        int result_count=0;

        for(int current=0;current<length;current++)
        {
            int plus_one=current+1;
            int check=1;

            while(check==1)
            {
                if(character[current]=='*')
                {
                    break;
                }
                else if(character[current]==character[plus_one])
                {
                    result_count=result_count+1;
                    character[plus_one]='*';
                    plus_one=plus_one+1;
                }
                else
                {
                    check=0;
                }
            }
        }

        cout<<result_count<<endl;
    }


    return 0;
}
