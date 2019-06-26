#include <iostream>
 
using namespace std;
 
int main()
{
   long long int M,T,U,F,D;
   char a[100001];
   int i;
 
   cin>>M>>T>>U>>F>>D;
   for (i=0;i<T;i++) cin>>a[i];
 
   for (i=0;i<T;i++) {
      if (a[i]=='u'||a[i]=='d') M=M-U-D;
      if (a[i]=='f') M=M-F-F;
      if (M<0) break;
 
   }
   cout<<i;
 
    return 0;
}
