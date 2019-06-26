#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char ch[7];
    int n,m;
    int i,j;
    cin.getline(ch,7);
    cin>>n>>m;

    if (strcmp(ch,"int")==0) {
        int a[n],b[m],c[n+m];
        for (i=0;i<n;i++) cin>>a[i];
        for (i=0;i<m;i++) cin>>b[i];

        for (i=0;i<n;i++) c[i]=a[i];
        for (i=n,j=0;i<n+m;i++,j++) c[i]=b[j];

        for (j=0;j<m+n;j++) cout<<c[j]<<" ";
    }
    if (strcmp(ch,"char")==0) {
        char a[n],b[m],c[n+m];
        for (i=0;i<n;i++) cin>>a[i];
        for (i=0;i<m;i++) cin>>b[i];

        for (i=0;i<n;i++) c[i]=a[i];
        for (i=n,j=0;i<n+m;i++,j++) c[i]=b[j];

        for (j=0;j<m+n;j++) cout<<c[j]<<" ";
    }
    if (strcmp(ch,"double")==0) {
        double a[n],b[m],c[n+m];
        for (i=0;i<n;i++) cin>>a[i];
        for (i=0;i<m;i++) cin>>b[i];

        for (i=0;i<n;i++) c[i]=a[i];
       for (i=n,j=0;i<n+m;i++,j++) c[i]=b[j];

        for (j=0;j<m+n;j++) cout<<c[j]<<" ";
    }

    return 0;
}
