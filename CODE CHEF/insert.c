#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *left;
    struct node *right;

}root;

void preOrder( struct node *head) {

	if( head == NULL )
      return;
	printf("%d ",head->data);
	preOrder(head->left);
	preOrder(head->right);

}

struct node* insert( struct node* head, int data ) {

        if(head!=NULL)
        {

            struct node * value=(struct node*)malloc(sizeof(struct node));
        value->data=data;
        value->left=NULL;
        value->right=NULL;


        struct node * temp=head;
        int check=0;



        while(check!=1)
        {

            if(data<temp->data)
            {
                if(temp->left==NULL)
                {
                        temp->left=value;
                        check=1;
                }
                else
                {
                         temp=temp->left;
                }
            }
            else if(data>temp->data)
            {
                if(temp->right==NULL)
                {
                    temp->right=value;
                    check=1;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }}
        else
        {

        head=(struct node*)malloc(sizeof(struct node));
        head->data=data;
        head->left=NULL;
        head->right=NULL;
        }



        return head;


}


int main() {


    struct root * head=NULL;
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        head = insert(head, data);
    }

	preOrder(head);
    return 0;
}

