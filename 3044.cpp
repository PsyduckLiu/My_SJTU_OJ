#include <iostream>
 
using namespace std;
long long int mod=1000000007;
int main()
{
    int n;
    int a[1001]={1};
    int i=2,j,k;
    cin>>n;
 
    for (k=0; k<1001; k++) a[k]=1;
 
    for (i=2; i<=n; i++)
    {
        if (i%2==0)
        {
 
            for(j=1; j<=i/2; j++)
                {
                a[i]=a[i]+a[j];
                if (a[i]>mod) a[i]=a[i]%mod;}
        }
 
 
        if (i%2==1)
            a[i]=a[i-1];
    }
 
    cout<<a[n];
 
 
 
    return 0;
}
