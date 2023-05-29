//30/04/2022
#include<iostream>
using namespace std;
class prim
{
 public:
 int visited[6];
int arr[6][6];
   prim()
	{
         for(int i=1;i<=6;i++){
          for(int j=1;j<=6;j++)
           {arr[i][j]=999;}
           }
       for(int i=1;i<=6;i++)
          { visited[i]=0;}
      }


   void create();
   void display();
   void mst(int);
};
void prim::create()
{
 for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++)
        {
              if(arr[i][j]==999 && i!=j)
          {
           cout<<"Enter the value for"<<i<<"*"<<j<<":";
           cin>>arr[i][j];
           arr[j][i]=arr[i][j];
         }
        }
   }
}
void prim::display()
{
cout<<"\t1\t"<<"2\t"<<"3\t"<<"4\t"<<"5\t"<<"6\t"<<endl;
for(int i=1;i<=6;i++)
    {  cout<<i;
        for(int j=1;j<=6;j++)
        {
          cout<<"\t"<<arr[i][j];
        }
    cout<<endl;
    }
}

void prim::mst(int start)
{
int min=999;
int u,v;
int n=6;
 int count=1;
 int opcost=0;
 visited[start]=1;
cout<<"\n start vertes is="<<start;
while(count<n)
{
  min=999;
 for(int i=1;i<=6;i++)
  {
  if(visited[i]==1)
     {
       for(int j=1;j<=6;j++)
       {
        if(visited[j]==0)
         {

          if(min>arr[i][j])
          {
           min=arr[i][j];
              v=j;u=i;

          }
         }
       }
     }
  }
  opcost=opcost+min;

  visited[v]=1;
  count++;
  cout<<"edge "<<u<<" "<<v<<endl;

}
cout<<"optcost"<<opcost<<endl;
}

int main()
{
int s;
prim p;
p.create();
p.display();
cout<<"Enter the starting vertex"<<endl;
cin>>s;
p.mst(s);
cout<<"done"<<endl;
}

