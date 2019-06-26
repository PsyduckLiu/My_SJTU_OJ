#include <iostream>
#include <cstdio>
#include <cctype>
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return X;
}
 
inline void write(int x) {
  int y = 10, len = 1;
  while (y <= x) {
    y *= 10;
    len++;
  }
  while (len--) {
    y /= 10;
    putchar(x / y + 48);
    x %= y;
  }
}
int a[200001],b[200001];
int divide(int a[],int low,int high)
{
    int k=a[low];
   do{
           while (low<high&&a[high]>=k) --high;
             if (low<high) {a[low]=a[high];++low;}
               while (low<high&&a[low]<=k) ++low;
                  if (low<high) {a[high]=a[low];--high;}  }
while (low!=high);
   a[low]=k;
      return low;}
void quicksort( int a[],int low,int high)
{
       int mid;
           if (low>=high) return;
        mid=divide(a,low,high);
 quicksort(a,low,mid-1);
 quicksort(a,mid+1,high);}
using namespace std;
 
 
const int mod=1000000007;
int main()
{
 
    int T,n;
    int i,k;
    T=read();
    n=read();
 
 
    for (i=0;i<n;i++) {
      a[i]=read();
    }
    quicksort(a,0,n-1);
 
    b[n-1]=a[n-1];
    for (i=n-2;i>=0;i--) {
        b[i]=b[i+1]+a[i];
 
        if (b[i]>mod) b[i]=b[i]-mod;
 
    }
 
    while (T) {
 
       k=read();
 
      write(b[n-k]);
      putchar('\n');
       T--;
 
 
    }
 
 
    return 0;
}
