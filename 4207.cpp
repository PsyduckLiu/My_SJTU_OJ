#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 5e3+10;
int n,k,a[maxn];
int num[maxn];
int dp[maxn][maxn];
 
int main(){
 	scanf("%d%d",&n,&k);
 	for(int i = 1; i <= n; i++)
  		scanf("%d",&a[i]);
 	sort(a+1,a+n+1);
 	for(int i = 1; i <= n; i++){
  		int low = a[i] - 5;
  		num[i] = i+1-(lower_bound(a+1,a+n+1,low)-a);
 	}
 
 	for(int i = 1; i <= n; i++){
  		for(int j = 1; j <= k; j++){
   			dp[i][j]=max(dp[i][j],dp[i-1][j]);
   			dp[i][j]=max(dp[i][j],dp[i-num[i]][j-1]+num[i]);
  		}
 	}
 	printf("%d\n",dp[n][k]);
}
