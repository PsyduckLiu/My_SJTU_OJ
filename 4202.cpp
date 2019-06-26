#include <iostream>
  #include <cstring>
 
  using namespace std;
 
  const int maxn = 1000000+10;
  const int INF=1<<30;
  const int h[]={0,1,2,2,3};
  int d[maxn][5],w[maxn][4];
  int n;
 
 int main() {
     ios::sync_with_stdio(false);
     cin>>n;
     for(int i=1;i<=n;i++) cin>>w[i][1]>>w[i][2]>>w[i][3];
 
     int ans=-INF;
     for(int d1=1;d1<=4;d1++) {
        memset(d,0,sizeof(d));
         for(int i=1;i<=4;i++) d[1][i]=-INF;
         d[1][d1] = w[1][h[d1]];
         for(int i=2;i<=n;i++)
         {
                 d[i][1]=max(d[i-1][4],d[i-1][2])+w[i][1];
                 d[i][2]=d[i-1][1]+w[i][2];
                 d[i][3]=d[i-1][4]+w[i][2];
                 d[i][4]=max(d[i-1][1],d[i-1][3])+w[i][3];
         }
         switch (d1) {
              case 1: ans=max(ans,d[n][2]); ans=max(ans,d[n][4]); break;
              case 2: ans=max(ans,d[n][1]); break;
              case 3: ans=max(ans,d[n][4]); break;
              case 4: ans=max(ans,d[n][1]); ans=max(ans,d[n][3]); break;
       }
     }
     cout<<ans;
    return 0;
 }
