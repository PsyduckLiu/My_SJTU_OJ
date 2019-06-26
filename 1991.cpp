#include <iostream>
#include <algorithm>
#include <iomanip>
 
using namespace std;
int fugai (double a[],double leng,int num,int poin);
double bug(double b[],double nowl,int nu,int poi);
int main()
{
    int n,k;
    int i;
    double length;
    double point[100001];
 
    cin>>n>>k;
    for(i=0;i<n;i++)  cin>>point[i];
    length=point[n-1]-point[0];
    length=bug(point,length,k,n);
    cout<<fixed<< setprecision(6)<<length/2.0<<'\n';
    return 0;
}
int fugai (double a[],double leng,int num,int poin)
{
    int i,j=0;
    double l;
    while (num) {
    l=0;
    for (i=j+1;i<poin;i++) {
        l+=a[i]-a[i-1];
        if (l>leng) break;
    }
    j=i;
    num--;
    if (j==poin) break;
 
    }
    if (num>=0&&j==poin) return 1;
    else return 0;
}
 
double bug(double b[],double nowl,int nu,int poi)
{
    double left,right;
    left=0.0;
    right=nowl;
    while (right-left>0.000001) {
    if (fugai(b,(right+left)/2,nu,poi)==1) {
        right=(right+left)/2;
    }
    if (fugai(b,(right+left)/2,nu,poi)==0) {
       left=(right+left)/2;
    }}
    return right;
 
}
