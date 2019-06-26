#include<iostream>
#include <cstdio>
using namespace std;
 
int  pre[200005];
int  t[200005];
 
int find(int x)
{
	int r=x;
	while(r!=pre[r])
	r=pre[r];
	int i=x,j;
	while(pre[i]!=r)
	{
	    j=pre[i];
		pre[i]=r;
		i=j;
}
	return r;
}
 
void mix(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		pre[fy]=fx;
	}
}
 
int main()
{
	int n,m,a,b,i,j,ans,op;
	cin>>n>>m;
 
	for(i=1;i<=n;i++) {
	    pre[i]=i;
        t[i]=0;
    }
 
    while (m!=0)
	{
	    cin>>op;
	    if (op==1) {
			cin>>a>>b;
			mix(a,b);
        }
 
 
        if (op==3) {
            cin>>a;
            t[a]=1;
        }
 
        if (op==2) {
            cin>>a>>b;
            i=find(a);
            j=find(b);
            if (i==j&&t[a]!=1&&t[b]!=1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    m--;
	}
 
 
 
	return 0;
 
}
