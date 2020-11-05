#include<iostream>
#include<string>

using namespace std;

int noOfA(string s,int length);
long long int calculate_result(string s,long long int extended_length,int no_of_a,int length);

int noOfA(string s,int length)
{
    int count_a=0;
    for(int i=0;i<length;i++)
    {
        if(s[i]=='a')
        {
            count_a++;
        }
    }

    return count_a;
}

long long int calculate_result(string s,long long int extended_length,int no_of_a,int length)
{
    long long int result=0;
    if(extended_length%length==0)
    {

        long long int division=extended_length/length;

        result=no_of_a*division;
    }
    else
    {
        long long int division=extended_length/length;
        result=no_of_a*division;
        long long int remainder=extended_length%length;

        for(int i=0;i<remainder;i++)
        {
            if(s[i]=='a')
        {
            result++;
        }
        }
    }

    return result;
}

int main()
{

    string s;
    cin>>s;

    long long int extended_length;
    cin>>extended_length;


    int length=s.length();


    int no_of_a=noOfA(s,length);


    long long int result=calculate_result(s,extended_length,no_of_a,length);

    cout<<result;
    return 0;
}
