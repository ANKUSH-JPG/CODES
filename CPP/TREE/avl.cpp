#include<iostream>

using namespace std;
int AVL(struct node *p);
void inorder(struct node *p);

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node * insert_into(struct node *head)
{
 int c=0;

 while(1)
 {
      struct node *p=head;
      struct node *r=NULL;

     int choose;
     cout<<"1.INSERT  2.EXIT";
     cin>>choose;
     if(choose==1)
     {
         if(c==0)
     {
         cout<<"ENTER DATA:";
         cin>>head->data;
         head->left=NULL;
         head->right=NULL;
     }
     else
     {
         struct node *temp=new node;
         cout<<"ENTER DATA:";
         cin>>temp->data;
         temp->left=NULL;
         temp->right=NULL;

         while(p)
         {
             if(temp->data>p->data)
             {
                 r=p;
                 p=p->right;
             }
             else
             {
                 r=p;
                 p=p->left;
             }
         }if(temp->data>r->data)
             {
                r->right=temp;
             }
             else
             {
                 r->left=temp;
             }
     }


     int result=AVL(head);cout<<endl;
     c=c+1;
     }
     else
     {
         break;
     }

 }
}

void inorder(struct node *p)
{
    if(p!=NULL)
    {
       inorder(p->left);

       cout<<p->data<<" ";

       inorder(p->right);
    }
}

int AVL(struct node *p)
{    int r_c=0,l_c=0;
    if(p->left==NULL && p->right==NULL)
    {
        return 0;
    }
    else
    {

        if(p->left!=NULL)
            l_c=1+AVL(p->left);
        else
            l_c=0;


        if(p->right!=NULL)
            r_c=1+AVL(p->right);
        else
            r_c=0;

    }

        int difference=l_c-r_c;
        cout<<difference<<" ";

        if(l_c>r_c)
            return l_c;
        else
            return r_c;
}
int main()
{
    struct node *head=new node;
    head=insert_into(head);


    return 0;
}
