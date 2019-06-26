#include <iostream>
 
using namespace std;
 
 
 
int map[1250][1250],cnt[1250][1250];
int maxS=0;
 
int main()
{
 
    ios::sync_with_stdio(false);
    int w,l;
    cin>>w>>l;
    char tmp;
    for(int i=1; i<=w; ++i) {
    for(int j=1; j<=l; ++j){
        cin>>tmp;
    if(tmp=='X') map[i][j] = 1;
    cnt[i][j] = map[i][j] + cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
}
}
 
    for(int i=0; i<w; ++i) {
    for(int j=0; j<l; ++j) {
        if(map[i+1][j+1]==1) continue;
        int xr = w-i,yr = l-j;
        int r = min(yr/2,xr),l=1,mid;
        while(l<r && r>maxS) {
                mid = (l+r+1)/2;
        if(cnt[i][j+mid*2] + cnt[i+mid][j] - cnt[i][j] -cnt[i+mid][j+2*mid] ==0)  l = mid;
        else  r = mid-1;
}
       if(r<=maxS) continue;
       if(cnt[i][j+mid*2] + cnt[i+mid][j] - cnt[i][j] != cnt[i+mid][j+2*mid])   mid--;
       if(mid>maxS)   maxS = mid;
}
}
 
    cout<<maxS*maxS*2<<endl;
 
    return 0;
 
}
