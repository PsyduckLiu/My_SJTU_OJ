#include <iostream>
 
using namespace std;
 
 
int heap[20000];
 
int siz = 0;
 
 
 
void inser(int x) {
 
	heap[++siz] = x;
 
	int hole = siz;
 
	while (hole > 1 && heap[hole / 2] > x) {
 
		heap[hole] = heap[hole / 2];
 
		hole /= 2;
 
	}
 
	heap[hole] = x;
 
}
 
 
 
void decrease(int i, int v) {
 
	int tmp = heap[i] - v;
 
	int hole = i;
 
	while (hole > 1 && heap[hole / 2] > tmp) {
 
		heap[hole] = heap[hole / 2];
 
		hole /= 2;
 
	}
 
	heap[hole] = tmp;
 
}
 
 
 
void find(int x) {
 
	int min = 200000000;
 
	int minindex = 1;
 
	int i = 1;
 
	for (; i <= siz; ++i) {
 
		if (heap[i] > x && heap[i] < min) {
 
			min = heap[i];
 
			minindex = i;
 
		}
 
 
 
	}
 
	cout << minindex << endl;
 
}
 
 
 
int main()
 
{
    int a1,a2,M;
 
	cin >> M;
 
	char order[20];
 
	for (int i = 0; i < M; ++i) {
 
		cin >> order;
 
 
 
		cin >> a1;
 
		if (order[0] == 'i') inser(a1);
 
		else if (order[0] == 'f') find(a1);
 
		else if (order[0] == 'd') {
 
 
			cin >> a2;
 
			decrease(a1, a2);
 
		}
 
	}
 
	return 0;
 
}
