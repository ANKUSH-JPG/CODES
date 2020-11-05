#include<iostream>

using namespace std;

void combination(int a, int b,int &result)
{
  static int p=1;
  static int q=1;
  static int c_p=0;

  if(a==1)
  {
      p=p*1;
      q=q*1;
  }
  if(b==0)
  {
      result=1;
  }
  else if(c_p==b)
  {
      q=q*a;
      combination(a-1,b,result);
  }
  else
  {
      c_p++;
      if(a>b){p=p*a;combination(a-1,b,result);}
      if(a<=b){p=p*a;q=q*a;combination(a-1,b,result);}
  }

  result=p/q;


}

int main()
{
    int a,b;
    cin>>a>>b;

    int result=1;
    combination(a,b,result);

    cout<<result;

    return 0;
}
