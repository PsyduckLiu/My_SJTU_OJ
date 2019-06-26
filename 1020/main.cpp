#include <iostream>
#include <cmath>
using namespace std;

int print(int a,int b);
int main()
{
   int n;
   cin>>n;
   int i,j,k,count,l;

   k=sqrt(n);

   cout<<n<<"=";
   l=print(n,2);
   for (i=3;i<=k;i+=2) {
    count=0;
    for (j=1;j<=i;j+=2) {
        if (i%j==0) ++count;
    }
    if (count==2) l=print(l,i);
   }
    if (l!=1) cout<<l<<"("<<"1"<<")";

    return 0;
}
int print(int a,int b)
{
    int s=0,m;
    m=a;
    while (m%b==0) {
        s+=1;
        m=m/b;
    }

    if (s!=0) cout<<b<<"("<<s<<")";
    return m;
}
