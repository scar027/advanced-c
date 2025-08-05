#include <stdio.h>

enum flags {
	FLAG_A = (1U << 0),
	FLAG_B = (1U << 1),
	FLAG_C = (1U << 2),
	FLAG_D = (1U << 3)
};

int function_using_bit_flags(int x, enum flags flag)
{
	if (flag & FLAG_A) {
		x += 10;
		/* Unset FLAG_D when FLAG_A is used for demonstration*/
		flag &= ~FLAG_D;
	}
	if (flag & FLAG_B) {
		x += 20;
	}
	if (flag & FLAG_C) {
		x += 30;
	}
	if (flag & FLAG_D) {
		x -= 10;
	}
	return x;
}

int main(int argc, char **argv)
{
	printf("\nExample 1: No flags\n");
	printf("%d\n", function_using_bit_flags(1000, 0));

	printf("\nExample 2: FLAG_A set\n");
	printf("%d\n", function_using_bit_flags(1000, FLAG_A));

	printf("\nExample 3: FLAG_B & FLAG_C set\n");
	printf("%d\n", function_using_bit_flags(1000, FLAG_B | FLAG_C));

	printf("\nExample 4: FLAG_A & FLAG_B & FLAG_D set\n");
	printf("%d\n",
	       function_using_bit_flags(1000, FLAG_A | FLAG_B | FLAG_D));
	return 0;
}
