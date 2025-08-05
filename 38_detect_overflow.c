#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void check_range_error(int a, int b)
{
	if (b > 0 && a > INT_MAX - b)
		printf("Operation will overflow\n");
	if (b < 0 && a < INT_MAX - b)
		printf("Operation will underflow\n");
}

int main(int argc, char **argv)
{
	int a1;
	int b1;
	int a2;
	int b2;
	int res;
	bool range_error;

	a1 = INT_MAX - 10;
	b1 = 3245;
	a2 = INT_MIN + 10;
	b2 = -3245;
	check_range_error(a1, b1);
	printf("%d + %d = %d\n", a1, b1, a1 + b1);
	check_range_error(a2, b2);
	printf("%d + %d = %d\n", a2, b2, a2 + b2);

	/* Using compiler built-in checks */
	range_error = __builtin_add_overflow(a1, b1, &res);
	printf("Range error: %d\n", range_error);
	printf("%d + %d = %d\n", a1, b1, res);

	range_error = __builtin_add_overflow(a2, b2, &res);
	printf("Range error: %d\n", range_error);
	printf("%d + %d = %d\n", a2, b2, res);

	range_error = __builtin_sub_overflow(a2, b2, &res);
	printf("Range error: %d\n", range_error);
	printf("%d - %d = %d\n", a2, b2, res);

	range_error = __builtin_mul_overflow(a1, b1, &res);
	printf("Range error: %d\n", range_error);
	printf("%d * %d = %d\n", a1, b1, res);
	return 0;
}
