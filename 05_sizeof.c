#include <stdio.h>

#define MAX_ARRAY_LEN 5

int main(int argc, char **argv)
{
	int x;
	int a[MAX_ARRAY_LEN] = { 1, 2, 3, 4, 5 };
	int *ptr_to_array;

	X = 1;
	ptr_to_array = a;
	printf("\nSize of variable(type)\n");
	printf("%zu\n", sizeof x);

	printf("\nSize of Array(total bytes)\n");
	printf("%zu\n", sizeof a);

	printf("\nLength of Array\n");
	printf("%zu\n", sizeof a / sizeof a[0]);

	printf("\nSize of pointer to array(CAUTION!)\n");
	printf("%zu\n", sizeof ptr_to_array);
	return 0;
}
