#include <iostream>

using namespace std;

const int max_len = 1e4 + 7;

int heap[max_len];

int top = 1;



void swap(int &a, int &b) {

    int temp = a;

    a = b;

    b = temp;

}



void insert(int n) {

    heap[top++] = n;

    int temp = top - 1;

    while (temp != 1 && heap[temp] < heap[temp >> 1]) {

        swap(heap[temp], heap[temp >> 1]);

        temp >>= 1;

    }

}



int dequeue() {

    int temp = heap[1];

    heap[1] = heap[--top];

    int t = 1;

    while (t < top) {

        if ((t << 1) < top && (t << 1 | 1) < top) {

            if (heap[t] > heap[t << 1] || heap[t] > heap[t << 1 | 1]) {

                if (heap[t << 1] > heap[t << 1 | 1]) {

                    swap(heap[t], heap[t << 1 | 1]);

                    t = t << 1 | 1;

                } else {

                    swap(heap[t], heap[t << 1]);

                    t = t << 1;

                }

            } else

                break;

        } else if ((t << 1) < top) {

            if (heap[t] > heap[t << 1]) {

                swap(heap[t], heap[t << 1]);

                t = t << 1;

            } else

                break;

        } else

            break;

    }

    return temp;

}






int main() {
   int size;

    int a[max_len];

    int sum = 0;

    cin >> size;

    for (int i = 0; i < size; i++) {

        cin >> a[i];

        insert(a[i]);

    }



    while (top > 2) {

        int s = dequeue() + dequeue();

        sum += s;

        insert(s);

    }



    cout << sum;



    return 0;

}
