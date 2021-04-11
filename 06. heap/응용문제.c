#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
결과는 알맞게 원하는게 나왔는데 자꾸 크기 에러가 난다... 어디서 난걸까?
*/

#define MAX 100

typedef struct Heap {
	int heap[MAX];
	int size;
}HeapType;

typedef struct stack {
	int stack[MAX];
	int size;
}StackType;

void init_s(StackType* stack) {
	stack->size = 0;
}

void init_h(HeapType* heap) {
	heap->size = 0;
}

//stack
int pop(StackType* stack) {
	int anse = 2;
	if (stack->size == 0) return;
	else {
		anse = stack->stack[stack->size-1];
		stack->size--;
	}
	return anse;
}

void push(int i, StackType *stack) {
	return stack->stack[stack->size++] = i;
}

//heap
void upHeap(HeapType *heap) {
	int i = heap->size;
	int key = heap->heap[i];
	while ((i != 1) && (key < heap->heap[i / 2])) {
		heap->heap[i] = heap->heap[i / 2];
		i /= 2;
	}
	heap->heap[i] = key;
}

void insertItem(HeapType *heap, int node) {
	heap->size += 1;
	heap->heap[heap->size] = node;
	upHeap(heap);
}

void printHeap(HeapType *heap) {
	for (int i = 1; i <= heap->size; i++) {
		printf("[%d] ", heap->heap[i]);
	}
}

void printStack(StackType* s) {
	printf("-------stack-----------\n");
	for (int i = s->size-1; i >= 0; i--) {
		printf("%d\n", s->stack[i]);
	}
	
}

void binaryExpansion(int i, StackType* stack) {
	while (i >= 2) {
		push(i % 2, stack);
		i = i / 2;
	}
	push(i, stack);
}

int findLastNode(HeapType *heap, int size) {
	StackType* stack = (StackType*)malloc(sizeof(StackType));
	int i = 1;

	init_s(stack);

	binaryExpansion(heap->size, stack);
	printStack(stack);

	pop(stack);
	printStack(stack);
	//여기까지 제대로 됨

	
	int count = 1;
	while (stack->size != 0) {
		printf("findLastCode, %d번째 \n", count);
		count++;
		int bit = pop(stack);
		printf("bit ; %d\n", bit);
		printStack(stack);

		if (bit == 0)// leftchild로 이동
		{
			i = i * 2;
			printf("i = %d \n", i);

		}
		else if (bit == 1) {
			i = i * 2 + 1;
			printf("i = %d \n", i);
		}
		else {
			printf("%d \n", bit);
		}
	}
	return i;
		//heap->heap[i];  //마지막 노드의 값 반환
}

void main() {
	srand(time(NULL));
	HeapType heap;
	init_h(&heap); 
	//heap만들고
	for (int i = 1; i <= 10; i++) {
		insertItem(&heap, rand() % 50 + 1);
	}
	printHeap(&heap);
	//마지막 노드 반환

	printf("\n");
	printf("%d", findLastNode(&heap, 10));
}
