#include <iostream>
 
using namespace std;
void money(long long int num,long long int m1,long long int m2);
 
int main()
{
    long long int q,i,j;
    long long int a[1001][3];
 
    cin>>q;
    for (i=0;i<q;i++) {
       cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    for (i=0;i<q;i++) {
       money(a[i][0],a[i][1],a[i][2]);
    }
 
 
 
    return 0;
}
void money(long long int num,long long int m1,long long int m2)
{
    long long int i;
    long long sum=0;
    if (2*m1<=m2) sum=num*m1;
    if (m1*2>m2) {
       i=num/2;
       if (num%2==1) sum=i*m2+m1;
       if (num%2==0) sum=i*m2;
    }
    cout<<sum<<endl;
}
