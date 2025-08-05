#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/stdlib.h>
#include <search.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

int compare_str(const void *v1, const void *v2)
{
	char *s1 = *(char **)v1;
	char *s2 = *(char **)v2;
	return strcmp(s1, s2);
}

int compare_int(const void *v1, const void *v2)
{
	int x1 = *(int *)v1;
	int x2 = *(int *)v2;
	return x1 - x2;
}

int main(int argc, char **argv)
{
	char *strings[] = { "foo", "bar", "baz", "qux", "quux", "corge" };
	int a[] = { 3, 2, 1, 4, 5 };
	int b[] = { 3, 2, 1, 4, 5 };
	int c[] = { 3, 2, 1, 4, 5 };
	int d[] = { 3, 2, 1, 4, 5 };
	int x;
	size_t len;
	void *res1;
	void *res2;
	void *res3;
	int i;

	printf("Initial strings array: \n");
	for (i = 0; i < ARRAY_SIZE(strings); i++)
		printf("%d: %s\n", i, strings[i]);
	printf("Sorted strings array: \n");
	qsort(strings, ARRAY_SIZE(strings), sizeof(strings[0]), compare_str);
	for (i = 0; i < ARRAY_SIZE(strings); i++)
		printf("%d: %s\n", i, strings[i]);

	printf("Initial int array: \n");
	for (i = 0; i < ARRAY_SIZE(a); i++)
		printf("%d: %d\n", i, a[i]);

	/* Sorting functions */
	printf("Sorted int array(qsort()): \n");
	qsort(a, ARRAY_SIZE(a), sizeof(a[0]), compare_int);
	for (i = 0; i < ARRAY_SIZE(a); i++)
		printf("%d: %d\n", i, a[i]);

	printf("Sorted int array(mergesort()): \n");
	mergesort(b, ARRAY_SIZE(b), sizeof(b[0]), compare_int);
	for (i = 0; i < ARRAY_SIZE(b); i++)
		printf("%d: %d\n", i, b[i]);

	printf("Sorted int array(heapsort()): \n");
	heapsort(c, ARRAY_SIZE(c), sizeof(c[0]), compare_int);
	for (i = 0; i < ARRAY_SIZE(c); i++)
		printf("%d: %d\n", i, c[i]);

	/* Searching functions */
	x = 4;
	res1 = bsearch(&x, a, ARRAY_SIZE(a), sizeof(a[0]), compare_int);
	if (res1)
		printf("Binary search: %p, %d\n", res1, *(int *)res1);
	else
		printf("Binary search: Element not found.\n");

	len = ARRAY_SIZE(d);
	res2 = lfind(&x, d, &len, sizeof(d[0]), compare_int);
	if (res2)
		printf("Linear search(lfind()): %p, %d\n", res2, *(int *)res2);
	else
		printf("Linear search(lfind()): Element not found.\n");

	/* 
         * lsearch() is also a linear search algorithm but it mutates array
         * i.e searches & inserts if not found.
         */
	res3 = lsearch(&x, d, &len, sizeof(d[0]), compare_int);
	if (res3)
		printf("Linear search(lsearch()): %p, %d\n", res3,
		       *(int *)res3);
	else
		printf("Linear search(lsearch()): Element not found.\n");
	return 0;
}
