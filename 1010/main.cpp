#include <iostream>

using namespace std;

int main()
{
    int mom=0,ming=0;
    int a[12];
    int i,j,k=0;
    double sum;
    for (i=0;i<12;i++) cin>>a[i];
    for (i=0;i<12;i++) {
        ming=ming+300-a[i];
        if (ming<0) {
            j=-(i+1);
            k=1;
            break;
        }
        if (ming>=100) {
            mom+=(ming/100)*100;
            ming-=(ming/100)*100;
        }}
        if (k==0) {
            sum=(mom/5)*6+ming;
            cout<<sum;
        }
        if (k==1) {
            cout<<j;
        }


    return 0;
}
