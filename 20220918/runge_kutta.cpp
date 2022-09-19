#include <stdio.h>

float fa(float b, float k, float m, float v, float x);
void rk(float b, float k, float m, int cnt, float dt);

float x[] = { 0.0 };
float v[] = { 0.0 };

int main()
{
	float b, k, m, t0, t1, v0, x0, h;

	printf("input b : ");
	scanf("%f", &b);
	printf("input k : ");
	scanf("%f", &k);
	printf("input m : ");
	scanf("%f", &m);
	printf("input t0 : ");
	scanf("%f", &t0);
	printf("input t1 : ");
	scanf("%f", &t1);
	printf("input v0 : ");
	scanf("%f", &v0);
	printf("input x0 : ");
	scanf("%f", &x0);
	printf("input h : ");
	scanf("%f", &h);
	printf("\n");

	v[0] = v0;
	x[0] = x0;

	int len = t1 - t0;

	rk(b, k, m, len, h);

	return 0;
}

float fa(float b, float k, float m, float v, float x)
{
	return -(b * v + k * x) / m;
}

void rk(float b, float k, float m, int cnt, float dt)
{
	float kv1, kv2, kv3, kv4, kx1, kx2, kx3, kx4;

	for (int i = 0; i < cnt; i++)
	{
		kv1 = fa(b, k, m, v[i], x[i]) * dt;
		kx1 = v[i] * dt;

		kv2 = fa(b, k, m, v[i] + (kv1 / 2), x[i] + (kx1 / 2)) * dt;
		kx2 = (v[i] + (kv1 / 2)) * dt;

		kv3 = fa(b, k, m, v[i] + (kv2 / 2), x[i] + (kx2 / 2)) * dt;
		kx3 = (v[i] + (kv2 / 2)) * dt;

		kv4 = fa(b, k, m, v[i] + kv3, x[i] + kx3) * dt;
		kx4 = (v[i] + kv3) * dt;

		v[i + 1] = v[i] + dt * ((1.0 / 6.0) * (kv1 + 2 * kv2 + 2 * kv3 + kv4));
		x[i + 1] = x[i] + dt * ((1.0 / 6.0) * (kx1 + 2 * kx2 + 2 * kx3 + kx4));

		printf("result x%d: %f  v%d: %f\n\n", i + 1, x[i + 1], i + 1, v[i + 1]);
	}
}