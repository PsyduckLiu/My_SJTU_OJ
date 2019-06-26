#include <iostream>
#include <algorithm>

using namespace std;

const int MX=10000+5;



struct Seg{

    long long int L,R;

    bool operator<(const Seg&b)const{

        if(L==b.L){

            return R>b.R;

        }

        return L<b.L;

    }

}A[MX];



int main(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>A[i].L>>A[i].R;
}
    sort(A+1,A+1+n);
    long long int ans=0,L=0,R=0;
    for(int i=1;i<=n;i++){
            if(L<=A[i].L&&A[i].L<=R) R=max(R,A[i].R);
            else{
                ans+=R-L;
                L=A[i].L;
                R=A[i].R;
}        }

        ans+=R-L;

        cout<<ans;



    return 0;

}
