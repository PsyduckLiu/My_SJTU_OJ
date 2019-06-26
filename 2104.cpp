#include<iostream>
 
#include<queue>
 
using namespace std;
 
struct st
 
{
 
   int x,y,c=0;
 
};
 
queue<st> xz;
 
int dir[4][2]={-1,0,1,0,0,-1,0,1};
 
int mg[1005][1005];
 
int bfs(st s,st e)
 
{
 
    st t;
    int i;
    xz.push(s);
    mg[s.x][s.y]=1;
    while (!xz.empty())
        {
        s=xz.front();
        xz.pop();
 
        if (s.x==e.x&&s.y==e.y)
 
            return s.c;
 
        for (i=0; i<4; i++)
 
        {
 
            t.x=s.x+dir[i][0];
 
            t.y=s.y+dir[i][1];
 
            if (t.x<0||t.x>1000||t.y<0||t.y>1000||mg[t.x][t.y])
 
                continue;
 
            t.c=s.c+1;
 
            mg[t.x][t.y]=1;
 
            xz.push(t);
 
        }
 
    }
 
};
 
int main()
 
{
    int n;
    int a,b;
    st s,e;
 
    s.x=500;
    s.y=500;
    cin>>e.x>>e.y>>n;
 
    e.x+=500;
    e.y+=500;
 
    while (n!=0) {
        cin>>a>>b;
        mg[500+a][500+b]=1;
        n--;
    }
    cout<<bfs(s,e)<<endl;
 
    return 0;
 
}
