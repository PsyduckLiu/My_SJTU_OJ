#include <iostream>
#include <algorithm>

using namespace std;

int v[100005];
int n, c;

int check(int d) {

	int tmp = v[0], cnt = 1;

	for (int i = 1; i < n; i++) {

		if (v[i] - tmp >= d) {

			cnt++;

			tmp = v[i];

		}

	}

	if (cnt >= c)

		return 1;

	return 0;

}

int main() {

	cin >> n >> c ;

		for (int i = 0; i < n; i++)  cin >> v[i];

		sort(v, v + n);

		int l = 0, r = v[n - 1], mid;

		while (l <= r) {

			mid = (l + r) / 2;

			if (check(mid))

				l = mid + 1;

			else

				r = mid - 1;

		}

		cout<<r;



	return 0;

}
