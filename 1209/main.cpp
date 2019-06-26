#include <iostream>

using namespace std;

int main()
{
    int n;
    int *a;
    cin>>n;
    a=new int[n];
    int i,j,num=0;

    for (i=0;i<n;i++) cin>>a[i];
    for (i=0;i<n;i++) {
        while (a[i]>=2) {
            if (a[i]%2==1) num+=1;
            a[i]=a[i]/2;
            }
        if (a[i]==1) num+=1;
    }
    cout<<num;
    return 0;
}
