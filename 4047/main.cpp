#include <iostream>

using namespace std;

int main()
{
     a[2e6],b[2e6];
    int i,n,k,m,p;

    cin>>n;
    k=p=2;
    for (i=0;i<n-1;i++) {
        a[i]=k;
        k+=1;
    }
    for (m=0;m<n-1;m++) {
        b[m]=p;
        p+=1;
    }
    for (m=0;m<n-1;m++) {
        for (i=m+1;i<n-1;i++) {
            if (a[i]%b[m]==0) a[i]=1;
        }
    }
   for (i=0;i<n-1;i++) {
    if (a[i]==1) continue;
    else cout<<a[i]<<' ';
   }
    return 0;
}
