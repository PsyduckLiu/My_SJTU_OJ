#include <iostream>

using namespace std;

int main()
{
    int a,b,i,j,k,l,m,n,p;
    k=0;
    m=0;
    cin>>a>>b;

    if (a<=0||b<=0||a>b) cout<<"error";

    else {

       for (i=a;i<=b;i++) {
       for (j=10;i>=j;j*=10);
       n=i;
       p=i;
        while (j>1) {
          j/=10;
          l=p/j;
          k+=l*l*l;
          p-=j*l;}00

        if (k==n) {
            cout<<n<<'\n';
            m+=1;}


        k=0;
        }
      if (m==0) cout<<"no";

    }
    return 0;
}
