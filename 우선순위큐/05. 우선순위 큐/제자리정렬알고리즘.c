#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h> //sleep 함수 사용하기 위한 헤더파일

#define MAX_SIZE 4
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



//insertion하는거 꼴보기 싫어서 insertion의 탈을 쓴 swap함수
void insertion_to_swap_sort(int list[], int n) {
	int key, tmp;
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], tmp);
		}
	}
}
void bubble_sort(int list[], int n) {
	int tmp;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], tmp);
		}
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

void inc_insertion_sort(int list[], int start, int n, int gap) {
	int key, tmp;
	for (int i = start+gap; i <= n; i+=gap) { //start 이후로 쭉
		key = list[i];
		int j = i - gap;
		while ((j >= 0) && (list[j] > key)) {
			list[j + gap] = list[j];
			j-= gap;
		}
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n) {
	
	for (int gap = n / 2; gap > 0; gap /= 2) {
		if (gap % 2 == 0)  //이해가 안가....
			gap++;
		for (int i = 0; i < gap; i++) {  //0,1,2,...
			inc_insertion_sort(list, i, n-1, gap);
		}
	}
}


void main() {
	int list01[MAX_SIZE];
	int list02[MAX_SIZE];
	int list_shell[MAX_SIZE];

	

	srand(time(NULL));	//seed rand
	for (int i = 0; i < MAX_SIZE; i++) {
		list01[i] = rand() % 100; //0~99까지 발생
		list02[i] = rand() % 100; //0~99까지 발생
		list_shell[i] = rand() % 100; //0~99까지 발생


		for (int j = 0; j < i; j++) { //중복허용하지 않고 임의의 수 발생
			if (list01[i] == list01[j])
				i--;
			if (list02[i] == list02[j])
				i--;
			if (list_shell[i] == list_shell[j])
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
	//selection_sort(list01, MAX_SIZE);
	insertion_to_swap_sort(list01, MAX_SIZE);

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

	printf("\n");
	printf("\n");


	//shell sort
	printf("shell sort\n");

	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list_shell[i]);
	}
	printf("\n");
	shell_sort(list_shell, MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list_shell[i]);
	}
}