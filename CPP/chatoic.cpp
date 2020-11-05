#include<iostream>
#include<vector>
using namespace std;

int main()
{
int no_of_times;
int length;


cin>>no_of_times;

for(int i=0;i<no_of_times;i++)
{
    cin>>length;
    vector<int> vec(length);
    vector<int> vech(length);

    for(int j=0;j<length;j++)
    {
        int no;
        cin>>no;
        vec[j]=no;
        vech[j]=j+1;
    }

    int check=1;
    int final_result=0;

    while(check==1)
    {
      int position=0;
      int check_count=0;
      int result_count=0;
      for(position;position<length;position++)
      {

          int vec_element=vec[position];
          int vech_element=vech[position];

          if(vec_element==vech_element)
          {
              check_count=check_count+1;
              if(check_count==length)
              {
                  check=0;
                  break;
              }
          }

          else{
           int x=0;
            for(x;x<length;x++)
            {
                if(vech[x]==vec_element)
                {
                    break;
                }
                }

                if(x>position)
                {
                    int bribe=x-position;
                    if(bribe>2)
                    {
                        check=5;
                        break;
                    }
                    else
                    {
                        for(int z=0;z<bribe;z++)
                        {
                            int y=vech[x];
                            vech[x]=vech[x-1];
                            vech[x-1]=y;

                            x=x-1;
                        }
                    }
                    result_count=bribe+result_count;
                }
            }


          }

          if(check==5)
          {
              break;
          }

          final_result=final_result+result_count;
        }

        if(check==5)
        {
            cout<<"Too chaotic"<<endl;
        }
        else
        {
            cout<<final_result<<endl;
        }

      }

      return 0;
    }





