#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {

  stack<char> st;
  int length=s.size();
  int check=0;
  for(int i=0;i<length;i++)
  {
      if(s[i]=='[' || s[i]=='(' || s[i]=='{')
          st.push(s[i]);
      else
      {
          if(st.empty())
          {
              check=1;
              break;
          }
          else
          {
              if(st.top()=='(' && s[i]==')')
               st.pop();
              else if(st.top()=='{' && s[i]=='}')
               st.pop();
              else if(st.top()=='[' && s[i]==']')
               st.pop();
              else
              {
               check=1;
               break;
              }
          }

      }
  }

  if(check==1)
    return "NO";
  else
    return "YES";



}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}

