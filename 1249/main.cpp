#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    int a,b;
    double s;
}f[500000];

int gcd(int x,int y)
{
    if(x%y==0) return y;
    return gcd(y,x%y);
}

bool cmp(node a,node b)
{
    return a.s<b.s;
}

int n,lens=1;
int main()
{
    scanf("%d",&n);
    f[lens].a=0,f[lens].b=1,f[lens].s=0.0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            if(gcd(i,j)==1)
            {
                lens++;
                f[lens].a=j;
                f[lens].b=i;
                f[lens].s=j*1.0/i;
            }
    sort(f+1,f+lens+1,cmp);
    for(int i=1;i<=lens;++i)
    {
        printf("%d/%d\n",f[i].a,f[i].b);
    }
    cout<<lens;
    return 0;
}
