#include <iostream>

using namespace std;
unsigned int fibo(int a);
int main()
{
    int n;
    cin>>n;
    if (n<=0) cout<<"error!";
    else cout<<fibo(n);

    return 0;
}
unsigned int fibo(int a)
{
   const int m=50;
   int *p;
   p=new int [m];

    if (a==1) return 0;
    if (a==2) return 1;
    p[1]=0;
    p[2]=1;
    for (int i=3;i<=a;i++)
        p[i]=p[i-1]+p[i-2];
    return p[a];
    delete []p;




}
