#include <iostream>

using namespace std;

int main()
{
    int a[10][10],b[10][10];
    int m,n,i,j,p,q,k,c,d;


    cin>>m>>n;
    for (i=0;i<m;i++)
    for (j=0;j<n;j++) {
        cin>>a[i][j];
    }
    cout<<n<<' '<<m<<endl;
    for (i=0;i<m;i++) {
    for (j=0;j<n;j++) {
        p=j;
        q=m-i-1;
        k=a[i][j];
        b[p][q]=k;}
    }

     for (c=0;c<n;c++) {
    for (d=0;d<m;d++)
             cout<<b[c][d]<<' ';

             cout<<endl;
     }



return 0;
}
