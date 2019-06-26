#include <iostream>
#include <cstdio>
using namespace std;
int Map[1005][1005];
int cost[1005][1005];
int dis[1005];
int sp[1005];
int s,e;
int que[1000007];
int head=0;
int rear=0;
void enque(int s)
{
que[rear++]=s;
}
int pop()
{
head++;
return que[head-1];
}
int main()
{
int n,m,i,j;
scanf("%d%d",&n,&m);
for (i=1;i<=n;++i)
for(j=1;j<=n;++j)
cost[i][j]=Map[i][j]=1000000000;
for (i=1;i<=n;++i) sp[i]=dis[i]=1000000000;
for (i=1;i<=m;++i)
{
int a,b,d,p;
scanf("%d%d%d%d",&a,&b,&d,&p);
if (Map[a][b]>d)
{Map[a][b]=Map[b][a]=d;cost[a][b]=cost[b][a]=p;}
else if (Map[a][b]==d&&cost[a][b]>p)
cost[a][b]=cost[b][a]=p;
}
scanf("%d%d",&s,&e);
enque(s);
dis[s]=sp[s]=0;
while (head!=rear)
{
int tmp=pop();
for(i=1;i<=n;++i)
{
if (dis[tmp]+Map[tmp][i]<dis[i]||dis[tmp]+Map[tmp][i]==dis[i]&&sp[tmp]+cost[tmp][i]<sp[i])
{
sp[i]=sp[tmp]+cost[tmp][i];
dis[i]=dis[tmp]+Map[tmp][i];
enque(i);
}
}
}
printf("%d %d",dis[e],sp[e]);
return 0;
}
