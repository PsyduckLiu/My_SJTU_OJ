#include<cstdio>
 
#include<iostream>
 
using namespace std;
 
int n,r,N;
 
struct Mouse
 
{
 
	int id;
 
	int score,pow;
 
	void init(int i,int s,int p)
 
	{
 
		id=i;score=s;pow=p;
 
	}
 
	bool operator<(Mouse &other)
 
	{
 
		if(score<other.score||(score==other.score&&id>other.id))
 
			return 1;
 
		else return 0;
 
	}
 
	bool operator>(Mouse &other)
 
	{
 
		if(score>other.score||(score==other.score&&id<other.id))
 
			return 1;
 
		else return 0;
 
	}
 
}Mice[200010];
 
int partition(int s,int e)
 
{
 
	Mouse temp=Mice[s];
 
	int i=s,j=s+1;
 
	for(;j<=e;j++)
 
	{
 
		if(Mice[j]>temp)
 
		{
 
			Mouse t=Mice[j];
 
			Mice[j]=Mice[++i];
 
			Mice[i]=t;
 
		}
 
	}
 
	Mice[s]=Mice[i];
 
	Mice[i]=temp;
 
	return i;
 
}
 
void quicksort(int s,int e)
 
{
 
	if(s>=e) return;
 
	int mid=partition(s,e);
 
	quicksort(s,mid-1);
 
	quicksort(mid+1,e);
 
}
 
void pushup(int pos)
 
{
 
	int i=pos-1;
 
	while(i&&Mice[i]<Mice[pos])
 
	{
 
		Mouse temp=Mice[pos];
 
		Mice[pos]=Mice[i];
 
		Mice[i]=temp;
 
		pos=i;
 
		i--;
 
	}
 
}
 
void contest()
 
{
 
	int a,b;
 
	for(int i=1;i<=n;i++)
 
	{
 
		a=i*2-1;b=i*2;
 
		if(Mice[a].pow>Mice[b].pow){Mice[a].score+=2;pushup(a);}
 
		else if(Mice[a].pow<Mice[b].pow){Mice[b].score+=2;pushup(b);}
 
		else{Mice[a].score+=1;Mice[b].score+=1;pushup(a);pushup(b);}
 
	}
 
}
 
void contest2()
 
{
 
	int a,b;
 
	for(int i=1;i<=n;i++)
 
	{
 
		a=i*2-1;b=i*2;
 
		if(Mice[a].pow>Mice[b].pow){Mice[a].score+=2;}
 
		else if(Mice[a].pow<Mice[b].pow){Mice[b].score+=2;}
 
		else{Mice[a].score+=1;Mice[b].score+=1;}
 
	}
 
}
 
void bubble()
 
{
 
	Mouse temp;
 
	bool flag;
 
	for(int i=2;i<=N;i++)
 
	{
 
		flag=0;
 
		for(int j=1;j<=N+1-i;j++)
 
			if(Mice[j+1]>Mice[j])
 
			{
 
				Mouse temp=Mice[j+1];
 
				Mice[j+1]=Mice[j];
 
				Mice[j]=temp;
 
				flag=1;
 
			}
 
		if(!flag) break;
 
	}
 
}
 
int main()
 
{
 
	scanf("%d%d",&n,&r);
 
	N=2*n;
 
	for(int i=1;i<=N;i++)
 
	{
 
		Mice[i].id=i;
 
		scanf("%d",&Mice[i].score);
 
	}
 
	for(int i=1;i<=N;i++)
 
		scanf("%d",&Mice[i].pow);
 
	quicksort(1,N);
 
	for(int i=0;i<r;i++) {contest2(); bubble();}
 
	for(int i=1;i<=N;i++)
 
		printf("%d ", Mice[i].id);
 
 
 
 
 
 
}
