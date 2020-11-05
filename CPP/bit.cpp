#include<iostream>
#include<cmath>
using namespace std;
long long int getDecimalNo();
void changeArrayBit(int array_bit);
long long int calculateFinalResult(int array_bit);

long long int getDecimalNo()
{
    long long int no;
    cin>>no;

    return no;
}

void changeArrayBit(int * array_bit)
{
    for(int i=0;i<32;i++)
    {
        if(array_bit[i]==0)
        {
            array_bit[i]=1;
        }
        else
        {
            array_bit[i]=0;
        }
    }
}

long long int calculateFinalResult(int * array_bit)
{
    long long int result=0;
    for(int i=0;i<32;i++)
    {
        result=result+(array_bit[i]*pow(2,i));
    }

    return result;
}

int main()
{

    int no;
    cin>>no;

    long long int decimal_no[no];

    for(int i=0;i<no;i++)
    {
        decimal_no[i]=getDecimalNo();
    }

    for(int i=0;i<no;i++)
    {
        int array_bit[32];
        for(int j=0;j<32;j++)
        {
            array_bit[j]=0;
        }

        int position=0;
        while(decimal_no[i]!=0)
        {
           int remainder=decimal_no[i]%2;
           decimal_no[i]=decimal_no[i]/2;

           array_bit[position]=remainder;

           position++;
        }

        changeArrayBit(array_bit);


       long long int result=calculateFinalResult(array_bit);

       cout<<result<<endl;
    }

    return 0;
}
