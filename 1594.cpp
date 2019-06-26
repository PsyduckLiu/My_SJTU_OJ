#include <stdio.h>
#include <iostream>
 
int main()
{
    int n,m,q,i,j,**arr;
    long long **a;
    int x1,y1,x2,y2;
    long long ans=0;
    scanf("%d %d %d",&n,&m,&q);
    arr=new int *[n+1];
    for(i=0;i<=n;i++)
    {
        arr[i]=new int [m+1];
    }
    a=new long long int *[n+1];
    for(i=0;i<=n;i++)
    {
        a[i]=new long long int [m];
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&arr[i][j]);
 
    a[1][1]=arr[1][1],a[1][0]=a[0][1]=a[0][0]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(i==1&&j==1)
                continue;
            else if(i==1&&j!=1)
                a[i][j]=a[i][j-1]+arr[i][j];
            else if(j==1&&i!=1)
                a[i][j]=a[i-1][j]+arr[i][j];
            else
                a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+arr[i][j];
        }
    }
    while(q--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1==1&&y1==1)
            ans=(long long)a[x2][y2];
        else if(x1==1&&y1!=1)
            ans=(long long)a[x2][y2]-a[x2][y1-1];
        else if(y1==1&&x1!=1)
            ans=(long long)a[x2][y2]-a[x1-1][y2];
        else
            ans=(long long)a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
        printf("%lld\n",ans);
    }
    return 0;
}
