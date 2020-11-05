#include<stdio.h>

struct linked_list
{
    int data;

    struct linked_list* next;

}*head;


int main()

{

    int n;
    scanf("%d",&n);



    if(n>=1)
    {
        head=(struct linked_list*)malloc(sizeof(struct linked_list));


        for(int i=0;i<n;i++)
        {
            int no;
            scanf("%d",&no);
            if(n==0)
            {
                head->data=no;
                head->next=NULL;

            }
            else
            {
                struct linked_list * temp2=(struct linked_list*)malloc(sizeof(struct linked_list));

                temp2->data=no;
                temp2->next=head;
                head=temp2;


            }
        }

while(head!=NULL)
    {

        printf("%d \n",head->data);

        head=head->next;
    }
    }


    return 0;
}
