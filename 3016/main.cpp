#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX = 1e5+ 5;
long long s[MAX], tmp;
int main(){
	int n; scanf("%d", &n);
	int num=0;
	for(int i = 1; i <= n; ++i)
        scanf("%lld", &s[i]);
	for(int i = 1; i <= n; ++i)
	    s[i] += s[i - 1];
	sort(s+1,s+n+1);
	for(int i=1;i<=n;++i) {
        if (s[i]-s[n/2+1]!=0) num++;
    cout<<num<< endl;
	return 0;

}
