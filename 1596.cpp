#include <iostream>
 
using namespace std;
 
int main()
{
   long long int n,i,j,sum=0;
   long long int a,b;
 
   cin>>n>>i>>j;
   while (i<n&&j<n&&i!=1&&j!=1) {
       sum+=(n-1)*4;
       n=n-2;
       i=i-1;
       j=j-1;
 
   }
   a=b=sum;
 
   if (j==1) a+=n-i+1;
   else {
        if (j==n) a+=i+2*(n-1);
        else {
           if (i==1) a+=n+j-1;
           else a+=2*n+n-2+n-j;
        }
   }
 
   if (j==n) b+=i;
   else {
        if (j==1) b+=n-i+1+2*(n-1);
        else {
           if (i==n) b+=n+n-j;
           else b+=2*n+n-2+j-1;
        }
   }
   cout<<a-1<<' '<<b-1;
 
    return 0;
}
