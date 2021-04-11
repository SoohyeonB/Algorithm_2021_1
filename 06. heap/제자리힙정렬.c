#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 1. 제자리 힙정렬 알고리즘 (수도코드 그대로)
*  2. 상향 힙정렬
*/
#define MAX_ELEMENT 100
struct Heap {
	int H[MAX_ELEMENT];
	int n;	//원소의 개수
}_Heap;  //전역으로 구조체 선언


//위에서부터 아래로 내려가면서 heap정렬해주는 함수
void downHeap(int i) {
	if (i * 2 > _Heap.n) return;  //i의 자식노드가 힙의 크기를 넘어가므로, 자식노드가 없다고 생각하면 됨
	if (_Heap.H[i] < _Heap.H[i * 2] || _Heap.H[i] < _Heap.H[i * 2] + 1) {//최대힙이므로
		//위치 이동 필요
		if (_Heap.H[i * 2] > _Heap.H[i * 2 + 1]) {  //왼>오 이면 swap (왼, 부모)
			int temp;
			temp = _Heap.H[i];
			_Heap.H[i] = _Heap.H[i * 2];
			_Heap.H[i * 2] = temp;
			downHeap(i * 2);
		}
		else { //왼<오
			int temp;
			temp = _Heap.H[i];
			_Heap.H[i] = _Heap.H[i * 2 + 1];
			_Heap.H[i * 2 + 1] = temp;
			downHeap(i * 2 + 1);
		}
	}
	else
		return;
}


void upHeap(int i) {
	int i = h->heap_size;
	int key = h->heap[i];
	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;

}
void buildHeap() {
	/*for (int i = 1; i <= (_Heap.n); i++)
		insertItem();  아 왜 자꾸 자기 마음대로 구현하지?*/
	for (int i = _Heap.n / 2; i >= 1; i--)
		downHeap(i);
}

//상향식 힙생성 재귀적 구현
void rbuildHeap(int i) {
	if (i > _Heap.n)
		return;
	if (i * 2 <= _Heap.n)
		rbuildHeap(2 * i);
	if (i * 2 + 1 <= _Heap.n)
		rbuildHeap(2 * i + 1);
	downHeap(i);
}

int removeMax() {
	int key = _Heap.H[1];
	_Heap.H[1] = _Heap.H[_Heap.n--];  //맨마지막 원소를 맨 앞에 넣음
	downHeap(1);
	return key;
}

void inPlaceHeapSort() {
	int size = _Heap.n; 
	int key;
	for (int i = 0; i < size; i++) {
		key = removeMax();
		_Heap.H[_Heap.n + 1] = key;  //heap size늘려서 새로운 키값 넣음
	}
}

void printHeap() {
	for (int i = 1; i <= _Heap.n; i++)
		printf("[%d] ", _Heap.H[i]);
	printf("\n");
}
void printArray() {
	for (int i = 1; _Heap.H[i] > 0; i++) {
		printf("[%d] ", _Heap.H[i]);
	}
	printf("\n");
}

void main() {
	_Heap.n = 0;
	srand(time(NULL));

	printf("입력할 원소의 개수: ");
	scanf_s("%d", &_Heap.n);
	//리스트 만들기
	for (int i = 1; i <= _Heap.n; i++) {
		_Heap.H[i] = rand() % 100;
	}
	printHeap();

	buildHeap();
	printHeap();
	getch();
	inPlaceHeapSort();
	printArray();
}