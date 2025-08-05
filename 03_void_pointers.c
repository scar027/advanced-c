#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define MAX_ARRAY_SIZE 5

void *memset_function(void *data, uint8_t c, size_t n)
{
	uint8_t *data_as_bytes;
	size_t i;

	data_as_bytes = (uint8_t *)data;
	for (i = 0; i < n; i++) {
		data_as_bytes[i] = c;
	}
	return data;
}

void map(void *a, size_t n, size_t size, void (*function)(void *))
{
	uint8_t *a_as_bytes;
	size_t i;

	a_as_bytes = (uint8_t *)a;
	for (i = 0; i < n; i++) {
		function(&a_as_bytes[i * size]);
	}
}

void square(void *x)
{
	int *p;

	p = (int *)x;
	*p = *p * *p;
}

int main(int argc, char **argv)
{
	int a[MAX_ARRAY_SIZE] = { 1, 2, 3, 4, 5 };
	size_t n;
	size_t i;

	n = sizeof(a) / sizeof(a[0]);
	printf("\nExample array\n");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	/* Square every element of a */
	map(a, n, sizeof(int), square);
	printf("\nSquaring elements of the array\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	/* Set all bytes in concerned memory to -1 */
	memset_function(a, -1, sizeof(a));
	printf("\nArray after applying memset\n");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
