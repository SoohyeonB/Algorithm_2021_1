#include <stdio.h>
#include <stdlib.h>
/*생일케이크 문제 배열 ver 1*/

int A[7];
#define N 7

void buildList(int n) {   

    for (int r = 0; r < n; r++) {
        A[r] = r + 1;      //fill Array
    }
}

void printArray(int n) {
    printf("A = [");
    for (int i = 0; i < n; i++) {
        printf("%d, ", A[i]);
    }
    printf("] \n");
}

int runSimulation_ver1(int n, int k) {
    int r = 0;
    int num = 1;

    while (n > 1) {
        int i = 0;
        while (i < k) {
            r = (r + 1) % N;
            if (A[r] != 0)
                i++;
        }
        A[r] = 0;   //remove candle
        printArray(7, A);
        n = n - 1;
        while (A[r] == 0) {
            r = (r + 1) % N;
        }

    }
    return r;
}

//remove rth index
void removeIndex(int r) {

}

int runSimulation_ver2(int A[], int n, int k) {

    return 0;
}

int candle(int n, int k) {

    buildList(n);
    printArray(n);
    return runSimulation_ver1(n, k);
    //return runSimulation_ver2(A, n, k);
}



void main() {
    int n = 7; int k = 3;

    buildList(n);
    printArray(n);

    printf("candle: %d", candle(n, k));
}