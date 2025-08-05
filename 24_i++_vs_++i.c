#include <stdio.h>

int main(int argc, char **argv)
{
	int a[5] = { 1, 2, 3, 4, -1 };
	int i;

	printf("Post-increment: \n");
	i = 0;
	while (a[i] != -1)
		printf("%d ", a[i++]);
	printf("\n");

	printf("Pre-increment: \n");
	i = 0;
	while (a[i] != -1)
		printf("%d ", a[++i]);
	printf("\n");
	/* Note: i += 1 is equivalent to ++i */
	return 0;
}
