#include <iostream>

using namespace std;

int main()
{
   int n;
   unsigned int a[100000],b[100000],c[100000];
   int i,j;
   bool flag=true;
   cin>>n;
   for (i=0;i<n;i++) cin>>a[i]>>b[i];
   if (a[0]>b[0]) c[0]=a[0];
       else c[0]=b[0];

   for (i=1;i<=n-1;i++) {
     if (a[i]>c[i-1]&&b[i]>c[i-1]) {
        flag=false;
        break;
     }
     else {
        if (a[i]<=c[i-1]&&b[i]<=c[i-1]) {
            if (a[i]>b[i]) c[i]=a[i];
            else c[i]=b[i];
        }
        if (a[i]<=c[i-1]&&b[i]>c[i-1]) c[i]=a[i];
        if (a[i]>c[i-1]&&b[i]<=c[i-1]) c[i]=b[i];
     }
   }

   if (flag==true) cout<<"YES";
   else cout<<"NO";
    return 0;
}
