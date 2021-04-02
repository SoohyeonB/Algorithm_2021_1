#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h> //sleep 함수 사용하기 위한 헤더파일

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
void insertion_sort(int list[], int n) {
	int key, tmp;
	for (int i = 1; i < n; i++) {
		key = list[i];
		int j = i - 1;
		while ((j >= 0) && (list[j] > key)) {
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
	}
}

void main() {
	int list01[MAX_SIZE];
	int list02[MAX_SIZE];

	srand(time(NULL));	//seed rand
	for (int i = 0; i < MAX_SIZE; i++) {
		list01[i] = rand() % 100; //0~99까지 발생
		list02[i] = rand() % 100; //0~99까지 발생

		for (int j = 0; j < i; j++) { //중복허용하지 않고 임의의 수 발생
			if (list01[i] == list01[j])
				i--;
			if (list02[i] == list02[j])
				i--;
		}
	}

	//새로 만든 리스트 출력
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list01[i]);
	}
	printf("\n"); 
	printf("selection sort\n");

	//selection sort
	selection_sort(list01, MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list01[i]);
	}
	printf("\n\n");

	printf("insertion sort\n");
	//insertion sort
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list02[i]);
	}
	insertion_sort(list02, MAX_SIZE);
	printf("\n");

	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list02[i]);
	}
}