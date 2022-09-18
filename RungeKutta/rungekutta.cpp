#include <stdio.h>

#define len 20

float fa(float b, float k, float m, float v, float x);
void rk(float b, float k, float m);

int main()
{
	float b, k, m;

	printf("input b : ");
	scanf("%f", &b);
	printf("input k : ");
	scanf("%f", &k);
	printf("input m : ");
	scanf("%f", &m);
	printf("\n");

	rk(b, k, m);
}

float fa(float b, float k, float m, float v, float x)
{
	float a;

	a = -(b * v + k * x) / m;

	return a;
}

void rk(float b, float k, float m)
{
	float dt = 0.01;

	float t[len + 1] = { 0. };
	float v[len + 1] = { 0. };
	float x[len + 1] = { 0. };

	float kv1, kv2, kv3, kv4;
	float kx1, kx2, kx3, kx4;

	x[0] = 0.1;

	for (int i = 0; i < len; i++)
	{
		kv1 = fa(b, k, m, v[i], x[i]) * dt;
		kx1 = v[i] * dt;

		kv2 = fa(b, k, m, v[i] + (kv1 / 2), x[i] + (kx1 / 2)) * dt;
		kx2 = (v[i] + (kv1 / 2)) * dt;

		kv3 = fa(b, k, m, v[i] + (kv2 / 2), x[i] + (kx2 / 2)) * dt;
		kx3 = (v[i] + (kv2 / 2)) * dt;

		kv4 = fa(b, k, m, v[i] + kv3, x[i] + kx3) * dt;
		kx4 = (v[i] + kv3) * dt;

		t[i + 1] = t[i] + dt;
		v[i + 1] = v[i] + ((1.0 / 6.0) * (kv1 + 2 * kv2 + 2 * kv3 + kv4));
		x[i + 1] = x[i] + ((1.0 / 6.0) * (kx1 + 2 * kx2 + 2 * kx3 + kx4));

		printf("result t%d: %f  v%d: %f  x%d: %f\n\n", i, t[i], i, v[i], i, x[i]);
	}
}