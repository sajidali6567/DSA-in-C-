#include<bits/stdc++.h>
using namespace std;

// utility function to swap two elements
void swap (int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}	


class MaxHeap {
	int* harr;
	int size;
	int capacity;
	public:
		MaxHeap(int cap);
		int Parent(int index);
		int LeftChild(int index);
		int RightChild(int index);
		void insert(int key);
		// to heapify a subtree with the root at given index
		void MaxHeapify(int i);
		void Print();
		void IncreaseKey(int i, int new_val);
};

MaxHeap::MaxHeap(int cap) {
	harr = new int[cap];
	capacity = cap;
	size = 0;
}

int MaxHeap::Parent(int index) {
	return ceil(index/2.0) - 1;
}

int MaxHeap::LeftChild(int index) {
	return 2*index+1;
}

int MaxHeap::RightChild(int index) {
	return 2*index+2;
}

void MaxHeap::insert(int key) {
	if (size == capacity) {
		cout << "cannot insert the key";
		return;
	}
	size++;
	// First insert the new key at the end
	int i = size-1;
	harr[i] = key;
	// Check if the MaxHeap property is violated
	while (Parent(i) >= 0 && harr[Parent(i)] < harr[i]) {
		swap(&harr[Parent(i)], &harr[i]);
		i = Parent(i);
	}
}

void MinHeap::Print() {
	for (int i = 0; i < size ; ++i) {
		cout << harr[i] << " ";
	}
}

void MaxHeap::IncreaseKey(int i, int new_val) {
	harr[i] = new_val;
	while (Parent(i) >= 0 && harr[Parent(i)] < harr[i]) {
		swap(&harr[Parent(i)], &harr[i]);
		i = Parent(i);
	}
}

void MaxHeap::MaxHeapify(int i) {
	if (i<0) return;
	int max = i;
	int leftChildIndex = LeftChild(i);
	if (leftChildIndex < size && harr[leftChildIndex] > harr[i]) {
		max = leftChildIndex;
	}
	int rightChildIndex = RightChild(i);
	if (rightChildIndex < size && harr[rightChildIndex] > harr[i]) {
		max = rightChildIndex;
	}
	if (i != max) {
		swap(&harr[i], &harr[max]);
		MaxHeapify(Parent(i));
	}
}

int main () {
	MinHeap h(10);
	h.insert(20);
	h.insert(10);
	h.insert(15);
	h.insert(5);
	h.insert(6);
	h.insert(12);
	h.insert(14);
	h.IncreaseKey(5, 40);
	//h.MaxHeapify(2);
	h.HeapSort();
	h.Print();
}