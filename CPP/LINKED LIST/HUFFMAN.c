#include<stdio.h>
#include<math.h>
#define MAX 1000
typedef struct node
{
        struct node *left;
        char ch;
        int freq;
        struct node *right;
}node;

struct table
{
    char alpha;
    int freq;
};

struct codes
{
    int sequence[MAX][8];
    int binary[8];
    char ch[MAX];

};

void table_generation(char str[],int length);
node * delete_from_heap();
void swap_fun(int current);

node * heap[MAX];
int max_heap=-1;
node *d1;node *d2;
int x=-1;

//FOR codes
struct codes c;
int m=0;


void table_generation(char str[],int length)
{
   char greatest='0';

   // FINDING GREATEST ELEMENT
    for(int i=0;i<length;i++)
    {
        if(str[i]>greatest)
           greatest=str[i];

    }

    // COUNTINING FREQUENCE
    int hashmap[MAX]={0};
    for(int i=0;i<length;i++)
    {
        if(str[i]>=97)
            hashmap[str[i]-97]=hashmap[str[i]-97]+1;

        else if(str[i]>=65)
            hashmap[(str[i]-65)+26]=hashmap[(str[i]-65)+26]+1;
        else if(str[i]==32)
            hashmap[99]=hashmap[99]+1;

    }

    // ADD DATA TO STRUCTURE TABLE A
    int position=0,n=0;
    for(int i=0;i<MAX;i++)
    {
        if(hashmap[i]!=0)
            n++;
    }

    // CREATING STRUCTURE
    struct table a[n];

    for(int i=0;i<MAX;i++)
    {
        if(hashmap[i]!=0)
        {
            if(i<25)
            {
              a[position].alpha=i+97;
              a[position].freq=hashmap[i];

            }
            else if(i==99)
            {
                a[position].alpha=32;
                a[position].freq=hashmap[99];
            }
            else
            {
                a[position].alpha=i+39;
                a[position].freq=hashmap[i];
            }

            position++;
         }
    }

    for(int i=0;i<n;i++)
    {
           printf("%c  %d\n",a[i].alpha,a[i].freq);
           Insert_into_heap(a[i].alpha,a[i].freq);
    }

    while(heap[1]!=NULL)
    {

        d1=delete_from_heap();

        d2=delete_from_heap();

        int f=d1->freq+d2->freq;
        //printf("%d\n",f);
        char c='0';

        Insert_into_heap(c,f);
    }

    // VALUE OF BINARY TO 2
    for(int i=0;i<8;i++)
    {
        c.binary[i]=2;
    }

    // VALUE OF SEQUENCE AND CH TO 2
    for(int i=0;i<MAX;i++)
    {
        c.ch[i]='0';
        for(int j=0;j<8;j++)
            c.sequence[i][j]=2;
    }
    display(heap[0]);


    //PRINT SEQUENCE

    print_sequence(str);

    /*printf("---%d----\n",max_heap);
    for(int i=0;i<n;i++)
    {

         printf("%d ",heap[i]->freq);
    }*/



}

void Insert_into_heap(char alpha,int freq)
{
      max_heap=max_heap+1;

      if(alpha=='0')
      {
          node *temp=(node *)malloc(sizeof(node));
          temp->ch=alpha;
          temp->freq=freq;
          temp->left=d1;
          temp->right=d2;

          heap[max_heap]=temp;

          heap_sort(max_heap);
      }
      else
      {
      node *temp=(node *)malloc(sizeof(node));
      temp->ch=alpha;
      temp->freq=freq;
      temp->left=NULL;
      temp->right=NULL;

      heap[max_heap]=temp;

      heap_sort(max_heap);
      }


}

