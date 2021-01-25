#include<iostream>
#include<vector>
#include<string>
using namespace std;


string calculate(vector<vector<long int > > m)
{

   string result;
   int n=m.size();

   for(int i=0;i<n;i++)
   {
       long int true_b=0;
       long int false_b=0;
       for(int j=0;j<n;j++)
       {
           true_b=true_b+m[i][j];
           false_b=false_b+m[j][i];
       }
       if(false_b-m[i][i]==true_b-m[i][i])
        {
           cout<<"*"<<endl;
           result="Possible";
        }
       else {
          cout<<"/"<<endl;
          result="Impossible";
          break;
       }
   }

   return result;

}

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        int n;

        cin>>n;

        vector<vector<long int > > m;
        for(int j=0;j<n;j++)
        {
            vector<long int> v;

            for(int k=0;k<n;k++)
            {
                int no;
                cin>>no;

                v.push_back(no);
            }
            m.push_back(v);
        }

        string r=calculate(m);
        cout<<r<<endl;
    }
    return 0;
}
