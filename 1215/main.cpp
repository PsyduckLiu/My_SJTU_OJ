#include <iostream>

using namespace std;

int M;
int heap[20000];
int siz=0;

void ins(int x) {
	int hole=++siz;
	while (hole > 1 && x < heap[hole / 2]) {
		heap[hole] = heap[hole / 2];
		hole /= 2;
	}
	heap[hole] = x;
}

void del() {
	int top = heap[siz--];
	int hole = 1;
	while (hole * 2 <= siz) {
		int son = 2 * hole;
		if (son + 1 <= siz && heap[son] > heap[son + 1])
			son++;
		if (heap[son] < top) {
			heap[hole] = heap[son];
			hole = son;
		} else break;
	}
	heap[hole] = top;
}



void min() {
	cout<< heap[1] << endl;
}

int main()
{
	cin >> M;
	char op[10];
	for (int i = 0; i < M; ++i) {
		cin >> op;
		if (op[0] == 'd') del();
		else if (op[0] == 'm') min();
		else if (op[0] == 'i') {
			int tmp;
			cin >> tmp;
			ins(tmp);
		}
	}
	return 0;

}
