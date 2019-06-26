#include<cstdio>
 
#include<iostream>
 
using namespace std;
 
int DisjoinSet[1000000];
 
int visit[1000000];
 
int mat[1000][1000];
 
int note[1000000][2];
 
int dir[1000000][4];
 
int n,N;
 
void init()
 
{
 
	int idx=1;
 
	for(int i=1;i<=n;i++)
 
		for(int j=1;j<=i;j++)
 
		{
 
			mat[i][j]=idx;
 
			DisjoinSet[idx]=idx;
 
			note[idx][0]=i;note[idx++][1]=j;
 
		}
 
	N=idx-1;
 
}
 
int find(int x)
 
{
 
	if(x>N||x<1) return -1;
 
	if(DisjoinSet[x]==x)
 
		return x;
 
	else
 
		return DisjoinSet[x]=find(DisjoinSet[x]);
 
}
 
int find2(int x)
 
{
 
	if(x>N||x<1) return -1;
 
	int stack[1000];
 
	int top=0;
 
	while(DisjoinSet[x]!=x)
 
	{
 
		stack[top++]=x;
 
		x=DisjoinSet[x];
 
	}
 
	for(int i=0;i<top;i++)
 
		DisjoinSet[stack[i]]=x;
 
	return x;
 
}
 
void join(int r1,int r2,int t)
 
{
 
	dir[r2][t]=1;
 
	r1=find(r1);
 
	r2=find(r2);
 
	if(r2>N||r2<1) return;
 
	DisjoinSet[r2]=DisjoinSet[r1];
 
}
 
bool f=false;
 
int path[100000];
 
int dy[4]={-1,0,0,1};
 
int dx[4]={-1,-1,1,1};
 
void dfs(int pos,int dst,int step,bool &flag)
 
{
 
	if(flag) return;
 
	if(pos==dst) 
 
	{
 
		path[step++]=pos;
 
		for(int i=0;i<step;i++)
 
			printf("%d ", path[i]);
 
		flag=true;
 
		return;
 
	}
 
	visit[pos]=1;
 
	path[step++]=pos;
 
	int temp;
 
	for(int i=0;i<4;i++)
 
	{
 
		if(!dir[pos][i]) continue;
 
		temp=mat[note[pos][0]+dx[i]][note[pos][1]+dy[i]];
 
		if(temp&&!visit[temp]&&find(temp)==find(dst))
 
		{
 
			dfs(temp,dst,step,flag);
 
		}
 
	}
 
	visit[pos]=0;
 
	step--;
 
}
 
int main()
 
{
 
	//freopen("1232.in","r",stdin);
 
	int a,b,x,y;
 
	scanf("%d%d%d",&n,&a,&b);
 
	init();
 
	do{
 
		//cout<<find(a)<<" "<<find(b);
 
		scanf("%d%d",&x,&y);
 
		dir[x][y]=1;
 
		switch(y)
 
		{
 
			case 0: if(note[x][1]>1&&note[x][0]>1) join(x,mat[note[x][0]-1][note[x][1]-1],3);break;
 
			case 1: if(note[x][0]>1) join(x,mat[note[x][0]-1][note[x][1]],2); break;
 
			case 2: if(note[x][0]<n) join(x,mat[note[x][0]+1][note[x][1]],1); break;
 
			case 3: if(note[x][0]<n) join(x,mat[note[x][0]+1][note[x][1]+1],0); break;
 
		}
 
	}while(find(a)!=find(b));
 
	dfs(a,b,0,f);
 
	return 0;
 
}
