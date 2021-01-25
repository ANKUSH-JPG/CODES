#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {

  vector<int> result;
  long int n=ranked.size();

  long int prev=0,total=0;
  queue<long int> q;

  for(long int i=n-1;i>=0;i--)
  {
      if(ranked[i]!=prev)
      {
          prev=ranked[i];
          q.push(ranked[i]);
          total=total+1;
      }
  }q.push(1000000);

  for(int i=0;i<player.size();i++)
  {
      long int c=0,no=player[i];

      while(!q.empty())
      {
          if(no>q.front())
          {
              c=c+1;
              q.pop();
          }
          else
          {
            if(no==q.front())
            {
                result.push_back(total-c);
                total=total-c;

                break;
            }
            else
            {
                result.push_back(total-c+1);
                total=total-c;
                break;
            }
          }
      }
  }

  return result;
}

int main()
{
  long int n,m;
  cin>>n;

  vector<int> leader,player;

  for(long int i=0;i<n;i++)
  {
      int no;
      cin>>no;
      leader.push_back(no);
  }

  cin>>m;

    for(long int i=0;i<m;i++)
    {
      int no;
      cin>>no;
      player.push_back(no);
    }

    vector<int> result=climbingLeaderboard(leader,player);

    int length=result.size();

    for(int i=0;i<length;i++)
    {
        cout<<result[i]<<endl;

    }

  return 0;
}
