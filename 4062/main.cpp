#include <iostream>

using namespace std;

int main()
{
    long long int x,y,sum=0,a,b;

    cin>>x>>y;
    while (x>1&&y>1) {
        if (x>y) {
            x=x-y;
            sum+=4*y;}
        if (x<y) {
            y=y-x;
            sum+=4*x;}
        if (x==y) {
            sum+=x*4;
            x=y=0;}
        }
        sum+=x*y*4;
        cout<<sum;
    return 0;
}
