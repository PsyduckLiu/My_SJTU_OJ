#include <iostream>
#include <iomanip>
using namespace std;
 
int grade[1005];
 
int main()
{
    int n,m,op,l,r;
    int i;
    int tmp,maxn;
    double sum;
    cin>>n>>m;
 
    for (i=0;i<n;i++) cin>>grade[i];
 
    while (m!=0) {
        cin>>op;
        sum=0.0;
        maxn=0;
        if (op==0) {
            cin>>l>>r;
            for (i=l;i<=r;i++) sum+=grade[i];
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum/(r-l+1)<<endl;
        }
 
        if (op==1) {
            cin>>l>>r;
            for (i=l;i<=r;i++) {
                if (grade[i]>maxn) maxn=grade[i];
            }
            cout<<maxn<<endl;
        }
 
        if (op==2) {
                cin>>l>>r;
            for (i=0;i<(r-l+1)/2;i++) {
                tmp=grade[l+i];
                grade[i+l]=grade[r-i];
                grade[r-i]=tmp;
            }
        }
 
        if (op==3) {
            cin>>l>>r;
            for (i=l;i<=r;i++) cout<<grade[i]<<' ';
            cout<<endl;
        }
 
        if (op==4) {
            cin>>l>>r;
            for (i=l;i<=r;i++) {
                if (grade[i]!=0) grade[i]=grade[i]-1;
            }
        }
        m--;
    }
    return 0;
}
