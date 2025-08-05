#include <stdio.h>

struct struct_with_bit_field {
	int first_4 : 4;
	int next_4 : 4;
	int alone : 1;
	int reset : 7;
};

int main(int argc, char **argv)
{
	printf("\nSize of struct\n");
	printf("%zu\n", sizeof(struct struct_with_bit_field));

	struct struct_with_bit_field a;
	a.first_4 = 2;
	a.next_4 = 4;
	a.alone = 1;
	printf("\nFields\n");
	printf("first_4(4 bits): %d\n", a.first_4);
	printf("next_4(4 bits): %d\n", a.next_4);
	/* Print statement below prints -1 since first bit is for sign in int type */
	printf("alone(1 bit): %d\n", a.alone);
	return 0;
}
