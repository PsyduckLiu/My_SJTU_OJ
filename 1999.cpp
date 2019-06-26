#include<cstdio>
 
#include<iostream>
 
using namespace std;
 
#define y second
 
#define x first
 
typedef pair<int,int> Pnt;
 
const int MAXS=10000000;
 
Pnt queque[100000];
 
int maze[102][102];
 
int visit[102][102];
 
int n,m,cnt=0;
 
void init()
 
{
 
	for(int i=1;i<=n;i++)
 
		for(int j=1;j<=m;j++)
 
			visit[i][j]=0;
 
}
 
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
 
int step=MAXS;
 
int bfs(int si,int sj,int ei,int ej)
 
{
 
	//cout<<si<<" "<<sj<<" "<<cnt<<'\n';
 
	int ss=0;
 
	int head=0,tail=0;
 
	init();
 
	visit[si][sj]=1;
 
	queque[tail++]=Pnt(si,sj);
 
	int pretail=tail;
 
	while(head!=tail)
 
	{
 
		Pnt p=queque[head++];
 
		for(int i=0;i<4;i++)
 
		{
 
			int ti=p.x+dx[i],tj=p.y+dy[i];
 
			if(ti==ei&&tj==ej)
 
				return ss+1;
 
			if(visit[ti][tj]==0&&maze[ti][tj]==0)
 
			{
 
				visit[ti][tj]=1;
 
				queque[tail++]=Pnt(ti,tj);
 
			}
 
		}
 
		if(head==pretail)
 
		{
 
			ss++;
 
			pretail=tail;
 
		}
 
	}
 
	return MAXS;
 
}
 
 
 
int note[6][6];
 
Pnt box[6];
 
int sel[6];
 
void findpath(int s,int ss,int idx)
 
{
 
	if(ss>step) return;
 
	if(!idx)
 
		{step=ss;return;}
 
	for(int i=1;i<=cnt;i++)
 
	{
 
		if(!sel[i]&&note[s][i]!=MAXS)
 
		{
 
			sel[i]=1;
 
			findpath(i,ss+note[s][i],idx-1);
 
			sel[i]=0;
 
		}
 
	}	
 
}
 
int main()
 
{
 
 
	int si,sj;
 
	scanf("%d%d",&n,&m);
 
	for(int i=0;i<=n+1;i++)
 
		for(int j=0;j<=m+1;j++)
 
		{
 
			if(i==0||j==0||i==n+1||j==m+1)
 
				{maze[i][j]=-1;continue;}
 
			scanf("%d",&maze[i][j]);
 
			if(maze[i][j]==2)
 
				{si=i;sj=j;maze[i][j]=0;box[0]=Pnt(i,j);}
 
			if(maze[i][j]==1)
 
				box[++cnt]=Pnt(i,j);
 
		}
 
	for(int i=0;i<=cnt;i++)
 
	{
 
		for(int j=i+1;j<=cnt;j++)
 
		{
 
			int temp=bfs(box[i].x,box[i].y,box[j].x,box[j].y);
 
			note[i][j]=note[j][i]=temp;
 
		}
 
	}
 
	findpath(0,0,cnt);
 
	if(step==MAXS) printf("-1\n");
 
	else printf("%d\n", step);
 
}
