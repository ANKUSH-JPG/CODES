#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void swap_op(struct node *head,int value);

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

queue<struct node *> q;
int height=0;
static int c_c=0;
vector< vector<int> > result;
int r_c=0;

struct node * initial(struct node *head,int n)
{
    for(int i=0;i<n;i++)
    {
        int v1,v2;
        cin>>v1;
        struct node *p=q.front();
        q.pop();

        if(v1!=-1)
        {
            struct node *temp=new node;
            temp->data=v1;
            temp->left=NULL;
            temp->right=NULL;

            p->left=temp;
            q.push(temp);
        }

        cin>>v2;
        if(v2!=-1)
        {
            struct node *temp=new node;
            temp->data=v2;
            temp->left=NULL;
            temp->right=NULL;

            p->right=temp;
            q.push(temp);
        }
    }

    return head;
}

void inorder(struct node *p)
{
    if(p!=NULL)
    {
       inorder(p->left);

       result[r_c].push_back(p->data);

       inorder(p->right);
    }

}

int count_height(struct node *head)
{
    if(head==NULL)
        return 0;
    else
    {
        int l,r;
        if(head->left!=NULL)
        {
            l=1+count_height(head->left);
        }
        else
            l=count_height(head->left);

        //FOR RIGHT
        if(head->right!=NULL)
        {
            r=1+count_height(head->right);
        }
        else
            r=count_height(head->right);

        if(l>r)
            return l;
        else
            return r;
    }

}

void execute_query(struct node *head)
{
    int n;
    cin>>n;


    for(int i=0;i<n;i++)
    {
        vector<int> a;
        result.push_back(a);
    }

    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;

        swap_op(head,value);
        inorder(head);
        r_c=r_c+1;
    }

    for(int i=0;i<n;i++)
    {
        int length=result[i].size();
        for(int j=0;j<length;j++)
            cout<<result[i][j]<<" ";

        cout<<endl;
    }
}

void swap_op(struct node *head,int value)
{
    if(head==NULL)
    {}
    else if(head->left==NULL && head->right==NULL)
    {}
    else
    {
        c_c=c_c+1;
        if(c_c%value==0)
        {
            struct node *temp=head->left;
            head->left=head->right;
            head->right=temp;

        }

        swap_op(head->left,value);
        swap_op(head->right,value);
        c_c=c_c-1;
    }
}


int main()
{
   int n;
   cin>>n;

   struct node *head=new node;
   head->data=1;
   head->left=NULL;
   head->right=NULL;
   q.push(head);
   head=initial(head,n);

   height=1+count_height(head);

   execute_query(head);




    return 0;
}
