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
	for (l = left; l <= right; l++) //임시에서 최종 리스트로 복사
		list[l] = sorted[l];

}

void merge_sort(int list[], int left, int right) {
	int m;
	if (left < right) { //분할 가능하면
			m = (left + right) / 2;//분할
		merge_sort(list, left, m);  //재귀
		merge_sort(list, m+1, right);
		merge(list, left, m, right);  //통치
	}
}



void main() {
	srand(time(NULL));

	int list[MAX_SIZE];
	int j;
//리스트 만들기
//얘는 앞뒤만 다르면 되니까 중복 발생 가능
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i] = rand() % 100;
		j = i-1;
		if (list[i] == list[j])
			i--;
	}
//얘는 모든 원소를 다 비교하니까 중복 발생 불가능
for (int i = 0; i < MAX_SIZE; i++) 
   {
      list[i] = rand() % 100;
      for (int j = 0; j < i; j++)
         if (list[i] == list[j])
            i--;   //중복 없는 배열
   }
//리스트 출력하기
	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n"); getch();
//합병정렬
	merge_sort(list, 0, MAX_SIZE - 1);
//리스트 출력하기
	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n"); getch();
}
