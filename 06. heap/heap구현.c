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

void main() {
	HeapType heap;
	init(&heap);
	insertItem(&heap, 5);
	insertItem(&heap, 7);
	insertItem(&heap, 3);
	insertItem(&heap, 4);
	insertItem(&heap, 1);

	printHeap(&heap);
}