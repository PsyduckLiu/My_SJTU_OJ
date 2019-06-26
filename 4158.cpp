#include<iostream>
#include<algorithm>
using namespace std;
 
int x[100001];
 
int C(int m,int n){
 
	int i,j,sum=1;
 
	for (i=m,j=0;j<n;j++,i--)
 
		sum=sum*i/(j+1);
 
	return sum;
 
}
 
int main(){
 
	int  t,n,m;
 
	cin>>t;
 
	while(t--){
 
		cin>>n>>m;
 
		x[0]=0;
 
		int cnt=0;
 
		int w;
 
		for(int i=1;i<=n;++i){
 
			cin>>w;
 
			x[i]=((x[i-1]+w)%m+m)%m;
 
		}
 
		sort(x,x+n+1);
 
		int s=1;
 
		for(int i=1;i<=n;++i){
 
			if(x[i]==x[i-1])
 
				s++;
 
			else{
 
				cnt+=C(s,2);
 
			    s=1;
 
			}
 
		}
 
		cnt+=C(s,2);
 
		cout<<cnt<<endl;
 
	}
 
	return 0;
 
}
