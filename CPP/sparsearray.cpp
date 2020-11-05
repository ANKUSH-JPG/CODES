#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()

{
    int no_of_rows_question=0;
    cin>>no_of_rows_question;

// CREATED FOR THE QUESTION PART .......................
    vector< vector<char> > question(no_of_rows_question);
    vector<int> question_length(no_of_rows_question);

    for(int i=0;i<no_of_rows_question;i++)
    {   string input;
        cin>>input;
        int length=input.length();
        question_length[i]=length;
        question[i]=vector<char>(length);

        for(int j=0;j<length;j++)
        {
            question[i][j]=input[j];
        }
    }


// CREATING FOR THE ANSWER PART NOW......................
    int no_of_rows_answer=0;
    cin>>no_of_rows_answer;
    vector< vector<char> > answer(no_of_rows_answer);
    vector<int> answer_length(no_of_rows_answer);

    for(int i=0;i<no_of_rows_answer;i++)
    {   string input;
        cin>>input;
        int length=input.length();
        answer_length[i]=length;
        answer[i]=vector<char>(length);

        for(int j=0;j<length;j++)
        {
            answer[i][j]=input[j];
        }
    }

// MAIN LOGIC HERE: ...........................

int a_l_length=answer_length.size();
int q_l_length=question_length.size();


for(int i=0;i<a_l_length;i++)
{   int result=0;
    int check=1;
    for(int j=0;j<q_l_length;j++)
    {
        if(answer_length[i]==question_length[j])
        {
            int found_length=answer_length[i];

            for(int x=0;x<found_length;x++)
            {
                if(answer[i][x]==question[j][x])
                {
                    check=0;
                }
                else
                {
                   check=1;
                   break;
                }
            }
            if(check==0)
    {
            result=result+1;
    }
        }

    }

    cout<<result<<endl;
}

return 0;
}

