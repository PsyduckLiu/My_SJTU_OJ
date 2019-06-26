#include <iostream>
 
#include <math.h>
 
#include <iomanip>
 
using namespace std;
 
 
 
int main(){
 
	double minn=0;
 
	double r,d,h,sita;
 
	while (cin>>r>>d){
 
		h=sqrt(r*r-d*d);
 
		sita=(asin(h/r))*2;
 
		minn=max(minn,(0.5*sita*r*r-h*d));
 
	}
 
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<minn<<endl;
 
	return 0;
 
}
