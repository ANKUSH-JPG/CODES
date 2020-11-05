#include<stdio.h>

struct linked_list
{
    int data;
    struct linked_list *next;
};

struct linked_list * create_link(int *count,struct linked_list *head,struct linked_list *p)
{
    int no;
    printf("ENTER NO :");
    scanf("%d",&no);
            if(*count==0)
            {
                p=(struct linked_list *)malloc(sizeof(struct linked_list));
                p->data=no;
                p->next=NULL;
                head=p;
                (*count)=(*count)+1;
            }
            else
            {
                struct linked_list *temp=(struct linked_list *)malloc(sizeof(struct linked_list));
                temp->data=no;
                temp->next=NULL;

                p->next=temp;
                p=p->next;
                (*count)=(*count)+1;
            }

            return p;
}

int display_fun(struct linked_list *display)
{
    int count=0;
    printf("***************************************** \n");

             while(display)
             {
                 printf("%d ",display->data);
                 display=display->next;
                 count++;
             }


    return count;
}

struct linked_list * insert_position(struct linked_list *head,int po,int d)
{
    int i=0;
    struct linked_list *p=head;
    struct linked_list *q=head;
    struct linked_list *temp=(struct linked_list*)malloc(sizeof(struct linked_list));
    temp->data=d;

    while(p && i<po)
    {
        p=p->next;
        i=i+1;
    }i=0;
    q=p->next;

    if(po==0)
    {
        temp->next=head;
        head=temp;
    }
    else if(q==NULL)
    {
        p->next=temp;
        temp->next=NULL;
    }
    else{
        p->next=temp;
        temp->next=q;
    }

    return head;

}

int display_sum(struct linked_list *display)
{
    int count=0;
    while(display)
    {
        count=count+display->data;
        display=display->next;

    }

    return count;
}
void greatest(struct linked_list *p)
{
    int great=0;

    while(p)
    {
        if(p->data>great)
          great=p->data;

        p=p->next;
    }

   printf("GREATEST ELEMENT:%d\n",great);
}

struct linked_list * remove_duplicate(struct linked_list *head)
{
    struct linked_list *p=head;
    struct linked_list *q=p->next;

    while(p!=NULL && q!=NULL)
    {
        if(p->data!=q->data)
        {

            p=p->next;
            q=q->next;
        }
        else
        {

            p->next=q->next;
            struct linked_list *temp=q;

            q=q->next;
            temp->next=NULL;
        }

    }

    return head;
}
int main()
{
    int choice;
    struct linked_list *head=NULL;
    struct linked_list *p=NULL;


    printf("************ LINKED LIST ************************ \n");
    int count=0;
    while(1)
    {
        printf("1. Append \n2. Display \n3. Exit \n4. Sum \n5. Greatest \n6. Insert at position \n7. Remove Duplicate \n");
        scanf("%d",&choice);

        if(choice==3)
            break;
        else if(choice==1)
        {
            p=create_link(&count,head,p);
            if(count==1)
                head=p;
        }
        else if(choice==4)
        {
            int sum=display_sum(head);
            printf("\nTOTAL SUM:%d \n",sum);
        }
        else if(choice==5)
        {
            greatest(head);
        }
        else if(choice==6)
        {
            int position,data;
            printf("ENTER POSITION AND DATA :");
            scanf("%d%d",&position,&data);

            head=insert_position(head,position,data);
        }
        else if(choice==7)
        {
            head=remove_duplicate(head);
        }
        else
        {
            int element=display_fun(head);

            printf("\nTOTAL ELEMENTS:%d",element);

            printf("\n***************************************** \n");

        }
    }



    return 0;
}
