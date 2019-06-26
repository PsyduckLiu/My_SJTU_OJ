#include <iostream>
#include <cstdio>
using namespace std;
 
bool gai(int x,int y);
bool pa[1000][1000];
int N;
 
struct site
{
    int x;
    int y;
};
 
site map[1000000];
int m,n,p,q;
int main()
{
    int i,k,j,t,flag;
    bool flag1;
    scanf("%d",&t);
    for (k=0;k<t;++k)
    {
    scanf("%d%d%d%d",&m,&n,&p,&q);
    N=0;
    flag1=false;
    for (i=0;i<m;++i)
        for (j=0;j<n;++j)
            scanf("%d",&pa[i][j]);
 
    for (i=0;i<p;++i)
        for (j=0;j<q;++j)
            {scanf("%d",&flag);
             if (flag==1) {map[N].x=i;map[N].y=j;++N;}
             }
 
    for (i=1;i<N;++i) {map[i].x-=map[0].x;map[i].y-=map[0].y;}
    map[0].x=map[0].y=0;
     for (i=0;i<m;++i)
        {
 
         for (j=0;j<n;++j)
         {
             if (pa[i][j])
             {
                 if (gai(i,j)) continue;
                 else {printf("%s\n","No");flag1=true;break;}
             }
         }
         if (flag1) {break;}
        }
        if (flag1) continue;
    for (i=0;i<m;++i)
        {for (j=0;j<n;++j)
        if (pa[i][j]) {printf("%s\n","No");flag1=true;break;}
        if (flag1) break;
        }
    if (!flag1) printf("%s\n","Yes");
 
    }
    return 0;
}
bool gai(int x,int y)
{
    int i,tmp1,tmp2;
    pa[x][y]=false;
    for (i=1;i<N;++i)
    {
        tmp1=x+map[i].x;
        tmp2=y+map[i].y;
        if (tmp1>=m||tmp1<0||tmp2>=n||tmp2<0||!pa[tmp1][tmp2]) return false;
        else {pa[tmp1][tmp2]=false;}
    }
    return true;
}
