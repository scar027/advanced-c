#include <stdio.h>

struct struct1 {
	int a;
	int b;
};

/* constexpr available since C23 */
constexpr struct struct1 f = { .a = 1, .b = 2 };

constexpr size_t len = 10;
constexpr int a[len] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
constexpr char s[] = "hello world";

int main(int argc, char **argv)
{
	size_t i;

	printf("Array(constexpr): \n");
	for (i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");

	printf("Struct(constexpr): \n");
	printf("a = %d, b = %d\n", f.a, f.b);

	/* For strings only char array works, string literals don't */
	printf("String(constexpr): \n");
	printf("%s\n", s);
	return 0;
}
