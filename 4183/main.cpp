#include <iostream>
using namespace std;

int a[1025] = {0};

void NextPermutation(int size) {

	int flag=size-1;
	int temp;
	int i;

	while(a[flag-1]>a[flag]&&flag!=0) {
            flag--;
}

	if(flag==0) {
            for(i=0;i<size;i++) a[i]=i+1;
            return;
}


	for(i=size-1;i>=flag;i--) {
            if(a[i]>a[flag-1]) {
                temp=a[flag-1];
                a[flag-1]=a[i];
                a[i]=temp;
                break;}}



	while(size-1>flag) {
            temp=a[size-1];
            a[size-1]=a[flag];
            a[flag]=temp;
            flag++;
            size--;
}}



int main()
{

	int m,n,k;
	int i;
	cin>>m;

	while(m) {

		cin>>n>>k;
		for(i=0;i<n;i++)  cin>>a[i];
		for(i=0;i<k;i++)  NextPermutation(n);
		for(i=0;i<n;i++)  cout<<a[i]<<' ';
		cout<<endl;
		m--;
}

	return 0;

}
