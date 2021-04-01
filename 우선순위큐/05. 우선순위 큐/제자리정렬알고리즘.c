#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x,y,t)((t)=(x), (x)=(y), (y)=(t))

void selection_sort(int list[], int n) {
	int minLocation, temp;
	for (int i = 0; i < n - 1; i++) {
		minLocation = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[minLocation])
				minLocation = j;
		SWAP(list[i], list[minLocation], temp);
	}
}

void main() {
	int list[MAX_SIZE];
	srand(time(NULL));	//seed rand
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i] = rand() % 100; //0~99까지 발생
		for (int j = 0; j < i; j++) //중복허용하지 않고 임의의 수 발생
			if (list[i] == list[j])
				i--;
	}

	//출력
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n"); getchar();
}