#include <iostream>
 
using namespace std;
 
const int maxn=505;
int n,m;
bool visit[maxn][maxn];
int a[maxn][maxn];
int X[4]={1,-1,0,0},Y[4]={0,0,-1,1};
 
struct node
{
    int x,y;
}Node;
 
class queue
{
    private:
    node map[50005];
    int num=0;
 
    public:
        bool empty() {
           return num==0;
        };
 
        void push(node &rhs) {
            num++;
            map[num].x=rhs.x;
            map[num].y=rhs.y;
        };
 
        void pop() {num--;};
 
        node front() {
         return map[num];
        };
} ;
bool check(int x,int y)
{
    if(x>=n||y>=m||x<0||y<0) return false;
    if(a[x][y]==-1||visit[x][y]==true) return false;
    return true;
}
void bfs(int x,int y)
{
    queue q;
    Node.x=x,Node.y=y;
    visit[x][y]=true;
    q.push(Node);
    while(!q.empty())
    {
        node top=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int newX=top.x+X[i],newY=top.y+Y[i];
            if(check(newX,newY))
            {
                Node.x=newX,Node.y=newY;
                q.push(Node);
                visit[newX][newY]=true;
            }
        }
    }
}
 
int main()
{
    int cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0&&visit[i][j]==false)
            {
                cnt++;
                bfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;
}
