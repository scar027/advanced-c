#include <stdio.h>

int main(int argc, char **argv)
{
	int a;
	const int *ptr1;
	int *const ptr2 = &a;
	const int *const ptr3 = &a;

	a = 34;
	ptr1 = &a;
	printf("Pointer to const: can modify pointer but not data: %p\n",
	       (void *)(ptr1++));

	printf("Const pointer: can modify data but not pointer: %d\n",
	       (*ptr2)++);

	printf("Const pointer to const: neither can be modified: %p\n",
	       (void *)ptr3);
	return 0;
}
