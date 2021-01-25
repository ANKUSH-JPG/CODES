#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
   int n;
   cin>>n;

   vector<string> phonebook;
   vector<int> result;

   for(int i=0;i<n;i++)
   {
       string operation;
       cin>>operation;

       if(operation=="add")
       {
           string name;
           cin>>name;

           phonebook.push_back(name);
       }
       else if(operation=="find")
       {
           string name;
           cin>>name;

           int c=0;

           int length=phonebook.size();
           for(int f=0;f<length;f++)
           {
               if(phonebook[f].find(name)!=-1)
                  c=c+1;
           }

           result.push_back(c);
       }

   }

   int length=result.size();

   for(int i=0;i<length;i++)
   {
       cout<<result[i]<<endl;
   }


    return 0;
}
