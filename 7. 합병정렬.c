#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> //이건 왜 해주는거지?
#include <time.h>

#define MAX_SIZE 15
int sorted[MAX_SIZE];
void merge(int list[], int left, int m, int right) {
	int i = left; //왼쪽 list의 left
	int k = left; //새로운 list의 left
	int j = m + 1;  //오른쪽 list의 left
	int l;
	while (i <= m && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > m) //왼쪽 list가 오른쪽 list보다 크기가 클 때 
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= m; l++)
			sorted[k++] = list[l];
	for (l = left; l <= right; l++)
		list[l] = sorted[l];

}

void merge_sort(int list[], int left, int right) {
	int m;
	if (left < right) {
		m = (left + right) / 2;
		merge_sort(list, left, m);
		merge_sort(list, m+1, MAX_SIZE);
		merge(list, left, m, right);
	}
}



void main() {
	srand(time(NULL));

	int list[MAX_SIZE];
	int j;
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i] = rand() % 100;
		j = i-1;
		if (list[i] == list[j])
			i--;
	}

	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n"); getch();

	merge_sort(list, 0, MAX_SIZE - 1);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", sorted[i]);
	printf("\n\n"); getch();
}
