#include<iostream>
#include<vector>
using namespace std;
void input_elements(int no[],int n);
vector<int> i_function(int no[],int n);
int r_function(int no);

void input_elements(int no[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>no[i];
    }

}

vector<int> i_function(int no[],int n)
{
    vector<int> all_elements;
    for(int i=0;i<n;i++)
    {
        int value=r_function(no[i]);

        all_elements.push_back(value);
    }

    return all_elements;
}

int s_function(vector<int> all_elements)
{
    int length=all_elements.size();
    int sum=0;
    for(int i=0;i<length;i++)
    {
        sum=sum+all_elements[i];
    }


    int final_sum=r_function(sum);

    return final_sum;
}



int r_function(int no)
{
    if(no==no%10)
     return no;

    else
    {
        int sum=0;

        while(no!=0)
        {
            int remainder=no%10;
            no=no/10;
            sum=sum+remainder;
        }

        int result=r_function(sum);

        return result;
    }
}


int b_cal(int no,int final_sum)
{
    int check=0;

    while(no!=0)
    {
        int remainder=no%10;
        no=no/10;

        if(remainder==final_sum)
        {
            check=1;
            break;
        }
    }

    return check;
}

vector<int> f_function(int no[],int final_sum,int n)
{
    vector<int> binary;

    for(int i=0;i<n;i++)
    {
        int value=b_cal(no[i],final_sum);
        binary.push_back(value);
    }

    return binary;
}


int main()
{

    int n;
    cin>>n;

    int no[n];

    input_elements(no,n);

    vector<int> all_elements=i_function(no,n);

    int final_sum=s_function(all_elements);

    vector<int> binary=f_function(no,final_sum,n);

    cout<<"**************************************************"<<endl;

    int length=binary.size();

    for(int i=0;i<length;i++)
    {
        cout<<binary[i]<<" ";
    }

    return 0;
}
