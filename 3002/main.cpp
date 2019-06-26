#include <iostream>
#include <cstdio>

using namespace std;

bool num[1009]={0};
int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int tmp;
		scanf("%d",&tmp);
		if (!num[tmp]) {
			++cnt;
			num[tmp] = true;
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < 1001; ++i) {
		if (num[i]) printf("%d ", i);
	}
	return 0;

}
