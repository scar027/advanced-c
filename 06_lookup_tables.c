#include <stdio.h>

enum keys { key_1 = 0, key_2, key_3 };

static int squares[] = { [key_2] = 4, [key_1] = 1, [key_3] = 9 };

static char case_convert[] = { ['A'] = 'a', ['B'] = 'b', ['C'] = 'c' };

int main(int argc, char **argv)
{
	printf("\nPrinting mapping\n");
	printf("%d\n", squares[key_1]);
	printf("%d\n", squares[key_2]);
	printf("%d\n", squares[key_3]);

	printf("%c\n", case_convert['A']);
	printf("%c\n", case_convert['B']);
	printf("%c\n", case_convert['C']);
	return 0;
}
