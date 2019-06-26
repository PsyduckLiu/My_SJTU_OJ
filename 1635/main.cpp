#include<cstdio>
#include<iostream>

using namespace std;

int n,m;
const int MAXS=100000000;

struct edge
{
	int end,val;
	edge *next;
	edge(int a,int v,edge *p):end(a),val(v),next(p){}
};

struct ver
{
	edge* head;
	ver(){head=NULL;}
}vers[1000010];

void add(int a,int b,int v)
{
	edge *p=vers[a].head;
	if(!p)
	{
		vers[a].head=new edge(b,v,NULL);
	}
	else
	{
		while(p&&p->end!=b)
			p=p->next;
		if(p&&p->val>v)
			p->val=v;
		else
			vers[a].head=new edge(b,v,vers[a].head);
	}
}

bool visit[1000010];
int ans=MAXS;
int path[2000010];
int pending[1000010][3],idx[3];
int step=0;

void bfs()
{
	int head=0,tail=0,pretail=1;
	path[tail++]=1;
	visit[1]=1;
	int temp;
	edge *p;
	while(head!=tail)
	{
		temp=path[head++];
		p=vers[temp].head;
		while(p)
		{
			if(!visit[p->end])
			{
				int k=(step+p->val-1)%3;
				pending[idx[k]++][k]=p->end;
			}
			p=p->next;
		}
		int j;
		for(j=0;head==pretail&&j<3;j++)
		{
			int k=(step+j)%3;
			for(int i=0;i<idx[k];i++)
			{
				if(!visit[pending[i][k]])
				{
					if(pending[i][k]==n) {step+=(1+j);return;}
					visit[pending[i][k]]=1;
					path[tail++]=pending[i][k];
				}
			}
			idx[k]=0;
			pretail=tail;
		}
		if(head!=pretail) step+=(j);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	bfs();
	printf("%d\n", step);

}
