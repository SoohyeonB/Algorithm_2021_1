#include <stdio.h>
#include <stdlib.h>
/*생일케이크 문제 연결리스트  ver 3*/
typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	L->head = NULL;
}
void printNode(LinkedListType *L) {
	ListNode* p = L->head;
	int n = 7;
	while (n>0) {
		printf("%d -> ", p->data);
		p = p->link;
		n--;
	}
	printf("\n");
}

ListNode* getNode() {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	return p;
}

LinkedListType* buildList(LinkedListType *L, int n) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	L->head = p;
	p->data = 1;
	for (int i = 2; i <=n; i++) {
		p->link = getNode();
		p = p->link;
		p->data = i;
	}
	p->link = L->head;
	return L;
}
int runSimulation(LinkedListType* L, int n, int k) {
	ListNode* p = L->head;
	ListNode* pnext = p->link;

	while (p != p->link) {
		printNode(L);

		for (int i = 1; i < k; i++)
			p = p->link;
		pnext = p->link;
		p->link = (p->link)->link;
		free(pnext);
		p = p->link;
	}
	return p->data;
}

int candle(LinkedListType*L, int n, int k) {
	L = buildList(L, n);
	return runSimulation(L, n, k);
}

void main() {
	LinkedListType list;
	init(&list);
	int n = 7; int k = 3;

	printf("%d",candle(&list, n, k));
}