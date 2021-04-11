#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct {
	int heap[MAX];
	int heap_size;
}HeapType;

void init(HeapType * h) {
	h->heap_size = 0;
}

void upHeap(HeapType *h) {
	int i = h->heap_size;
	int key = h->heap[i];
	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}
void downHeap(HeapType* h) {
	int temp = h->heap[1];
	int parent = 1, child = 2;
	while (child >= h->heap_size) {
		if((child< h->heap_size)&& (h->heap[child]>h->heap[parent]))
			child++;
		if (temp <= h->heap[child])
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
}

void insertItem(HeapType* h, int key) {
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);
}

void printHeap(HeapType *h) {
	for (int i = 1; i <= h->heap_size; i++) {
		printf("[%d] ", h->heap[i]);
	}
	printf("\n");
}

int removeMin(HeapType* h) {
	int key = h->heap[1];
	h->heap[1] = h->heap[h->heap_size];
	h->heap_size--;
	downHeap(h);
	return key;
}

void heapSort(HeapType* h, int list[]) {
	HeapType temp;
	init(&temp);
	for (int i = 1; i <= h->heap_size; i++) {
		temp.heap[i] = h->heap[i];
		temp.heap_size++;
	}
	for (int i = 1; i <= h->heap_size; i++) {
		list[i] = removeMin(&temp);
	}
}

void printArr(int list[], int n) {
	for (int i = 1; i <= n; i++)
		printf("[%d] ", list[i]);
	printf("\n");
}
void main() {
	HeapType heap;
	int list[MAX] = { 0 };
	init(&heap);
	insertItem(&heap, 5);
	insertItem(&heap, 7);
	insertItem(&heap, 3);
	insertItem(&heap, 4);
	insertItem(&heap, 1);

	printHeap(&heap);

	removeMin(&heap);
	printHeap(&heap);


	heapSort(&heap, list);
	printArr(list, heap.heap_size);

}