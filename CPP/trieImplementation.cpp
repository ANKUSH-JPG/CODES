#include<iostream>
#include<stdio.h>
#include<vector>
#define MAX_ALPHABET 26
using namespace std;



struct trie{

  struct trie *p[MAX_ALPHABET];
  bool last;
  vector<int> position;

};

vector<int> result;
int c=0;

void find_using_recursion(struct trie *head)
{
    int length=head->position.size();
    for(int i=0;i<length;i++)
    {
        if(head->p[head->position[i]]!=NULL)
        {
            find_using_recursion(head->p[head->position[i]]);
        }
    }

    if(head->last==true)
      {
         c=c+1;
      }


}

void insert_str(string str,struct trie *head)
{
    int length=str.size();
    for(int i=0;i<length;i++)
    {
        int r=str[i]-'a';
        if(head->p[r]==NULL)
        {
            head->position.push_back(r);
            head->p[r]=new trie;
            for(int k=0;k<MAX_ALPHABET;k++)
                head->p[r]->p[k]=NULL;

                if(head->last!=true)
                    head->last=false;

                head=head->p[r];
        }
        else
        {
            head=head->p[r];
        }
    }head->last=true;
}

void find_contact(string str,struct trie *head)
{

    int check=0;
    c=0;
    int n=str.size();
    for(int i=0;i<n;i++)
    {
        int r=str[i]-'a';
        if(head->p[r]!=NULL)
        {
           head=head->p[r];
        }
        else
        {
            check=1;
            break;
        }

    }

    if(check==1)
        result.push_back(c);
    else
    {

        find_using_recursion(head);
        result.push_back(c);
    }

}


int main()
{
    int n;
    cin>>n;

    struct trie *head=new trie;
    for(int i=0;i<MAX_ALPHABET;i++)
        head->p[i]=NULL;

   for(int x=0;x<n;x++)
   {
       string s;
       cin>>s;

       if(s=="add")
       {
           string str;
           cin>>str;
           insert_str(str,head);
       }
       else if(s=="find")
       {
           string str;
           cin>>str;
           find_contact(str,head);
       }
   }

   int l=result.size();
   for(int i=0;i<l;i++)
   {
       cout<<result[i]<<endl;
   }
    return 0;
}
