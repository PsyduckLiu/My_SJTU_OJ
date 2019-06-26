#include <iostream>
#include <cmath>
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
 
using namespace std;
int f[200005][25];
int n,m;
int main()
{
   int x,y;
   n=read();
   m=read();
 
 
for(int i=1;i<=n;i++) {
   x=read();
   f[i][0]=x;
}
 
 
int p=log2(n);
 
 
for(int j=1;j<=p;j++)
for(int i=1;i<=n-(1<<j)+1;i++)
  f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
 
 
 
for(int i=1;i<=m;i++){
  x=read();
  y=read();
  p=log2(y-x+1);
 
   write(max(f[x][p],f[y-(1<<p)+1][p]));
   putchar('\n');
}
 
  return 0;
}
