#include <stdio.h>

float alpha;
float prevX = 0;

float lpf(float prev, float x) {
	float x_lpf;

	x_lpf = alpha * prevX + (1 - alpha) * x;

	prevX = x_lpf;
	return x_lpf;
}

int main(void) {
	float num;
	printf("weight : ");
	scanf_s("%f", &alpha);

	while (1) {
		printf("input : ");
		scanf_s("%f", &num);
		printf("%.2f\n", lpf(prevX, num));
	}
}
