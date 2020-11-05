#include<iostream>
#include<string>

void subset(std::string,std::string,int);

int main()
{
    std::string str, curr= "";
    int index=0;
    printf("Enter your String: ");
    std::getline(std::cin,str);
    subset(str,curr,index);
}

void subset(std::string str, std::string curr, int index)
{
    if(str.length() == index)
    {
        std::cout<<curr<<" ";
        return;
    }
    subset(str,curr,index++);
    subset(str,curr + str[index],index++);
}