void heap_sort(int current)
{
    if(current==-1)
    {}
    else
    {
        if(current*2+1<=max_heap)
        {
            // OPERATION PERFORMANCE
            if(current*2+2<=max_heap)
            {
                // left+right
                if(heap[current*2+1]->freq<=heap[current*2+2]->freq)
                {
                    if(heap[current]->freq>heap[current*2+1]->freq)
                    {
                        swap_fun(current);
                        heap_sort(current-1);
                    }
                    else
                        heap_sort(current-1);
                }
                else
                {
                    if(heap[current]->freq>heap[current*2+2]->freq)
                    {
                            node *temp=heap[current];
                            heap[current]=heap[current*2+2];
                            heap[current*2+2]=temp;

                            heap_sort(current-1);
                    }
                    else
                        heap_sort(current-1);

                }

            }
            else
            {  //left
                if(heap[current*2+1]->freq<heap[current]->freq)
                {
                    swap_fun(current);
                    heap_sort(current-1);
                }
            }

        }
        else
        {
            heap_sort(current-1);
        }
    }
}

void swap_fun(int current)
{
    node *temp=heap[current];
    heap[current]=heap[current*2+1];
    heap[current*2+1]=temp;
}

node * delete_from_heap()
{
    node *d=heap[0];
    heap[0]=heap[max_heap];
    heap[max_heap]=NULL;

    max_heap=max_heap-1;
    int current=0;

    delete_heap(current);

    return d;
}

void delete_heap(int current)
{
    if(current<=max_heap)
    {
        if(current*2+1<=max_heap)
        {
            // OPERATION PERFORMANCE
            if(current*2+2<=max_heap)
            {
                // left+right
                if(heap[current*2+1]->freq<heap[current*2+2]->freq)
                {
                    if(heap[current]->freq>heap[current*2+1]->freq)
                    {
                        swap_fun(current);
                        heap_sort(current*2+1);
                    }

                }
                else
                {
                    if(heap[current]->freq>heap[current*2+2]->freq)
                    {
                            node *temp=heap[current];
                            heap[current]=heap[current*2+2];
                            heap[current*2+2]=temp;

                            heap_sort(current*2+2);
                    }

                }
            }
            else
            {  //left
                if(heap[current*2+1]->freq<heap[current]->freq)
                {
                    swap_fun(current);
                    heap_sort(current*2+1);
                }
            }
        }
    }
    else
    {}
}

void display(node *head)
{
    if(head->ch=='0')
    {
        if(head->left!=NULL)
        {
            x=x+1;

            c.binary[x]=0;
            display(head->left);
            x=x-1;
            if(head->right!=NULL)
            {
                x=x+1;
                c.binary[x]=1;
                display(head->right);
                x=x-1;
            }
        }
    }
    else
    {
        for(int i=0;i<8;i++)
        {
            if(c.binary[i]==0 || c.binary[i]==1)
                {
                    printf("%d",c.binary[i]);
                    c.sequence[m][i]=c.binary[i];
                }
            else
                break;
        }
        printf(" : character=%c\n",head->ch);
        c.ch[m]=head->ch;

        m=m+1;
    }
}

void print_sequence(char str[])
{
    int p=0;
    while(str[p]!='\0')
    {
        FILE *fp;
        char character=str[p];

        for(int i=0;i<MAX;i++)
        {
            if(c.ch[i]==character)
            {
                int ascii=0;
                for(int j=0;j<8;j++)
               {
                    if(c.sequence[i][j]==0 || c.sequence[i][j]==1)
                    {
                        printf("%d",c.sequence[i][j]);
                        ascii=ascii+(c.sequence[i][j]*pow(2,j));
                    }
                    else
                        break;
                }printf("%c \n",ascii);
                break;
            }
        }

        p=p+1;

    }
}

int main()
{

        printf("******************************* L-cent ************************************** \n");
        int choice;
        printf("1. STRING \n2. EXIT \n");
        scanf("%d",&choice);
        getchar();
        char str[1000];

        if(choice==1)
        {
            printf("Enter string:");
            fgets(str,1000,stdin);
            int length=0;
            while(str[length]!='\0')
            {
                length=length+1;
            }
            table_generation(str,length);
        }
        else
        {

        }
    return 0;
}
