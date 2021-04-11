#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct {
	int heap[MAX]; 
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

//heap에 새로운 노드를 삽입하고 min heap으로 정렬해주는 함수
void upHeap(HeapType* h) {
	int i = h->heap_size;
	int key = h->heap[i]; //제일 마지막 노드에 key값 넣고
	//다시 올라가면서 heap 정렬해줌
	while ((i != 1) && (key < h->heap[i / 2])) {
		//윗 노드보다 key값이 윗노드보다 작을때while문 계속 돎
		h->heap[i] = h->heap[i / 2]; //i번째 노드에 i의 부모노드의 키값 저장
		i /= 2;	//i는 부모로 또 한칸 올라감
	}
	h->heap[i] = key; //이제 더이상 부모노드보다 작지 않을때 해당 i번째 노드에 새로 삽입한 친구 넣어줌
	
}


void downHeap(HeapType* h) {
	int temp = h->heap[1];
	int parent = 1, child = 2;
	while (child >= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] > h->heap[parent]))
			child++;
		if (temp <= h->heap[child])
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
}

//주어진 최소힙에 새로운 노드 삽입
void insertItem(HeapType* h, int key) {
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);
}

void printHeap(HeapType* h) {
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
		//list라는 새로운 배열을 만들어서 거기다가 넣어줬었음
	}
}

void printArr(int list[], int n) {
	for (int i = 1; i <= n; i++)
		printf("[%d] ", list[i]);
	printf("\n");
}

//제자리 정렬 함수 
void inPlaceHeapSort(HeapType* h) {
	int size = h->heap_size;
	int key;
	for (int i = 0; i < size; i++) {
		key = removeMin(h); //heap에서 최솟값을 꺼내서
		h->heap[h->heap_size + 1] = key; //
	}
}
void main() {
	HeapType heap;
	int list[MAX] = { 0 };
	
	srand(time(NULL));
	init(&heap);

	//1. heap 생성
	for (int i = 0; i < 15; i++) {
		insertItem(&heap, rand() % 100);
	}
	printHeap(&heap);

	//이번에는 별도의 배열을 만들지 않고 원래의 배열에서 
	//제자리 정렬을 해 줄 것임!
	inPlaceHeapSort(&heap);
	//정렬됐는지 확인
	for (int i = 1; i < heap.heap[i]>0; i++)
		printf("[%d] ", heap.heap[i]);
}