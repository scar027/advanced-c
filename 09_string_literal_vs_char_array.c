#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *literal =
		"This string is immutable(stored in .rodata(read only data))";
	/* Mutable copy */
	char *s = strdup(literal);
	char array[] = "This string is mutable";

	s[0] = '$';
	array[0] = '@';
	printf("%s\n", s);
	printf("%s\n", array);
	return 0;
}
