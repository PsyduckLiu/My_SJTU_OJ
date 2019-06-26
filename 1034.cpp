#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
 
int n, k;
 
int q[440000];
 
int q_pos[440000];
 
int ss = 0;
 
int tt = -1;
 
int num[440000];
 
 
void q_push(int num, int pos) {
 
    while (ss <= tt && q[tt] < num) --tt;
 
    q[++tt] = num;
 
    q_pos[tt] = pos;
 
}
 
 
 
void q_pop(int pos) {
 
    if (pos == q_pos[ss]) ++ss;
 
}
 
int main() {
 
    scanf("%d %d", &n, &k);
 
    for (int i = 0; i < n; ++i) { scanf("%d", num + i); num[i + n] = num[i]; }
 
    for (int i = 0; i < k; ++i) { q_push(num[i], i); }
 
 
 
    int res=q[ss];
 
    for (int i = k; i < 2*n; ++i) {
 
        q_push(num[i], i);
        q_pop(i - k);
        res=min(q[ss], res);
 
    }
 
    cout << res << endl;
   return 0;
}
