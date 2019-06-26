#include <iostream>

using namespace std;

int main()
{
    int a,b,i,j,k,l,m,n,p,q,s,c;
    k=0;
    m=0;
    q=1;
    c=1;
    cin>>a>>b;

    if (a<=0||b<=0||a>b) cout<<"error";

    else {

       for (i=a;i<=b;i++) {
       for (j=10;i>=j;j*=10) {
           q+=1;
       }
       n=i;
       p=i;
        while (j>1) {
          j/=10;
          l=p/j;
          for (s=0;s<q;s++) {
          c=c*l;}
          k+=c;
          p-=j*l;
          c=1;
          }

        if (k==n) {
            cout<<n<<'\t';
            m+=1;}


        k=0;
        }
      if (m==0) cout<<"no";

    }
    return 0;
}
