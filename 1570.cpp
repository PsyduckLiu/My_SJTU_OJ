#include <iostream>
 
using namespace std;
 
int main()
{
    int n,t,*p,*q,i,s,low,high,mid;
    cin>>n>>t;
    p=new int [n];
    q=new int [t];
    for (i=0; i<n; i++) cin>>p[i];
    for (i=0; i<t; i++) cin>>q[i];
    for (i=0;i<t;i++)
    {
        low=0;high=n-1;
        while(low<high-1)
        {
            mid=(high+low)/2;
            if (q[i]>=p[mid]&&q[i]<p[mid+1]) {cout<<n-mid-1<<'\n';break;}
            if (q[i]<p[mid]) high=mid;
            else low=mid;
        }
        if (low==high-1)
            {if (q[i]<p[low]) cout<<n-low<<'\n';
            if (q[i]<p[high]&&q[i]>=p[low]) cout<<n-high<<'\n';
            if (q[i]>=p[high]) cout<<n-1-high<<'\n';}
 
        if (low==high) cout<<n-mid<<'\n';
    }
    delete [] p;
    delete [] q;
    return 0;
}
