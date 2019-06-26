#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int cmp (int x,int y)
{
    if (x<y) return 1;
    else return 0;
}
int main()
{
    int n,m;
    int l,r,x;
    int p[10001],q[10001];
    int i,tmp;
 
    cin>>n>>m;
    for (i=1;i<=n;i++) {
            cin>>p[i];
            q[i]=p[i];
    }
 
    while (m) {
        scanf("%d%d%d",&l,&r,&x);
        sort(q+l,q+r+1,cmp);
 
        if (p[x]==q[x]) printf("%s", "Yes\n");
        else printf("%s", "No\n");
        m--;
        for (i=1;i<=n;i++) q[i]=p[i];
 
    }
    return 0;
}
