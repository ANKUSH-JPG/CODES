
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()

{
    int result=0;
    int magazine_no=0;
    int message_no=0;
    cin>>magazine_no>>message_no;

    vector<string> mag_vector;
    vector<string> mess_vector;
    for(int i=0;i<magazine_no;i++)
    {
        string get_text;
        cin>>get_text;

        mag_vector.push_back(get_text);
    }
    for(int i=0;i<message_no;i++)
    {
        string get_text;
        cin>>get_text;

       mess_vector.push_back(get_text);
    }


    for(int x=0;x<message_no;x++)
    {
        for(int y=0;y<magazine_no;y++)
        {
                if(mess_vector[x]==mag_vector[y])
                    {
                        result++;
                        mag_vector[y]="****";
                        break;
                    }

        }


    }

    if(result==message_no)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}
