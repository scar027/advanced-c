#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_ARRAY_LEN 10

int add(int x, int y)
{
	return x + y;
}

bool check_odd(int x)
{
	return x % 2 == 1;
}

void function_with_function_parameter(int a[MAX_ARRAY_LEN],
				      bool (*condition)(int))
{
	size_t i;

	for (i = 0; i < MAX_ARRAY_LEN; i++) {
		if (condition(a[i])) {
			printf("%d\n", a[i]);
		}
	}
}

int custom_compare(const void *x1, const void *x2)
{
	return (*(int *)x1 - *(int *)x2);
}

int main(int argc, char **argv)
{
	int a[MAX_ARRAY_LEN] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int (*add_function_pointer)(int, int);
	int b[MAX_ARRAY_LEN] = { 1, 3, 2, 5, 4, 6, 8, 7, 10, 9 };
	size_t i;

	add_function_pointer = add;
	printf("\nExample 1: Function pointer usage\n");
	printf("%d\n", add_function_pointer(5, 6));

	printf("\nExample 2: Function as parameter\n");
	function_with_function_parameter(a, check_odd);

	printf("\nExample 3: Sorting with custom comparator\n");
	printf("Array before sorting: \n");
	for (i = 0; i < 10; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	qsort(b, 10, sizeof(int), custom_compare);
	printf("Array after sorting: \n");
	for (i = 0; i < 10; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}
