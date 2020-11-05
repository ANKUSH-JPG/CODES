#include<iostream>

using namespace std;

struct node
{
  struct node *left;
  char data;
  struct node *right;
};

struct q
{
    int f=0;
    int r=-1;
    struct node *a[100]={NULL};
};

struct node * add_root(struct node *a[],int &f,int &r)
{
    struct node *temp=new node;
    r=r+1;
    cout<<"ENTER CHARACTER FOR ROOT:";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;

    a[r]=temp;
    return temp;
}

struct node * add_nodes(struct node *head,struct node *a[],int &f,int &r)
{

 while(a[f]!=NULL)
 {
 int choice;
 cout<<"WANT LEFT CHILD: 1.YES  2.NO";
 cin>>choice;

 struct node *p=a[f];
 f=f+1;
 if(choice==1)
 {
     struct node *l=new node;
     cout<<"ENTER DATA:";
     cin>>l->data;
     l->left=NULL;l->right=NULL;

     p->left=l;

     // INSERT INTO QUEUE
     r=r+1;a[r]=l;

     // RIGHT PART
     int rchoice;
cout<<"WANT RIGHT CHILD: 1.YES  2.NO";
cin>>rchoice;

    if(rchoice==1)
    {
     struct node *ri=new node;
     cout<<"ENTER DATA:";
     cin>>ri->data;
     ri->left=NULL;ri->right=NULL;

     p->right=ri;

     // INSERT INTO QUEUE
     r=r+1;a[r]=ri;

    }

 }
 else
 {
     int rchoice;
cout<<"WANT RIGHT CHILD: 1.YES  2.NO";
cin>>rchoice;

    if(rchoice==1)
    {
     struct node *ri=new node;
     cout<<"ENTER DATA:";
     cin>>ri->data;
     ri->left=NULL;ri->right=NULL;

     p->right=ri;

     // INSERT INTO QUEUE
     r=r+1;a[r]=ri;

      }
    }
  }

  return head;
}

void preorder(struct node *p)
{
    if(p!=NULL)
    {
       cout<<p->data<<" ";

       preorder(p->left);

       preorder(p->right);
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

void postorder(struct node *p)
{
    if(p!=NULL)
    {
       postorder(p->left);

       postorder(p->right);

       cout<<p->data<<" ";
    }
}

void levelorder(struct node *a[],int &f,int &r)
{
    while(f!=r)
    {
        f=f+1;

        struct node *p=a[f];
        cout<<p->data<<" ";
        if(p->left!=NULL)
        {
            r=r+1;
            a[r]=p->left;
            if(p->right!=NULL)
            {
                r=r+1;
                a[r]=p->right;
            }
        }
        else
        {
            if(p->right!=NULL)
            {
                r=r+1;
                a[r]=p->right;
            }
        }
    }
}



int main()
{

   struct node *head=new node;
   struct q q1;

   head=add_root(q1.a,q1.f,q1.r);

   head=add_nodes(head,q1.a,q1.f,q1.r);

   cout<<"!!!!!!!!!!!!!! OK COMPLETED CREATION OF TREE !!!!!!!!!!!!!!"<<endl;

   while(1)
   {
      int choice;
      cout<<endl<<"1.PREORDER  2.INORDER  3.POSTORDER  4.LEVEL ORDER  5.EXIT"<<endl;
      cin>>choice;

     if(choice==1)
        preorder(head);

     else if(choice==2)
        inorder(head);

    else if(choice==3)
        postorder(head);

    else if(choice==4)
    {
        q1.f=-1;
        q1.r=-1;

        q1.r=q1.r+1;

        q1.a[q1.r]=head;

        levelorder(q1.a,q1.f,q1.r);

    }

    else
        break;
   }


   return 0;
}
