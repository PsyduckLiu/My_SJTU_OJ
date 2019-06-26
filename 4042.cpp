#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1000000009;
int arr[300005];
void Merge(int p,int q,int r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int left[300000],right[300000];
    for (i=0; i<n1; ++i) left[i]=arr[p+i];
    for (j=0; j<n2; ++j) right[j]=arr[q+1+j];
    i=j=0;
    left[n1]=N;
    right[n2]=N;
    for (k=p; k<=r; ++k)
    {
        if (left[i]>right[j])
        {
            arr[k]=right[j];
            ++j;
        }
        else
        {
            arr[k]=left[i];
            ++i;
        }
    }
}
void MergeSort(int p,int r)
{
    if (p<r)
    {
 
 
        int q=(p+r)/2;
        MergeSort(p,q);
        MergeSort(q+1,r);
        Merge(p,q,r);
    }
}
int Mul(int x,int y);
int Plus(int x,int y);
int Minus(int x,int y);
int pre[300005],sub[300005];
const int mod=1000000007;
int main()
{
    int n,i,a=1,ans=0;
    scanf("%d",&n);
    for (i=1;i<=n;++i)
        scanf("%d",&arr[i]);
    MergeSort(1,n);
    pre[1]=arr[1];
    sub[n]=arr[n];
    for (i=2;i<n;++i)
    {
        pre[i]=Plus(pre[i-1],arr[i]);
        sub[n+1-i]=Plus(sub[n+2-i],arr[n+1-i]);
    }
    for (i=1;i<n;++i)
    {
        ans=Plus(ans,Mul(a,Minus(sub[n+1-i],pre[i])));
        a=Plus(a,a);
    }
    printf("%d",ans);
    return 0;
}
int Plus(int x,int y)
{
    return (x+y)>=mod?(x+y-mod):(x+y);
}
int Minus(int x,int y)
{
    return (x-y)<0?(x-y+mod):(x-y);
}
int Mul(int x,int y)
{
    long long int x1=x,y1=y;
    return x1*y1%mod;
}
