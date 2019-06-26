#include <iostream>
 
using namespace std;
 
const int maxn = 1e5 + 7;
int seq[maxn];
int q[maxn];
long long int ret = 0;
 
void mergeArray(int li[], int low, int mid, int high, int temp[]) {
 
    int i = low, j = mid + 1, k = 0;
    while (i < mid + 1 && j < high + 1) {
        if (li[i] <= li[j]) temp[k++] = li[i++];
        else {
            temp[k++] = li[j++];
            ret += mid - i + 1;
        }
    }
    while (i < mid + 1) temp[k++] = li[i++];
    while (j < high + 1) temp[k++] = li[j++];
    for (int i = 0; i < k; i++)  li[low + i] = temp[i];
}
 
void sortSeq(int li[], int low, int high, int temp[]) {
    int mid = (low + high) / 2;
    if (low + 1 < high) {
        sortSeq(li, low, mid, temp);
        sortSeq(li, mid + 1, high, temp);
    }
    mergeArray(li, low, mid, high, temp);
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> seq[i];
    }
    sortSeq(seq, 0, size - 1, q);
    cout <<ret;
 
    return 0;
 
}
