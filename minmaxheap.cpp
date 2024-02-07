#include <iostream>
using namespace std;

class maxheap {
	int size;
	int* arr;
public:
	maxheap(int size) {
		this->size = size;
		this->arr = new int[size];

		for (int i = 0; i < size; i++) cin >> arr[i];
	}
	// Iterative //
	void heapify() {

		for (int i = 0; i < size; i++) {
			int j = i;

			while (arr[(j - 1) / 2] < arr[j]) {
				swap(arr[(j - 1) / 2], arr[j]);
				j = (j - 1) / 2;
			}
		}
	}
	// recursive //
	void heapify(int i) {
		if (i == 0) {
			return;
		}

		if (arr[(i - 1) / 2] < arr[i]) {
			swap(arr[(i - 1) / 2], arr[i]);
		}
		heapify((i - 1) / 2);
	}
	void Start() {

		for (int i = 0; i < size; i++) {
			heapify(i);
		}
	}
	void print() {

		for (int i = 0; i < size; i++) {
			cout << arr[i] << "    ";
		}
	}
	
};
int main() {
	maxheap heap(5);
	heap.print();
	cout << endl;
	cout << "After Heapify :   ";
	cout << endl;
	heap.Start();
	heap.print();
}
