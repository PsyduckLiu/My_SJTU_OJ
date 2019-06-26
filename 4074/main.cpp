
#include<cstdio>
#include<iostream>
#define inf 0x7fffffff;
using namespace std;

struct Data
{
    int x,y,v;
};
Data pri[1000000];
int cur=0;
void Push(Data x)
{
     int hole=++cur;
    for (;hole>1&&x.v<pri[hole/2].v;hole/=2)
        pri[hole]=pri[hole/2];
    pri[hole]=x;

}
void percolatedown(int hole)
{
    int child;
    Data tmp=pri[hole];
    for (;hole*2<=cur;hole=child)
    {
        child=hole*2;
        if (child!=cur&&pri[child+1].v<pri[child].v)
            ++child;
        if (pri[child].v<tmp.v) pri[hole]=pri[child];
        else break;
    }
    pri[hole]=tmp;
}
Data Pop()
{
    Data tmp;
    tmp=pri[1];
    pri[1]=pri[cur--];
    percolatedown(1);
    return tmp;
}

int u[4]= {1,0,-1,0},v[4]= {0,1,0,-1};
int minn,minx,miny;
int n,m,ss;
int map[107][107],ans=0;
bool pd[107][107];

void Pre()
{
    int i,j;
    Data in;
    for(i=1; i<=n; i++)
    {
        in.x=i;
        in.y=0;
        in.v=map[i][0];
        pd[i][0]=1;
        Push(in);
        in.x=i;
        in.y=m;
        in.v=map[i][m];
        pd[i][m]=1;
        Push(in);
    }
    for(j=2; j<m; j++)
    {
        in.x=0;
        in.y=j;
        in.v=map[0][j];
        pd[0][j]=1;
        Push(in);
        in.x=n;
        in.y=j;
        in.v=map[n][j];
        pd[n][j]=1;
        Push(in);
    }
}

bool inmap(Data a)
{
    return a.x<=n&&a.x>=1&&a.y>=1&&a.y<=m;
}

void Fill(Data z,int h)
{
    int i,xx=z.x,yy=z.y;
    pd[xx][yy]=1;
    if(z.v>=h)
    {
        Push(z);
        return;
    }
    ans+=h-map[xx][yy];
    for(i=0; i<4; i++)
    {
        Data t;
        t.x=xx+u[i];
        t.y=yy+v[i];
        t.v=map[t.x][t.y];
        if(!pd[t.x][t.y])
        {
            Fill(t,h);
        }
    }
}

void solve()
{
    int i;
    Data temp;
    while(cur!=0)
    {

        temp=Pop();

        for(i=0; i<4; i++)
        {
            Data t;
            t.x=temp.x+u[i];
            t.y=temp.y+v[i];
            t.v=map[t.x][t.y];
            if(inmap(t) && !pd[t.x][t.y])
            {
                Fill(t,temp.v);
            }


     }
    }
}


int main()
{

    minn=inf;
    scanf("%d%d",&n,&m);
    int i,j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]<minn)
                minn=map[i][j],minx=i,miny=j;
        }
    }
    Pre();
    solve();
    printf("%d",ans);
    return 0;
}
