#include<iostream>
 
using namespace std;
 
int cnt(long long int x)
{
    int ret=0;
    while (x)
    {
        if (x&1) ret++;
        x>>=1;
    }
    return ret;
}
int main()
{
    int i,j,k,n;
    long long int now,ans=0,x;
    cin>>now>>n;
    if (now>=n) {
    while (cnt(now)>n)
    {
        for (x=1;;x<<=1)
          if (now&x) break;
        ans+=x;
        now+=x;
    }
    }
    else ans=n-now;
    cout<<ans;
}
