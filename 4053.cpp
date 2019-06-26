#include <iostream>
#include <cmath>
using namespace std;
int a[33],b[33],num=0;
int n;
bool zs(int x,int y)
{
    int ans=x+y;
    for(int i=2;i<=sqrt(ans);i++)
    {
        if(ans%i==0)
            return 0;
    }
    return 1;
}
 
void dfs(int k)
{
    for(int i=2;i<=n;i++)
    {
        if(zs(a[k-1],i)==1&&b[i]==0)
        {
            b[i]=1;
            a[k]=i;
            if(k==n&&zs(a[k],a[1])==1)
            {
                num++;
                for (int j=1;j<=n;j++) cout<<a[j]<<' ';
                cout<<'\n';
            }
            else dfs(k+1);
            b[i]=0;
        }
 
    }
 
}
 
int main () {
 
 
 
   cin>>n;
   if (n%2==1) cout<<"None";
   else {
       a[1]=1;
       dfs(2);
    }
return 0;
}
