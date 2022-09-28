#define SIZE 4
#include <stdio.h>

// 출력함수
void printMatrix(int m[][SIZE]) {
	printf("----- 출력 -----\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%5d", m[i][j]);
		}
		printf("\n");
	}
}
// 입력함수
void setMatrix(int m[][SIZE]) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("[%d][%d] : 입력\n", i, j);
			scanf("%d", &m[i][j]);
		}
		if (j != SIZE)
			printf("mA[%d][%d] : 입력\n", i, j);
	}
}
//계산 함수 
void calcMatrix(int a[][SIZE], int b[][SIZE], int c[][SIZE]) {
	int k, temp;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			temp = 0;
			for (k = 0; k < SIZE; k++) {
				temp += (a[i][k] * b[k][j]);
			}
			c[i][j] = temp;
		}
	}
}
int main(void) {
	int mA[SIZE][SIZE] = { 0 };
	int mB[SIZE][SIZE] = { 0 };
	int mC[SIZE][SIZE] = { 0 };

	while (1) {
		printf("mA 입력");
		setMatrix(mA);
		printf("mB 입력");
		setMatrix(mB);

		printf("mA 출력");
		printMatrix(mA);
		printf("mB 출력");
		printMatrix(mB);
		calcMatrix(mA, mB, mC);

		printf("mC 출력");
		printMatrix(mC);
	}
	return 0;
}