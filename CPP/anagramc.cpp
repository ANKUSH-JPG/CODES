#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{

    string a,b;
    string result_string;
    vector<int> result_string_count;
    cin>>a>>b;

    string mid_string=a+b;

    int mid_string_length=mid_string.length();

    int position=0;
    for(int i=0;i<mid_string_length;i++)
    {
        if(i==0)
        {

            result_string[position]=mid_string[i];
            result_string_count.push_back(1);
            position=position+1;
        }
        else
        {
            int result_string_length=result_string_count.size();
            int element=mid_string[i];
            int check=0;

            for(int x=0;x<result_string_length;x++)
            {
                if(result_string[x]==element)
                {
                    result_string_count[x]=result_string_count[x]+1;
                    check=1;
                }
            }

            if(check==0)
            {
            result_string[position]=element;
            result_string_count.push_back(1);
            position=position+1;
            }

        }
    }

    int result_string_length=result_string_count.size();
     int total_count=0;
     int valid_count=0;
    for(int i=0;i<result_string_length;i++)
    {
        total_count=total_count+result_string_count[i];

        if(result_string_count[i]%2==0)
        {
            continue;
        }
        else
        {
            result_string_count[i]=result_string_count[i]-1;
        }
    }

    for(int i=0;i<result_string_length;i++)
    {
        valid_count=valid_count+result_string_count[i];
    }

    cout<<total_count-valid_count;



return 0;
}
