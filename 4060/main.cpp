#include <iostream>

using namespace std;

void shunxu(int a[],int num);
int time(int a[],int num);

int main()
{
    int i,n;
    int b[100];

    cin>>n;
    for (i=0;i<n;i++) cin>>b[i];

    shunxu(b,n);
    cout<<time(b,n);
    return 0;
}
void shunxu(int a[],int num)
{
    int j,k,tmp;
    for (j=1;j<num;j++) {
        for (k=0;k<num-j;k++) {
            if (a[k+1]<a[k]) {
                tmp=a[k];
                a[k]=a[k+1];
                a[k+1]=tmp;
            }
        }
    }
}
int time(int a[],int num)
{
    int k,t;
    t=0;
    if (num%2==0) {
        if (num==2) t=t+a[1];
        else t=t+2*a[1]+a[0]+a[num-1]+time(a,num-2);
    }
    if (num%2==1) {
        if (num==1) t=t+a[0];
        if (num==3) t=t+a[0]+a[1]+a[2];
        if (num>3) {
           t=t+2*a[1]+a[0]+a[num-1]+time(a,num-2);
        }
    }
    return t;
}
