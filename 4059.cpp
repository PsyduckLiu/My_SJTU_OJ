#include <iostream>
 
using namespace std;
class wax{
 int num;
 
public:
    void in(int m) {
        num=m;}
    void out(int b[],int n) {
         int j,m=0,d;
         for (j=0;j<n;j++) {
          if (b[j]>m) {
            m=b[j];
            d=j+1;
        }
    }
    cout<<m<<' '<<d;
    }
};
int main()
{
    int p,j;
    int q[100];
    wax ma;
    cin>>p;
    for (j=0;j<p;j++) cin>>q[j];
    ma.in(p);
    ma.out(q,p);
    return 0;
}
