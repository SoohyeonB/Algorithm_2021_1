#include <stdio.h>
#include <stdlib.h>

/*addLast, removeFirst, removeLast 함수 구현하기*/

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

void addFirst(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void add(LinkedListType* L, int pos, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;	//삽입할 바로 전의 노드까지 기억하기
	node->data = item; //삽입하고 싶은 노드 삽입
	node->link = before->link;
	before->link = node;
}

int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->data;
}


int removeNode(LinkedListType* L, int pos) {
	ListNode* removed = L->head;
	ListNode* p = L->head;
	int key;
	
	for (int i = 2; i < pos; i++) {
		p = p->link;
	}
	removed = p->link;
	if (removed == NULL)
		printf("The list is blank.\n");
	else {
		p->link = p->link->link;
		key = removed->data;
		free(removed);
		return key;
	}
	return 0;

}

int removeLast(LinkedListType* L) {
	ListNode* p = L->head;
	int key;
	if (p == NULL) {
		printf("The list is blank.\n");
		return 0;
	}
	while (p!= NULL) {
		p = p->link;
		if (p->link->link == NULL) {
			key = p->link->data;
			p->link = NULL;		//맨마지막 노드 이전 노드의 링크 삭제
			break;
		}
	}

	return key;
}

int removeFirst(LinkedListType* L) {
	ListNode* removed;

	if (L->head == NULL) return NULL;
	removed = L->head;
	L->head = removed->link;

	free(removed);
	return L->head->data;
}


void set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}

void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d] -> ", p->data);
	printf("NULL\n");
}

void main() {
	LinkedListType list;
	init(&list);

	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);

	printf("\n");
	add(&list, 1, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);
	printf("\n");

	printf("removed: %d  ",removeFirst(&list)); printList(&list);
	printf("removed: %d  ", removeLast(&list)); printList(&list);
	printf("removed: %d  ", removeNode(&list, 2)); printList(&list);

	int pos;
	printf("몇 번 노드의 값을 반환할까요?");
	scanf_s("%d", &pos); 
	printf("%d번 노드의 값은 %d\n", pos, get(&list, pos));

}