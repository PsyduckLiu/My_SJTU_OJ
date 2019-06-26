#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
 
using namespace std;
 
struct position
{
    int x,y;
};
 
struct node
{
    int x,y,sum=0;
};
 
int barrier[35][35];
int M1,M2;
 
int vis[35][35];
int m,n,srow,scol,erow,ecol,a,b,ans,flag;
queue<node>que;
 
int  in(int a,int b){
    if(a>0&&a<=m&&b>0&&b<=n)  return 1;
    return 0;
}
 
int BFS()
{
    int col,row;
    position dir[8]={{-M1,-M2},{-M1,M2},{M1,M2},{M1,-M2},{M2,M1},{M2,-M1},{-M2,M1},{-M2,-M1}};
    ans=0;
    node t,m;
    t.x=srow; t.y=scol; t.sum=ans;
    que.push(t);
    vis[srow][scol]=1;
    while(!que.empty())
    {
        t=que.front();
        que.pop();
        row=t.x;
        col=t.y;
        if(col==ecol&&row==erow)
          {
              ans=t.sum;
              return ans;
          }
        for(int i=0;i<8;i++)
        {
        if(in(t.x+dir[i].x, t.y+dir[i].y)==1&&vis[t.x+dir[i].x][t.y+dir[i].y]==0&&barrier[t.x+dir[i].x][t.y+dir[i].y]==1){
                m.x=t.x+dir[i].x;
                m.y=t.y+dir[i].y;
                m.sum=t.sum+1;
                que.push(m);
                vis[t.x+dir[i].x][t.y+dir[i].y]=1;
            }
           }
        }
    }
 
int main()
{
      int i,j;
      cin>>m>>n>>M1>>M2;
 
      for(i=1;i<=m;i++) {
      for (j=1;j<=n;j++) {
            cin>>barrier[i][j];
            if (barrier[i][j]==2) barrier[i][j]=0;
            if (barrier[i][j]==3) {
                srow=i;
                scol=j;
                barrier[i][j]=1;
            }
            if (barrier[i][j]==4) {
                erow=i;
                ecol=j;
                barrier[i][j]=1;
            }
        }
      }
 
    BFS();
    cout<<ans;
    return 0;
 
    }
