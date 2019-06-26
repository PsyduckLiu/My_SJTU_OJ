#include <iostream>
#include <cstdio>
 
using namespace std;
 
int n,g[100005],v[100005]={0},cnt=0;
 
int main()
{
 
   scanf("%d",&n);
 
   for(int i=0;i<n;i++) {
       scanf("%d",&g[i]);
   }
 
   for(int i=0;i<n;i++) {
       if(v[i])continue;
       v[i]=1;
       int j=i;
       while(g[j]!=i) {
       j=g[j];
       v[j]=1;
 
 }
 
       cnt++;
 }
 
    printf("%d",cnt-1);
    return 0;
}
