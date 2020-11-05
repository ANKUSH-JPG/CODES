#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a,b;

    cin>>a>>b;

    int a_length=a.length();
    int b_length=b.length();

    int largest=0;
    for(int i=0;i<b_length;i++)
    {
        int check=0;
        int count_string=1;

        for(int j=0;j<a_length;j++)
        {
            if(b[i]==a[j])
            {
                check=1;
                if(j<a_length-1)
                {
                    int position=0;

                    for(int x=j+1;x<a_length;x++)
                    {int y;

                        if(position==0)
                        {
                            y=i+1;
                        }

                            while(y<b_length)
                            {
                            if(a[x]==b[y])
                            {
                                position=1;
                            count_string=count_string+1;
                            y=y+1;
                            break;
                            }
                            else
                            {
                                y++;
                            }
                            }

                    }
                }
            }
        }

        if(check==1)
        {
            if(count_string>largest)
            {
                largest=count_string;
            }
        }
    }


    cout<<largest;



    return 0;
}
