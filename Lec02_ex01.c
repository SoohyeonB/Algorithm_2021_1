#include <stdio.h>
#include<stdlib.h>

//8p printDigits 재귀적 rprintDigits를 구동하여 양의 정수를 한 라인에 한 숫자씩 인쇄

void rPrintDigits(int n) {
	if (n < 10) printf("%d\n", n);
	else {
		rPrintDigits(n / 10);
		printf("%d\n", n % 10);
	}
}

void printDigits() {
	int n;
	scanf_s("%d", &n);
	if (n < 0)printf("write positive number");
	else {
		rPrintDigits(n);
	}
}


void main() {
	
	printDigits();
}