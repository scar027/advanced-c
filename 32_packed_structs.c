#include <stdio.h>
#include <stdint.h>

struct demo {
	/* Random order of size causes compiler to put padding */
	int8_t a;
	int32_t c;
	int16_t b;
};

struct method1 {
	/* Descending order of size removes unnecessary padding */
	int32_t c;
	int16_t b;
	int8_t a;
};

struct method2 {
	/* Use compiler specific keyword to force removal of padding */
	int8_t a;
	int32_t c;
	int16_t b;
} __attribute__((packed));

void print_bytes(void *ptr, size_t size)
{
	uint8_t *f_as_bytes;
	size_t i;

	f_as_bytes = (uint8_t *)ptr;
	for (i = 0; i < size; i++) {
		printf("%02x ", f_as_bytes[i]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	struct demo d = {
		.a = 0x11,
		.b = 0x2222,
		.c = 0x33333333,
	};

	struct method1 m1 = {
		.a = 0x11,
		.b = 0x2222,
		.c = 0x33333333,
	};

	struct method2 m2 = {
		.a = 0x11,
		.b = 0x2222,
		.c = 0x33333333,
	};

	printf("sizeof(d) = %zu\n", sizeof(d));
	print_bytes(&d, sizeof(d));

	printf("sizeof(m1) = %zu\n", sizeof(m1));
	print_bytes(&m1, sizeof(m1));

	printf("sizeof(m2) = %zu\n", sizeof(m2));
	print_bytes(&m2, sizeof(m2));
	return 0;
}
