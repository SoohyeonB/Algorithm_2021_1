#include <stdio.h>
#include <stdlib.h>

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

int pop(StackType* stack) {
	return stack->stack[stack->size]; //맨마지막 노드 반환 (맨위)
}

void push(int i, StackType *stack) {
	stack->size++;
	for (int j = 1; j < stack->size; j++) {
		int tmp = stack->stack[j];
		stack->stack[j] = stack->stack[j + 1];
		stack->stack[j + 1] = tmp;
	}
	stack->stack[0] = i;
}

void binaryExpansion(int i, StackType* stack) {
	while (i >= 2) {
		push(i%2, &stack);
		i /= 2;
	}
	push(i, &stack);
	return;
}

int findLastNode(HeapType *heap, int size) {
	StackType* stack = (StackType*) malloc(sizeof(StackType));
	init_s(&stack);
	binaryExpansion(heap->size, &stack);
	int last = pop(&stack);
	while (stack->size != 0) {
		int bit = pop(&stack);
		if(bit ==0)

			//heap에 leftchild를 넣어줌
		else

	}
}

void main() {
	HeapType* heap;
	init_h(&heap); 

}