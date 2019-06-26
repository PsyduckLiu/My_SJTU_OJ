#include <iostream>
#include <cstdio>
 
using namespace std;
 
const int maxlen = 100100;
 
int le[maxlen] = { 0 }, ri[maxlen] = { 0 };
int root;
bool check[maxlen] = { 0 };
int n;
int que[maxlen] = { 0 };
int head = 1, rear = 0;
int cnt = 0;
int num[maxlen] = { 0 };
 
void enque(int x) {
    que[++rear] = x;
}
 
int deque() {
    int x = que[head];
    head++;
    return x;
}
 
bool empty() {
    return rear + 1 == head;
}
 
int main()
 
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> le[i] >> ri[i];
        check[le[i]] = check[ri[i]] = true;
    }
 
    for(int i = 1; i <= n; ++i) {
        if(check[i] == false) {
            root = i;
            break;
        }
    }
 
    enque(root);
    num[root] = 1;
    
    while(!empty()) {
        int tmp = deque();
        cnt++;
        if(cnt != num[tmp]) {
            cout << "N" << endl;
            return 0;
        }
 
        if(le[tmp] != 0) enque(le[tmp]);
        if(ri[tmp] != 0) enque(ri[tmp]);
        
        num[le[tmp]] = cnt * 2; 
        num[ri[tmp]] = cnt * 2 + 1;
 
    }
 
    cout << "Y" << endl;
 
    return 0;
 
}
