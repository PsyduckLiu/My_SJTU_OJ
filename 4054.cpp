#include <iostream>
#include <cstring>
using namespace std;
long long int sum(char *a,int l);
int main()
{
    long long int num=0;
    char l[19],r[19];
    int l1,l2;
 
    cin>>l>>r;
    l1=strlen(l);
    l2=strlen(r);
 
 
    num=sum(r,l2)-sum(l,l1);
    if (l[l1-1]==l[0]) num++;
 
    cout<<num;
    return 0;
}
long long int sum(char *a,int l)
{
    long long int tmp=9,all=0,n=0;
    int i;
    if (l>2) {
        for (i=3;i<l;i++) {
        tmp=tmp*10;
        all+=tmp;
    }
        if (a[l-1]==a[0]) {
            for (i=1;i<l-1;i++) n=10*n+(a[i]-'0');
            all=all+n+((a[0]-'0')-1)*tmp*10/9+1;
        }
        if (a[l-1]<a[0]) {
            for (i=1;i<l-1;i++) n=10*n+(a[i]-'0');
            all=all+n+((a[0]-'0')-1)*tmp*10/9;
        }
        if (a[l-1]>a[0]) {
            for (i=1;i<l-1;i++) n=10*n+(a[i]-'0');
            all=all+((a[0]-'0')-1)*tmp*10/9+n+1;
        }
        all+=18;
    }
 
    if (l==2) {
        if (a[0]<a[1]) all+=a[0]-'0';
        if (a[0]==a[1]) all+=a[0]-'0';
        if (a[0]>a[1]) all+=a[0]-'0'-1;
        all+=9;
    }
    if (l==1) {
        all=a[0]-'0';
    }
    return all;
}
