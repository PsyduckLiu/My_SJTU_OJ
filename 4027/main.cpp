#include<iostream>
#include<cstdio>

using namespace std;
int n;
int a1[100010],a2[100010];
int belong[100010];
int f[100010],b[100010],len;
int halfsearch(int low,int high,int x)
{
    while (low<=high)
    {
        int mid=(low+high)>>1;
        if (x>b[mid]) low=mid+1;
        else high=mid-1;
    }
    return low;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a1[i]);
        belong[a1[i]]=i;
    }
    for(int i=1;i<=n;i++)
    scanf("%d",&a2[i]);
    for(int i=1;i<=n;i++)
    {
        if(belong[a2[i]]>b[len])
        {
            b[++len]=belong[a2[i]];

            continue;
        }
        int k=halfsearch(1,len,belong[a2[i]]);
        b[k]=belong[a2[i]];
    }
    printf("%d\n",len);
    return 0;
}
