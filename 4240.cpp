#include <iostream>
 
using namespace std;
 
int a[4000005];
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int s,p,op;
    int i,j,tmp;
    int min=4000000,max=0;
   
    cin>>s;
 
    for (i=0;i<s;i++) {
        cin>>tmp;
        tmp=tmp+2000000;
        a[tmp]=1;
        if (tmp>max) max=tmp;
        if (tmp<min) min=tmp;
    }
 
    cin>>p;
 
    while (p!=0) {
       cin>>op;
       if (op==0) {
          cin>>tmp;
          tmp+=2000000;
          a[tmp]=0;
          if (tmp==min) {
              for (i=tmp;i<=max;i++) {
                  if (a[i]==1) {
                      min=i;
                      break;
                  }
              }
       }
       }
 
       if (op==1) {
          cin>>tmp;
          tmp+=2000000;
          a[tmp]=1;
          if (tmp>max) max=tmp;
          if (tmp<min) min=tmp;
       }
 
    p--;
    }
 
    for (i=min;i<=max;i++) {
        if (a[i]==1) cout<<i-2000000<<' ';
    }
 
 
    return 0;
}
