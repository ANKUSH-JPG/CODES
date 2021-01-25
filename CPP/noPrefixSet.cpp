#include<iostream>
#include<string>
#define MAX_ALPHABET 10
using namespace std;

struct trie
{
    struct trie *p[MAX_ALPHABET];
    bool last;
};

int insert_to_trie(struct trie *head,string str)
{
    int l=str.size();
    int check=0;
    for(int i=0;i<l;i++)
    {
        int r=str[i]-'a';
        if(head->p[r]==NULL)
        {
            head->p[r]=new trie;

            for(int k=0;k<MAX_ALPHABET;k++)
                head->p[r]->p[k]=NULL;

            head->last=false;

            if(i<l-1)
                head=head->p[r];
        }
        else
        {
            if(head->last)
            {
                check=1;
                head=head->p[r];
            }
            else
            {
                head=head->p[r];
            }
        }
    }head->last=true;

    return check;
}
int main()
{
    int n;
    cin>>n;
    string str;
    string status,s;
    int check=0;

    struct trie *head=new trie;

    for(int i=0;i<MAX_ALPHABET;i++)
        head->p[i]=NULL;

    for(int i=0;i<n;i++)
    {
        cin>>str;

        int r=insert_to_trie(head,str);

        if(r==1)
        {
            if(check!=1)
            {
                check=1;
                status="BAD SET";
                s=str;
            }
        }
        else
        {
            if(check!=1)
            {
                status="GOOD SET";
            }
        }
    }

    cout<<status<<endl<<s;

    return 0;
}
