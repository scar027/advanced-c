#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>

int main(int argc, char **argv)
{
	int len = 5;
	int a[len];
	int *b;
	int *c;
	int i;

	/* 
         * Variable length array(NOT RECOMMENDED) as can overflow the limited
         * stack space
         */
	printf("Variable length array(stack): \n");
	for (i = 0; i < len; i++)
		a[i] = i * i * i;
	for (i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");

	/* 
         * alloca() - allocate automatically freed stack memory (NOT 
         * RECOMMENDED) 
         */
	printf("Variable length array(alloca()): \n");
	b = alloca(sizeof(int) * len);
	for (i = 0; i < len; i++)
		b[i] = i * i * i;
	for (i = 0; i < len; i++)
		printf("%d ", b[i]);
	printf("\n");

	/* malloc() */
	printf("Variable length array(malloc()): \n");
	c = malloc(sizeof(int) * len);
	for (i = 0; i < len; i++)
		c[i] = i * i * i;
	for (i = 0; i < len; i++)
		printf("%d ", c[i]);
	printf("\n");
	free(c);
	return 0;
}
