#include<iostream>

using namespace std;
void insert_into_bst(struct node *head);

struct node
{
    struct node *left;
    int data;
    struct node *right;
};


void insert_into_bst(struct node *head,int value)
{
    struct node *p=head;
    struct node *r=NULL;
    struct node *temp=new node;

    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;

    while(1)
    {
        if(p==NULL)
        {
            if(value>r->data)
                r->right=temp;
            else
                r->left=temp;

          break;
        }
        else if(value>p->data)
        {
            r=p;
            p=p->right;
        }
        else
        {
            r=p;
            p=p->left;
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
    cout<<endl;
}

void delete_from_bst(struct node *head,int key)
{
    struct node *p=head;
    struct node *r=NULL;

    while(1)
    {
        if(p->data==key)
        {
            if(p->left==NULL && p->right==NULL)
            {
                if(key>r->data)
                r->right=NULL;
            else
                r->left=NULL;

            break;
            }
            else
            {

            }

        }
        else if(key>p->data)
        {
            r=p;
            p=p->right;
        }
        else
        {
            r=p;
            p=p->left;
        }
    }

}

int main()
{
    int n;
    cout<<"ENTER NO OF VALUES IN BST:";
    cin>>n;
    cout<<"ENTER VALUES";

    struct node *head=new node;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;

        if(i==0)
        {
            head->data=value;
            head->left=NULL;
            head->right=NULL;
        }
        else
        {
            insert_into_bst(head,value);
        }
    }

    cout<<endl<<"***********************************"<<endl;

    while(1)
    {
       int choice;
       cout<<"1.INORDER  2.INSERT  3.DELETE  4.EXIT";
       cin>>choice;

       if(choice==1)
          inorder(head);
       else if(choice==2)
       {
           int n;
           cout<<"ENTER VALUE:";
           cin>>n;

           insert_into_bst(head,n);
       }
       else if(choice==3)
       {
           int key;
           cout<<"ENTER KEY TO DELETE:";
           cin>>key;
           delete_from_bst(head,key);
       }
       else{break;}
    }

    return 0;
}
