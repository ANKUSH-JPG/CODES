#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int calculate(int n,int o,int rq,int cq,int obstacles[][2])
{
     int result=0;
     int north=n-rq;
     int east=n-cq;
     int south=rq-1;
     int west=cq-1;

     int north_west=0,north_east=0,south_east=0,south_west=0;

     if(north==0 || west==0)
          north_west=0;
     else
     {
         if(north<west)
            north_west=north;
         else
            north_west=west;
     }


     if(north==0 || east==0)
          north_east=0;
     else
     {
         if(north<east)
            north_east=north;
         else
            north_east=east;
     }

     if(south==0 || east==0)
          south_east=0;
     else
     {
         if(south<east)
            south_east=south;
         else
            south_east=east;
     }

     if(south==0 || west==0)
          south_west=0;
     else
     {
         if(south<west)
            south_west=south;
         else
            south_west=west;
     }

     result=north+east+south+west+north_west+north_east+south_east+south_west;


     for(int i=0;i<o;i++)
     {
         if( ( abs(rq-obstacles[i][0])==abs(cq-obstacles[i][1]) ) || rq-obstacles[i][0]==0 || cq-obstacles[i][1]==0 )
         {
             if(rq-obstacles[i][0]==0)
             {
                 if(cq-obstacles[i][1]>0)
                     result=result-obstacles[i][1];
                 else
                    result=result-(n-obstacles[i][1]+1);
             }
             else if(cq-obstacles[i][1]==0)
             {
                 if(rq-obstacles[i][0]>0)
                     result=result-obstacles[i][0];
                 else
                    result=result-(n-obstacles[i][0]+1);
             }
             else
             {
                 if((obstacles[i][0]-rq>0 && obstacles[i][1]-cq>0))
                 {
                     int R=n-obstacles[i][0];
                     int C=n-obstacles[i][1];
                     if(R==0 || C==0)
                        result=result-1;
                     else if(R<C)
                        result=result-(R+1);
                     else
                        result=result-(C+1);
                 }
                 else if((obstacles[i][0]-rq>0 && obstacles[i][1]-cq<0))
                 {
                     int R=n-obstacles[i][0];
                     int C=obstacles[i][1]-1;
                     if(R==0 || C==0)
                        result=result-1;
                     else if(R<C)
                        result=result-(R+1);
                     else
                        result=result-(C+1);
                 }
                 else if((obstacles[i][0]-rq<0 && obstacles[i][1]-cq<0))
                 {
                     int R=obstacles[i][0]-1;
                     int C=obstacles[i][1]-1;
                     if(R==0 || C==0)
                        result=result-1;
                     else if(R<C)
                        result=result-(R+1);
                     else
                        result=result-(C+1);
                 }
                 else if((obstacles[i][0]-rq<0 && obstacles[i][1]-cq>0))
                 {
                     int R=obstacles[i][0]-1;
                     int C=n-obstacles[i][1];
                     if(R==0 || C==0)
                        result=result-1;
                     else if(R<C)
                        result=result-(R+1);
                     else
                        result=result-(C+1);
                 }
             }
         }
     }


     return result;
}

int main()
{
    int n,o,rq,cq;
    cin>>n>>o>>rq>>cq;

    int obstacles[o][2];

    for(int i=0;i<o;i++)
    {
        cin>>obstacles[i][0]>>obstacles[i][1];
    }

    int moves=calculate(n,o,rq,cq,obstacles);

    cout<<moves;
    return 0;
}
