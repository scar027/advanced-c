#include <stdio.h>

int add_int(int a, int b)
{
	return a + b;
}

float add_float(float a, float b)
{
	return a + b;
}

double add_double(double a, double b)
{
	return a + b;
}

/* _Generic() available since C11 */
#define add(a, b)                             \
	_Generic((a),                         \
		int: add_int((a), (b)),       \
		float: add_float((a), (b)),   \
		double: add_double((a), (b)), \
		default: printf("Type not supported."))

int main(int argc, char **argv)
{
	int ai;
	int bi;
	float af;
	float bf;
	double ad;
	double bd;

	ai = 2;
	bi = 3;
	af = 3.14159F;
	bf = 1.61803F;
	ad = 3.33333;
	bd = 6.66666;
	printf("Integer: add(ai, bi) = %d\n", add(ai, bi));
	printf("Float: add(af, bf) = %f\n", add(af, bf));
	printf("Integer: add(ad, bd) = %f\n", add(ad, bd));
	return 0;
}
