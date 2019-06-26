#include <iostream>
#include <cstdio>
using namespace std;
long long num[100005];
long long Left[50005];
long long Right[50005];
long long sum[100005];
void Merge(int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int i,j,k;
    for (i=0;i<n1;++i)
        Left[i]=sum[i+l];
    for (j=0;j<n2;++j)
        Right[j]=sum[j+m+1];
    i=j=0;
    for(k=l;k<=r;++k)
    {
        if (i==n1)
            {sum[k]=Right[j++];
            continue;}
        if (j==n2)
            {sum[k]=Left[i++];
            continue;}
        if (Left[i]<Right[j]) sum[k]=Left[i++];
        else sum[k]=Right[j++];
    }
}
void mergesort(int l,int r)
{
    if (l<r)
    {
        int m=(l+r)>>1;
        mergesort(l,m);
        mergesort(m+1,r);
        Merge(l,m,r);
    }
}
int main()
{
    int n;
    int cnt=1;
    int maxi=0;
    sum[0]=0;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
     scanf("%lld",&num[i]);
     sum[i]=sum[i-1]+num[i];
    }
 
    mergesort(1,n);
 
    for (int i=1;i<n;++i)
    {
        while (i<n&&sum[i]==sum[i+1])
        {
            ++cnt;
            ++i;
        }
        if (cnt>maxi) maxi=cnt;
        cnt=1;
    }
 
    if (n==1) printf("0");
    else
    printf("%d",n-maxi);
 
 
    return 0;
}
