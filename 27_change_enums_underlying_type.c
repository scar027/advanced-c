#include <stdio.h>

enum enum1 { VAR_A, VAR_B };

/* Changing enum's underlying type available since C23 */
enum enum2 : short { VAR_C, VAR_D };

int main(int argc, char **argv)
{
	enum enum1 x;
	enum enum2 y;

	x = VAR_A;
	y = VAR_C;
	printf("Default enum size: sizeof(x) = %lu\n", sizeof(x));
	printf("Modified(short) enum size: sizeof(y) = %lu\n", sizeof(y));
	return 0;
}
