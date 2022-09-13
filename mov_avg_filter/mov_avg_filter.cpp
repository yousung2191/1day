#include <stdio.h>

#define SIZE 5

double num[SIZE + 1] = { 0, };

double mov_avg_filter(double prev_avg, double sample)
{
	double avg = 0.0;

	num[SIZE] = sample;

	avg = prev_avg + num[SIZE] / SIZE - num[0] / SIZE;

	for (int i = 0; i < SIZE; i++)
		num[i] = num[i + 1];

	printf("최근 입력된 %d개의 데이터 : ", SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("%.2lf ", num[i]);

	return avg;
}

int main(void)
{
	double prev_avg = 0.0;
	double input_num = 0.0;

	while (true)
	{
		printf("\n데이터 입력 : ");
		scanf_s("%lf", &input_num);

		prev_avg = mov_avg_filter(prev_avg, input_num);

		printf("\n최근 %d개 데이터의 평균 : %.2lf\n", SIZE, prev_avg);
	}

	return 0;
}

