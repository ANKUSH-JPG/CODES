#include<stdio.h>
#include<stdlib.h>

int main()

{

    char get_string[1000];

    scanf("%s",&get_string);
    int length=strlen(get_string);


    int countalphabet=0;

    int count[26];
    char alphabet[26];

    for(int i=0;i<26;i++)
    {
        count[i]=0;
        alphabet[i]='a';
    }

    for(int i=0;i<length;i++)
    {
        switch(get_string[i])
        {
        case 'a':
            count[0]=count[0]+1;
            alphabet[0]='a';
            break;
        case 'b':
            count[1]=count[1]+1;
            alphabet[1]='b';
            break;
        case 'c':
            count[2]=count[2]+1;
            alphabet[2]='c';
            break;
        case 'd':
            count[3]=count[3]+1;
            alphabet[3]='d';
            break;
        case 'e':
            count[4]=count[4]+1;
            alphabet[4]='e';
            break;
        case 'f':
            count[5]=count[5]+1;
            alphabet[5]='f';
            break;
        case 'g':
            count[6]=count[6]+1;
            alphabet[6]='g';
            break;
        case 'h':
            count[7]=count[7]+1;
            alphabet[7]='h';
            break;
        case 'i':
            count[8]=count[8]+1;
            alphabet[8]='i';
            break;
        case 'j':
            count[9]=count[9]+1;
            alphabet[9]='j';
            break;
        case 'k':
            count[10]=count[10]+1;
            alphabet[10]='k';
            break;
        case 'l':
            count[11]=count[11]+1;
            alphabet[11]='l';
            break;
        case 'm':
            count[12]=count[12]+1;
            alphabet[12]='m';
            break;
        case 'n':
            count[13]=count[13]+1;
            alphabet[13]='n';
            break;
        case 'o':
            count[14]=count[14]+1;
            alphabet[14]='o';
            break;
        case 'p':
            count[15]=count[15]+1;
            alphabet[15]='p';
            break;
        case 'q':
            count[16]=count[16]+1;
            alphabet[16]='q';
            break;
        case 'r':
            count[17]=count[17]+1;
            alphabet[17]='r';
            break;
        case 's':
            count[18]=count[18]+1;
            alphabet[18]='s';
            break;
        case 't':
            count[19]=count[19]+1;
            alphabet[19]='t';
            break;
        case 'u':
            count[20]=count[20]+1;
            alphabet[20]='u';
            break;
        case 'v':
            count[21]=count[21]+1;
            alphabet[21]='v';
            break;
        case 'w':
            count[22]=count[22]+1;
            alphabet[22]='w';
            break;
        case 'x':
            count[23]=count[23]+1;
            alphabet[23]="x";
            break;
        case 'y':
            count[24]=count[24]+1;
            alphabet[24]='y';
            break;
        case 'z':
            count[25]=count[25]+1;
            alphabet[25]='z';
            break;
        }
}

for(int i=0;i<26;i++)
{
    if(count[i]==0)
    {
        continue;
    }
    if(count[i]!=0)
    {
        countalphabet=countalphabet+1;
    }

}


int * final_array=(int *)malloc(countalphabet * sizeof(int));
char * final_alphabet=(char *)malloc(countalphabet * sizeof(char));

int i=0;
    for(int k=0;k<26;k++)
    {

      if(count[k]==0)
    {
        continue;
    }
    else
    {
        *(final_array+i)=count[k];
        *(final_alphabet+i)=alphabet[k];
        i=i+1;
    }
    }

int first_alphabet=*(final_array+0);
int result=0;
for(int i=1;i<countalphabet;i++)
{
    if(first_alphabet==*(final_array+i))
    {
        result=1;
        continue;
    }
    else
    {
        break;
    }

}

if(result==1)
    printf("YES");
else if(result==0)
    printf("NO");

return 0;
}
