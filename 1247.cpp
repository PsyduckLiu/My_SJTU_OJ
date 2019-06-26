#include <iostream>
 
using namespace std;
 
int tree[10005];
 
int main()
{
    int n,m;
    int l,r,i;
    int num=0;
    cin>>n>>m;
 
    while (m!=0) {
        cin>>l>>r;
        for (i=l;i<=r;i++) {
            if (tree[i]==0) tree[i]=1;
        }
        m--;
    }
 
    for (i=0;i<=n;i++) {
        if (tree[i]==0) num++;
    }
    cout<<num;
    return 0;
}
