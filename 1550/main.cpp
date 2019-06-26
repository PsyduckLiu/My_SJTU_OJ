#include <iostream>

using namespace std;

int main()
{
    int n,i,j,k=0,m=0,t=0,b;
    int x[10000]={0},maxl[10000]={0},maxr[10000]={0},c[10000];
    char a[20005];

    cin>>n;
    cin>>a;
    j=0;
    for (i=1;a[i]!=']';i++) {
            if (a[i]==',') {
                c[j]=i;
                t++;
                if (t==1) {
                    for (b=1;b<=i-1;b++) x[j]=10*x[j]+(a[b]-'0');
                    j++;
                    }
                if (t>1&&t<n) {
                    for (b=c[j-1]+1;b<c[j];b++) x[j]=10*x[j]+(a[b]-'0');
                    j++;}
                }
            }
    for (b=c[j-1]+1;b<i;b++) x[j]=10*x[j]+(a[b]-'0');

    i=1;
    while (i<n) {
        if (x[i-1]>maxl[i-1]) maxl[i]=x[i-1];
        else maxl[i]=maxl[i-1];
        i++;
    }
    i=n-2;
    while (i>0) {
        if (x[i+1]>maxr[i+1]) maxr[i]=x[i+1];
        else maxr[i]=maxr[i+1];
        i--;
    }

    for (i=1;i<n-1;i++) {
            if (x[i]<maxl[i]&&x[i]<maxr[i])
        k+=min(maxl[i],maxr[i])-x[i];
    }

    cout<<k;

    return 0;
}
