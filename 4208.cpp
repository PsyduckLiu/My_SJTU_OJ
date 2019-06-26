#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    int a,b,x1,y1,x2,y2;
    int n,i,p1,m1,p2,m2,block1,block2,block3,block4,d1,d2;
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%d%d%d%d%d%d",&a,&b,&x1,&y1,&x2,&y2);
        a*=2;
        b*=2;
        p1=x1+y1;
        m1=x1-y1;
        p2=x2+y2;
        m2=x2-y2;
        if (p1>0) block1=p1/a;
        else block1=-(-p1/a)-1;
        if (m1>0) block2=m1/b;
        else block2=-(-m1/b)-1;
        if (p2>0) block3=p2/a;
        else block3=-(-p2/a)-1;
        if (m2>0) block4=m2/b;
        else block4=-(-m2/b)-1;
        d1=max(block1-block3,block3-block1);
        d2=max(block2-block4,block4-block2);
        printf("%d\n",max(d1,d2));
    }
    return 0;
}
