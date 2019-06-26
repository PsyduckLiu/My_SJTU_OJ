#include <iostream>
#include <cstdio>
 
using namespace std;
 
int n;
int v[100005],r[100005];
long long a[100005]={0};
 
int main()
{
   scanf("%d",&n);
 
   for(int i=0;i<n;i++) {
       scanf("%d",&v[i]);
   }
 
   for(int i=0;i<n;i++) {
       scanf("%d",&r[i]);
    }
 
   for(int i=0;i<n;i++) {
       int j=i;
       while(v[i]>=r[j]) {
          a[j]+=r[j];
          v[i]-=r[j];
          j++;
    }
 
    a[j]+=v[i];
 
}
    for(int i=0;i<n;i++) {
        printf("%lld ",a[i]);
    }
return 0;
}
