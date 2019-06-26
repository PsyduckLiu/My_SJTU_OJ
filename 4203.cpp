#include <iostream>
#include <cmath>
 
using namespace std;
 
 
#define maxn 100000
 
const long long MOD=1000000007;
 
long long int fact[maxn+5];
long long int a[maxn+10];
 
long long int pow(long long int x)
{
    long long int n = MOD-2;
    long long int res=1;
    while(n>0)
    {
        if(n%2==1)
        res=res*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}
 
void init()
{
    a[0]=a[1]=1;
    fact[0]=fact[1]=1;
 
    for(int i=2;i<=100005;i++)
    {
        fact[i]=fact[i-1]*i%MOD;
        a[i]=a[i-1]*pow(i)%MOD;
    }
}
 
long long int C(int n,int m)
{
    if(n<0||m<0||n<m) return 0;
    return fact[n]*a[n-m]%MOD*a[m]%MOD;
}
 
int main()
{
    int t,i;
    int n[20000],m[20000];
    long long x;
    init();
    cin>>t;
 
    for(i=0; i<t; ++i) {
        cin>>n[i]>>m[i];
    }
 
    for(i=0; i<t; ++i) {
        x=C(n[i],m[i])%MOD;
        cout<<x<<'\n';
    }
 
    return 0;
}
