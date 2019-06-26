#include <iostream>

using namespace std;

int main()
{
    int n;
    int i,j,a=0,b=0,count,k;

    cin>>n;
    k=n;
    if (n==2) cout<<"0";
    else {
    if (k%2==0) n=k-1;

    for (i=n;i>=3;i-=2) {
    count=0;
    for (j=1;j<=i;j+=2) {
        if (i%j==0) ++count;
    }
    if (count==2) {
        a=i;
        break;
    }
    }

    if (k%2==0) n=k+1;
    for (i=n;;i+=2) {
    count=0;
    for (j=1;j<=i;j+=2) {
        if (i%j==0) ++count;
    }
    if (count==2) {
        b=i;
        break;
    }
    }

    if ((b-a)==0) cout<<"0";
    else cout<<b-a;


    }
    return 0;
}
