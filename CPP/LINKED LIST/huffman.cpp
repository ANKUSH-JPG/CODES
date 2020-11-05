#include<iostream>
#include<string>

using namespace std;
void table_generation(string str,int &n);
void sort_table(struct table a[],int n);


struct huffman
{
    char alpa;
    int data;
    struct huffman * left;
    struct huffman * right;
};

struct table
{
    char alpha;
    int freq;
};

void table_generation(string str,int &n)
{
    char greatest='A';
    int length=str.size();


    // FINDING GREATEST ELEMENT
    for(int i=0;i<length;i++)
    {
        if(str[i]>greatest)
           greatest=str[i];

    }

    // COUNTINING FREQUENCE
    int hashmap[greatest-96]={0};
    for(int i=0;i<length;i++)
    {
        hashmap[str[i]-97]=hashmap[str[i]-97]+1;

    }

    // ADD DATA TO STRUCTURE TABLE A
    int position=0;
    for(int i=0;i<greatest-96;i++)
    {
        if(hashmap[i]!=0)
            n++;
    }

    // CREATING STRUCTURE
    struct table a[n];

    for(int i=0;i<greatest-96;i++)
    {
        if(hashmap[i]!=0)
        {
            a[position].alpha=i+97;
            a[position].freq=hashmap[i];
            position++;
        }
    }



    sort_table(a,n);


}

void sort_table(struct table a[],int n)
{

    for(int i=0;i<n;i++)
    {
        cout<<a[i].alpha<<" "<<a[i].freq<<endl;
    }
}

int main()
{
    int choice,n=0;
    cout<<"1. ENTER STRING"<<endl<<"2. EXIT"<<endl;

    cin>>choice;

    if(choice==1)
    {
       string str;
       cout<<"Enter string: ";
       getline(cin, str);
       cout<<str;
       table_generation(str,n);
     }
    else
    {
        return 0;
    }



    return 0;
}

