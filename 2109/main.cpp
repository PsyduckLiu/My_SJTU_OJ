#include <iostream>

using namespace std;

int main()
{
    int N,K;
    long long int a[100001],b[10001][2],c[10001]={0};
    int i,j;
    long long int k;

    cin>>N;
    for (i=0;i<N;i++) cin>>a[i];
    cin>>K;
    for (i=0;i<K;i++) cin>>b[i][0]>>b[i][1];

    for (j=0;j<K;j++) {
            for (i=0;i<N;i++) {
            k=b[j][0]*b[j][0]-4*a[i]*b[j][1];
            if (k<0) {
                    c[j]=i;
                    break;
            }
            }
            c[j]=i;
          }
     for (i=0;i<K;i++) cout<<c[i]<<'\n';


    return 0;
}
