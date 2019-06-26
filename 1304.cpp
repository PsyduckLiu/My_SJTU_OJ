#include<iostream>
 
using namespace std;
 
int main(){
 
	int n,L;
 
	int i;
	int tmax=0,tmin=1000000001;
    cin>>n>>L;
 
	int a[10001];
    int t[10001];
 
 
	for(i=0;i<n;i++){
        cin>>a[i];
        if ((i+1)%2==1) {
                
                t[i]=L-a[i];}
        if ((i+1)%2==0) {
              
                t[i]=a[i];
	}
	}
 
 
       for(i=0;i<n;i++){
            if (t[i]>tmax) tmax=t[i];
            if (t[i]<tmin) tmin=t[i];
 
       }
 
 
      cout<<tmin<<' '<<tmax;
 
 
    return 0;
}
