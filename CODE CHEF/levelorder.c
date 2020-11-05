#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *left;
    struct node *right;

};

struct node* insert( struct node* root, int data ) {

	if(root == NULL) {

        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;

	} else {

		struct node* cur;

		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}

		return root;
	}
}

void levelOrder( struct node *root) {

    struct node * new_array[100];
    static int front=-1;
    static int rear=0;
    struct node * p=NULL;


    static int count=0;

    if(root==NULL)
    {front=0;}

    if(front==rear)
    {}
    else {
        if(count==0)
        {
            *(new_array+rear)=root;
            p=root;
            printf("%d ",p->data);
            count++;
        }

        if(p->left==NULL)
        {
            front++;
            if(p->right==NULL)
            {}
            else
            {
               rear++;
               p=p->right;
               *(new_array+rear)=p;
               printf("%d ",p->data);

               levelOrder(p);
            }
        }
        else
        {

        }

    }
}


int main() {

    struct node* root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

	levelOrder(root);
    return 0;
}

