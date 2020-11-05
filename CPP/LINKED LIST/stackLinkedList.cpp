#include<iostream>

using namespace std;

int s_s;
struct node *head=NULL;
struct node
{
    int value;
    struct node * next;
};

struct node * push(int &top)
{
    if(top<s_s)
        top=top+1;
    if(top<s_s)
    {
        int value;
        cout<<"ENTER VALUE:";

        struct node * temp=new node;
        cin>>temp->value;
        temp->next=head;
        head=temp;

        return head;
    }
    else
    {
        cout<<"STACK OVERFLOW"<<endl;
        return head;
    }
}

void pop(int &top)
{
    if(head==NULL)
    {
        cout<<"STACK EMPTY"<<endl;
        top=-1;
    }
    else
    {
       struct node*temp=head;

       cout<<"DELETED:"<<temp->value<<endl;

       head=head->next;

       temp->next=NULL;
       delete temp;
       top=top-1;
    }

}
int main()
{
    int top=-1;
    int choice;
    cout<<"ENTER THE SIZE OF STACK:";
    cin>>s_s;
    while(1)
    {
            cout<<"1.PUSH  2.POP  3.PEEK  5.DISPLAY  4.EXIT"<<endl;
            cin>>choice;

            if(choice==1)
            {
                    head=push(top);
            }
            else if(choice==2)
            {
                    pop(top);
            }
            else if(choice==5)
            {
                struct node *p=head;
                while(p)
                {
                    cout<<p->value<<" ";
                    p=p->next;
                }cout<<endl;
            }
            else
            {
                break;
            }
    }

    return 0;
}
