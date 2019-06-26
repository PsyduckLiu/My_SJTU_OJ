#include <iostream>

using namespace std;



int main(){

	long long start,n,rest,total=0;

	cin>>start>>n;

	rest=n%7;

	for (int day=0;day<rest;++day){

		if (start<=5) total+=250;

		start++;

		if (start>7) start-=7;

	}

	total+=250*5*(n/7);

	cout<<total<<endl;

	return 0;

}
