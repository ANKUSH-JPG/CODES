#include<stdio.h>


struct linked_list
{
    int data;
    struct linked_list * next;
};

struct linked_list * merge(struct linked_list *first,struct linked_list *second)
{
    struct linked_list *start=NULL;
    struct linked_list *temp=NULL;
    int i=0;
    while(first && second)
    {
        if(i==0)
        {
            if(first->data<second->data)
            {
               start=first;
               first=first->next;

               start->next=NULL;
            }
            else
            {
               start=second;
               second=second->next;

               start->next=NULL;
            }
         temp=start;
         i++;
        }

        else
        {
            if(first->data<second->data)
            {
               temp->next=first;
               temp=temp->next;

               first=first->next;
               temp->next=NULL;
            }
            else
            {
               temp->next=second;
               temp=temp->next;

               second=second->next;
               temp->next=NULL;
            }
        }

    }
    if(second==NULL)
    {
        while(first)
        {
            temp->next=first;
            temp=temp->next;
            first=first->next;
        }
    }
    else if(first==NULL)
    {
        temp->next=second;
        temp=temp->next;

        second=second->next;
    }

    return start;

}

void display(struct linked_list *p)
{
    while(p)
    {
        printf("%d ",p->data);

        p=p->next;
    }

}

int main()
{
    struct linked_list *first=(struct linked_list *)malloc(sizeof(struct linked_list));
    struct linked_list *second=(struct linked_list *)malloc(sizeof(struct linked_list));

    struct linked_list *f=first;
    struct linked_list *s=second;

    int s_f,s_s;
    printf("ENTER THE LINKED LIST SIZE :");
    scanf("%d%d",&s_f,&s_s);

    printf("FIRST LINKED LIST:");
    for(int i=0;i<s_f;i++)
    {
        int n;

        scanf("%d",&n);
        if(i==0)
        {
            f->data=n;
            f->next=NULL;
        }
        else
        {
            struct linked_list *temp=(struct linked_list *)malloc(sizeof(struct linked_list));
            temp->data=n;
            temp->next=NULL;

            f->next=temp;
            f=f->next;
        }
    }

    printf("SECOND LINKED LIST:");
    for(int i=0;i<s_s;i++)
    {
        int n;

        scanf("%d",&n);
        if(i==0)
        {
            s->data=n;
            s->next=NULL;
        }
        else
        {
            struct linked_list *temp=(struct linked_list *)malloc(sizeof(struct linked_list));
            temp->data=n;
            temp->next=NULL;

            s->next=temp;
            s=s->next;
        }
    }

    first=merge(first,second);

    display(first);

    return 0;
}
