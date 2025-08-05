#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	int64_t a = 9223372036854775807;
	int b = 0xFFAA01BB;
	int c = 0755;
	int d = 0b01010101;

	printf("Signed 64 bit integer: %ld\n", a);
	printf("Hexadecimal: %x\n", b);
	printf("Octal: %o\n", c);
	printf("Binary: %b\n", d);
	return 0;
}
