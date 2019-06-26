#include <iostream>
 
#include <cstdio>
 
#define MAX 70000
 
 
 
using namespace std;
 
 
 
void output(int *node, int root) {
 
    if (node[root] == -1) return;
 
    output(node, 2*root+1);
 
    output(node, 2*root+2);
 
    printf("%d ", node[root]);
 
}
 
 
 
int main() {
 
    int node[MAX], index[MAX];
 
    int n, id, left, right;
 
 
 
    scanf("%d", &n);
 
 
 
    node[0] = 1;
 
    index[1] = 0;
 
 
 
    for (int i = 0; i < n; ++ i) {
 
        scanf("%d %d %d", &id, &left, &right);
 
        if (left != -1) {
 
            index[left] = 2*index[id]+1;
 
        }
 
        node[2*index[id]+1] = left;
 
        if (right != -1) {
 
            index[right] = 2*index[id]+2;
 
        }
 
        node[2*index[id]+2] = right;
 
    }
 
 
 
    for (int i = 1; i <= n; ++ i)
 
        printf("%d ", index[i]+1);
 
    printf("\n");
 
 
 
    output(node, 0);
 
    printf("\n");
 
 
 
 
 
    return 0;
 
}
