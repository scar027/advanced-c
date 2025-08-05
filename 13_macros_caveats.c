#include <stdio.h>

#define MUL(x, y) ((x) * (y))
#define SUM_RANGE(start, end)                     \
	/* do */ {                                \
		int x;                            \
		int sum = 0;                      \
                                                  \
		for (x = (start); x < (end); x++) \
			sum += x;                 \
		printf("The sum is: %d\n", sum);  \
	} /* while(0) */

int main(int argc, char **argv)
{
	int sum = 0;

	printf("MUL(2 + 5, 2 + 3 * 2 - 5) = %d\n", MUL(2 + 5, 2 + 3 * 2 - 5));
	printf("sum variable with value %d doesn't conflict with "
	       "sum variable of SUM_RANGE now.\n",
	       sum);
	SUM_RANGE(1, 5 * 2);
	return 0;
}
