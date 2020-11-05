#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct node *function_call(struct node *p, int v1,struct node *new_array[10],int check);
struct node *function_call2(struct node *p2, int v2,struct node *new_array2[10],int check2);

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

struct node *lca( struct node *root, int v1, int v2 ) {
  printf("* \n");

  struct node *new_array[10];
  struct node *new_array2[10];
  int check=0;
  int check2=0;

  struct node *p=root;
  struct node *p2=root;

  for(int i=0;i<10;i++)
  {
      *(new_array+i)=NULL;
      *(new_array2+i)=NULL;
  }


 struct node *value=function_call(p,v1,new_array,check);

 struct node *value2=function_call2(p2,v2,new_array2,check2);


 for(int i=0;i<10;i++)
  {
      printf("%d  ",*(new_array+i));

  }
  printf("\n");
  for(int i=0;i<10;i++)
  {
      printf("%d  ",*(new_array2+i));

  }


  printf("\n ------------------ \n");
  return value;
}


 struct node *function_call(struct node *p, int v1,struct node *new_array[10],int check)
 {

     struct node *result;

     if(p->data==v1)
  {
       printf("\n 1 \n");
        return p;
  }
  else if(p->data<v1)
  {

      new_array[check]=p;
      check++;
      p=p->right;

     result=function_call(p,v1,new_array,check);
  }
  else {

      new_array[check]=p;
      check++;
      p=p->left;

      result=function_call(p,v1,new_array,check);
}

return result;

 }

 struct node *function_call2(struct node *p2, int v2,struct node *new_array2[10],int check2)
 {
      struct node *result2;

if(p2->data==v2)
{
    return p2;
}
else if(v2>p2->data)
{
     new_array2[check2]=p2;
      check2++;
      p2=p2->right;

     result2=function_call(p2,v2,new_array2,check2);
}

else
{
    new_array2[check2]=p2;
      check2++;
      p2=p2->left;

      result2=function_call(p2,v2,new_array2,check2);

}

 return result2;
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
  	int v1;
  	int v2;

  	scanf("%d%d", &v1, &v2);
	struct node *ans = lca(root, v1, v2);
  	printf("%d", ans->data);

    return 0;
}
