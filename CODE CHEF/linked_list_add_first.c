#include<stdio.h>

struct linked_list
{
    int data;

    struct linked_list* next;

};


int main()

{

    int n;
    scanf("%d",&n);


    struct linked_list * head=NULL;

    if(n>=1)
    {



        head=(struct linked_list*)malloc(sizeof(struct linked_list));
        struct linked_list * temp=head;


        for(int i=0;i<n;i++)
        {

            int no;
            scanf("%d",&no);

            if(i==0)
            {
                temp->data=no;
                temp->next=NULL;
            }
            else
            {
                struct linked_list * temp2=(struct linked_list*)malloc(sizeof(struct linked_list));

            temp2->data=no;
            temp2->next=NULL;
            temp->next=temp2;
            temp=temp->next;
            }

        }



    }




    while(head!=NULL)
    {

        printf("%d \n",head->data);

        head=head->next;
    }


    return 0;

}
