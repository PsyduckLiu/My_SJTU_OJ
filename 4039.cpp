#include <iostream>
 
using namespace std;
 
int main()
{
 int N,i,j,a;
a=0;
 cin>>N;
 while (N%2==0) {
        N/=2;
       if (N!=1) cout<<"2"<<' ';
       if (N==1) cout<<"2";
    }
if (N!=1) {
   for (i=3;i<=N+2;i+=2)
   for (j=3;j<=i;j+=2) {
      if (i%j==0) a+=1;
      if (a==1) {
      while (N%i==0) {
            N/=i;
        if (N!=1) cout<<i<<' ';
         if (N==1) cout<<i;
        }
 
      } a=0;
}
}
    return 0;
}
